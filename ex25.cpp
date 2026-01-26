#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// =========================================================
// [1] 스키마 정의 (Schema)
// =========================================================
struct Record {
    int id;                 // PK (Clustered Index Key)
    int userId;             // Secondary Index Key
    string activityType;
    string activityDate;    // 검색 조건
    string activityDateTime;
    string memo;

    void print() const {
        cout << "      ✅ [Found Record] ID:" << id
             << " | User:" << userId
             << " | Date:" << activityDate
             << " | Type:" << activityType
             << " | Memo:" << memo << endl;
    }
};

// =========================================================
// [2] B+ Tree 노드 구조 (계층형)
// =========================================================

// 모든 노드의 부모 (추상 클래스)
struct Node {
    bool isLeaf;
    virtual ~Node() {}
};

// [내부 노드]: 이정표 역할 (Key + Child Pointer)
// 데이터는 없고, "어디로 가야 하는지" 방향만 알려줌
struct InternalNode : public Node {
    vector<int> keys;       // 기준값들 (예: 100, 200)
    vector<Node*> children; // 자식 노드들 (Key 개수 + 1)

    InternalNode() { isLeaf = false; }
};

// [클러스터드 리프 노드]: 실제 데이터(Record) 저장
struct ClusteredLeaf : public Node {
    vector<Record> records; // PK순 정렬된 데이터
    ClusteredLeaf* next = nullptr; // Linked List

    ClusteredLeaf() { isLeaf = true; }
};

// [세컨더리 리프 노드]: 인덱스(User ID -> PK) 저장
struct SecondaryLeaf : public Node {
    // <UserId, PK> 쌍 저장
    vector<pair<int, int>> entries;
    SecondaryLeaf* next = nullptr;

    SecondaryLeaf() { isLeaf = true; }
};

// =========================================================
// [3] Tree A: 클러스터드 인덱스 (PK 기준)
// =========================================================
class ClusteredIndexTree {
public:
    Node* root;

    ClusteredIndexTree() { root = nullptr; }

    // PK로 리프 노드 찾아가기 (Traversal)
    ClusteredLeaf* searchLeaf(int pk) {
        Node* curr = root;

        // 내부 노드라면 계속 타고 내려감
        while (!curr->isLeaf) {
            InternalNode* internal = static_cast<InternalNode*>(curr);

            // 어디로 내려갈지 결정 (Routing)
            int childIdx = 0;
            // Keys: [10, 20] 이라면
            // pk < 10 : child[0]
            // 10 <= pk < 20 : child[1]
            // 20 <= pk : child[2]
            while (childIdx < internal->keys.size() && pk >= internal->keys[childIdx]) {
                childIdx++;
            }
            // cout << "    ⬇️ [Internal] PK " << pk << " 찾기 위해 자식[" << childIdx << "]로 이동\n";
            curr = internal->children[childIdx];
        }

        return static_cast<ClusteredLeaf*>(curr);
    }

    // 데이터 조회 (PK -> Record)
    Record* find(int pk) {
        ClusteredLeaf* leaf = searchLeaf(pk);
        // 리프 노드 내에서 이진 탐색 (여기선 단순 순회)
        for (auto& rec : leaf->records) {
            if (rec.id == pk) return &rec;
        }
        return nullptr;
    }
};

// =========================================================
// [4] Tree B: 보조 인덱스 (UserId 기준)
// =========================================================
class SecondaryIndexTree {
public:
    Node* root;

    SecondaryIndexTree() { root = nullptr; }

    // UserId로 리프 노드 찾아가기
    SecondaryLeaf* searchLeaf(int userId) {
        Node* curr = root;

        cout << "  🔍 [Tree B] 루트에서 탐색 시작 (User: " << userId << ")\n";

        while (!curr->isLeaf) {
            InternalNode* internal = static_cast<InternalNode*>(curr);
            int childIdx = 0;

            // 간단한 라우팅 로직
            while (childIdx < internal->keys.size() && userId >= internal->keys[childIdx]) {
                childIdx++;
            }
            cout << "    ⬇️ [Internal Node] Key=" << userId << " -> 자식 노드 [" << childIdx << "]번으로 이동\n";
            curr = internal->children[childIdx];
        }

        cout << "    🏁 [Leaf Node] 도착! 스캔 준비 완료.\n";
        return static_cast<SecondaryLeaf*>(curr);
    }
};

