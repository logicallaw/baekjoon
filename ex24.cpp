#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip> // 출력 정렬용

using namespace std;

// =========================================================
// [1] 데이터 구조 정의 (Schema)
// =========================================================

// 실제 테이블에 저장되는 레코드 (Row)
struct Record {
    int id;                 // Primary Key (Clustered Index의 기준)
    int userId;             // Secondary Index의 기준
    string activityType;
    string activityDate;    // 검색 조건 (Filtering)
    string memo;

    void print() {
        cout << "      [DATA FOUND] ID:" << id << " | User:" << userId
             << " | Date:" << activityDate << " | " << memo << endl;
    }
};

// =========================================================
// [2] Tree A: 클러스터드 인덱스 (데이터 본체)
// =========================================================

// 본체 데이터가 저장되는 리프 노드 (Data Page)
struct ClusteredNode {
    // PK(id) 순서대로 정렬된 진짜 데이터들
    vector<Record> records;
    ClusteredNode* next = nullptr; // 다음 페이지 연결

    // PK로 레코드 찾기 (Binary Search)
    Record* findById(int pk) {
        for (auto& rec : records) {
            if (rec.id == pk) return &rec;
        }
        return nullptr;
    }
};

class ClusteredIndexTree {
public:
    ClusteredNode* rootPage;

    ClusteredIndexTree() {
        rootPage = new ClusteredNode();
    }

    // 데이터 삽입 (항상 PK 순서 유지하며 저장)
    void insert(Record rec) {
        rootPage->records.push_back(rec);
        // 간략화: 매번 정렬하여 B+ Tree의 정렬 상태 유지 시뮬레이션
        sort(rootPage->records.begin(), rootPage->records.end(),
             [](const Record& a, const Record& b) { return a.id < b.id; });
    }

    // PK로 데이터 페이지 찾기 (O(log N) 시뮬레이션)
    ClusteredNode* searchPage(int pk) {
        // 실제로는 트리 타고 내려가지만, 여기선 rootPage가 리프라고 가정
        return rootPage;
    }
};

// =========================================================
// [3] Tree B: 보조 인덱스 (userId 인덱스)
// =========================================================

// 인덱스 엔트리 (Key: userId, Value: PK)
struct IndexEntry {
    int userId;
    int pk; // <-- 여기가 핵심! 진짜 데이터 포인터가 아니라 'PK'를 가짐
};

// 보조 인덱스 리프 노드 (Index Page)
struct SecondaryNode {
    // userId 순서대로 정렬된 (userId, pk) 쌍들
    // -> "논리적 인접성"이 여기서 구현됨 (vector 내부에 붙어있음)
    vector<IndexEntry> entries;
    SecondaryNode* next = nullptr;
};

class SecondaryIndexTree {
public:
    SecondaryNode* rootPage;

    SecondaryIndexTree() {
        rootPage = new SecondaryNode();
    }

    // 인덱스 등록 (userId 순서 유지)
    void insert(int userId, int pk) {
        rootPage->entries.push_back({userId, pk});
        // userId 순으로 정렬. userId 같으면 PK 순으로 정렬
        sort(rootPage->entries.begin(), rootPage->entries.end(),
             [](const IndexEntry& a, const IndexEntry& b) {
                 if (a.userId != b.userId) return a.userId < b.userId;
                 return a.pk < a.pk;
             });
    }

    // userId로 인덱스 페이지 찾기
    SecondaryNode* searchPage(int userId) {
        return rootPage;
    }
};

// =========================================================
// [4] DB 엔진 (쿼리 실행기)
// =========================================================
class DatabaseEngine {
    ClusteredIndexTree* tableData;  // 본체
    SecondaryIndexTree* userIndex;  // 목차

public:
    DatabaseEngine() {
        tableData = new ClusteredIndexTree();
        userIndex = new SecondaryIndexTree();
    }

    // 데이터 적재 (Insert 시 두 트리 모두에 기록됨)
    void insertData(int id, int userId, string type, string date, string memo) {
        // 1. 본체(Clustered)에 저장
        tableData->insert({id, userId, type, date, memo});
        // 2. 목차(Secondary)에 (userId, id) 등록
        userIndex->insert(userId, id);
    }

    // ⭐️ 핵심 로직: SELECT * FROM table WHERE userId=123 AND date='...'
    void executeQuery(int targetUserId, string targetDate) {
        cout << "\n=== [Query Start] User: " << targetUserId << ", Date: " << targetDate << " ===\n";

        // STEP 1. 보조 인덱스 탐색 (Seek)
        cout << "1. [Secondary Index] 탐색 시작 (Tree B)\n";
        SecondaryNode* idxNode = userIndex->searchPage(targetUserId);

        // STEP 2. 보조 인덱스 스캔 (Scan)
        // -> userId가 123인 엔트리들을 찾아서 PK를 수집
        vector<int> foundPKs;
        for (const auto& entry : idxNode->entries) {
            if (entry.userId == targetUserId) {
                cout << "   -> [Index Scan] userId 123 발견! (매핑된 PK: " << entry.pk << ")\n";
                foundPKs.push_back(entry.pk);
            }
        }
        cout << "   -> 총 " << foundPKs.size() << "개의 후보 PK 확보 완료.\n\n";

        // STEP 3. 랜덤 I/O 발생 (Lookup)
        cout << "2. [Clustered Index] 본체 데이터 조회 (Tree A)\n";

        for (int pk : foundPKs) {
            cout << "   -> [Lookup] PK " << pk << "번 데이터를 가지러 본체로 점프!\n";

            // 3-1. PK로 본체 페이지 찾기
            ClusteredNode* dataNode = tableData->searchPage(pk);

            // 3-2. 페이지 내에서 실제 데이터 가져오기
            Record* realData = dataNode->findById(pk);

            // 3-3. 나머지 조건(activityDate) 필터링 (DB 엔진이 수행)
            if (realData->activityDate == targetDate) {
                realData->print(); // 정답!
            } else {
                cout << "      [FILTER OUT] 날짜 불일치 (" << realData->activityDate << ")\n";
            }
        }
        cout << "=== [Query End] ===\n";
    }
};

// =========================================================
// [5] 메인 실행
// =========================================================
int main() {
    DatabaseEngine db;

    // 데이터 적재 (순서는 뒤죽박죽 들어온다고 가정)
    // ID(PK)는 고유함
    db.insertData(1, 100, "Login", "2024-01-01", "다른 유저");
    db.insertData(5, 123, "Write", "2024-05-05", "철수의 5월 글");  // PK 5
    db.insertData(9, 123, "Login", "2024-07-31", "철수의 7월 접속"); // PK 9 (Target)
    db.insertData(2, 200, "Out",   "2024-02-02", "영희");
    db.insertData(3, 123, "View",  "2024-07-31", "철수의 7월 조회"); // PK 3 (Target)

    /* [DB 내부 저장 상태]

       Tree A (Clustered): PK순 정렬
       [ID:1] -> [ID:2] -> [ID:3] -> [ID:5] -> [ID:9] ...

       Tree B (Secondary): userId순 정렬
       [100, PK:1] -> [123, PK:3] -> [123, PK:5] -> [123, PK:9] -> [200, PK:2]
                                      (논리적 인접성 O)
    */

    // 쿼리 실행
    db.executeQuery(123, "2024-07-31");

    return 0;
}