// =========================================================
// [5] DB 엔진 (Facade)
// =========================================================
class DatabaseEngine {
    ClusteredIndexTree pkTree;
    SecondaryIndexTree userTree;

public:
    // 테스트를 위해 수동으로 '이미 구축된 트리'를 만듦 (Insert 로직 생략)
    void buildSampleData() {
        // ---------------------------------------------------
        // 1. 클러스터드 인덱스 구축 (PK 1~30)
        // 구조: Internal(Root) -> Leaf1(1~9), Leaf2(10~19), Leaf3(20~29)
        // ---------------------------------------------------
        InternalNode* pkRoot = new InternalNode();
        pkRoot->keys = {10, 20}; // 기준점

        ClusteredLeaf* pLeaf1 = new ClusteredLeaf(); // 1~9
        ClusteredLeaf* pLeaf2 = new ClusteredLeaf(); // 10~19
        ClusteredLeaf* pLeaf3 = new ClusteredLeaf(); // 20~30

        // 데이터 채워넣기 (간략화)
        pLeaf1->records.push_back({1, 100, "Login", "2024-01-01", "", "A"});
        pLeaf1->records.push_back({5, 123, "Write", "2024-05-05", "", "B"}); // PK 5

        pLeaf2->records.push_back({12, 123, "View", "2024-07-31", "", "Target1"}); // PK 12 (Target)
        pLeaf2->records.push_back({15, 200, "Login", "2024-02-02", "", "C"});

        pLeaf3->records.push_back({25, 123, "Login", "2024-07-31", "", "Target2"}); // PK 25 (Target)
        pLeaf3->records.push_back({28, 300, "Out", "2024-08-08", "", "D"});

        // 트리 연결
        pkRoot->children = {pLeaf1, pLeaf2, pLeaf3};
        pkTree.root = pkRoot;


        // ---------------------------------------------------
        // 2. 보조 인덱스 구축 (UserId 기준)
        // 구조: Internal(Root) -> Leaf1(User ~100), Leaf2(User 101~200), Leaf3(User 201~)
        // ---------------------------------------------------
        InternalNode* idxRoot = new InternalNode();
        idxRoot->keys = {101, 201}; // userId 기준점

        SecondaryLeaf* sLeaf1 = new SecondaryLeaf(); // User 0~100
        SecondaryLeaf* sLeaf2 = new SecondaryLeaf(); // User 101~200 (여기에 123 존재)
        SecondaryLeaf* sLeaf3 = new SecondaryLeaf(); // User 201~

        // 인덱스 데이터 (UserId, PK)
        sLeaf1->entries.push_back({100, 1});

        // User 123 데이터들이 모여있는 곳 (논리적 인접성)
        sLeaf2->entries.push_back({123, 5});
        sLeaf2->entries.push_back({123, 12}); // PK 12
        sLeaf2->entries.push_back({123, 25}); // PK 25
        sLeaf2->entries.push_back({200, 15});

        sLeaf3->entries.push_back({300, 28});

        // 트리 연결
        idxRoot->children = {sLeaf1, sLeaf2, sLeaf3};
        userTree.root = idxRoot;
    }

    // ⭐️ 쿼리 실행: SELECT * FROM activityLog WHERE userId=123 AND activityDate='2024-07-31'
    void executeQuery(int targetUser, string targetDate) {
        cout << "========================================================\n";
        cout << "Query: SELECT * FROM table WHERE userId=" << targetUser << " AND date='" << targetDate << "'\n";
        cout << "========================================================\n\n";

        // STEP 1. 보조 인덱스 탐색 (Tree Traversal)
        SecondaryLeaf* idxNode = userTree.searchLeaf(targetUser);

        // STEP 2. 인덱스 스캔 (Scan)
        vector<int> candidatePKs;
        cout << "  👁️ [Index Scan] Leaf Node 내부 스캔 중...\n";
        for (auto& entry : idxNode->entries) {
            if (entry.first == targetUser) {
                cout << "    -> User " << targetUser << " 발견! (PK: " << entry.second << " 획득)\n";
                candidatePKs.push_back(entry.second);
            }
        }
        cout << "  ✅ 총 " << candidatePKs.size() << "개의 PK 후보 찾음.\n\n";

        // STEP 3. 랜덤 룩업 (Random Lookup to Clustered Index)
        cout << "  🚀 [Lookup] 실제 데이터 조회 시작 (Tree A로 점프)\n";
        for (int pk : candidatePKs) {
            // 본체 트리(Clustered)를 다시 탐색
            Record* rec = pkTree.find(pk);

            if (rec) {
                // 필터링 (Date 비교)
                if (rec->activityDate == targetDate) {
                    rec->print();
                } else {
                    cout << "      ❌ [Filter Out] PK " << pk << ": 날짜 불일치 (" << rec->activityDate << ")\n";
                }
            }
        }
    }
};

int main() {
    DatabaseEngine db;

    // 복잡한 Split 알고리즘 대신, 구조 이해를 위해 샘플 트리 구축
    db.buildSampleData();

    // 쿼리 실행
    db.executeQuery(123, "2024-07-31");

    return 0;
}