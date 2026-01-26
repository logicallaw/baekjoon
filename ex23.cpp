#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// [1] 실제 데이터 (Table Record)
// 디스크의 Data Page에 저장되는 원본 데이터입니다.
struct Record {
    int id;                 // PK
    int userId;             // 인덱스 대상
    string activityType;
    string activityDate;    // 검색 조건 대상
    string memo;

    // 편의상 출력용 함수
    void print() {
        cout << "   -> [FOUND] ID: " << id << ", User: " << userId
             << ", Date: " << activityDate << ", Type: " << activityType << endl;
    }
};

// ---------------------------------------------------------
// [2] B+ Tree 구조 정의
// ---------------------------------------------------------

// B+ Tree 노드의 기본 부모 클래스
struct Node {
    bool isLeaf;
    virtual ~Node() {}
};

// [Leaf Node]: 실제 데이터(Record)의 위치를 가리키는 '인덱스 엔트리'들이 저장됨
struct LeafNode : public Node {
    // (Key: userId, Value: Record 포인터)의 쌍을 저장하는 배열
    // 실제 DB에서는 이 배열이 꽉 차면 옆 노드로 넘어감
    vector<pair<int, Record*>> entries;

    LeafNode* next = nullptr; // 다음 리프 노드를 가리키는 포인터 (Linked List)

    LeafNode() { isLeaf = true; }
};

// [Internal Node]: 리프 노드까지 찾아가기 위한 이정표 역할 (Key만 저장)
struct InternalNode : public Node {
    vector<int> keys;       // 기준이 되는 userId들
    vector<Node*> children; // 자식 노드 포인터들

    InternalNode() { isLeaf = false; }
};

// ---------------------------------------------------------
// [3] B+ Tree 클래스 (매니저 역할)
// ---------------------------------------------------------
class BPlusTreeIndex {
public:
    Node* root;

    BPlusTreeIndex() {
        root = new LeafNode(); // 처음엔 빈 리프 노드 하나로 시작
    }

    // (설명 편의상) 간단한 검색 함수 구현
    // 목표: userId = 123 AND activityDate = '2024-07-31'
    void search(int targetUserId, string targetDate) {
        cout << "[Search Start] 찾는 조건: User=" << targetUserId << ", Date=" << targetDate << endl;

        // 1단계: 탐색 (Seek) - 트리를 타고 리프 노드까지 내려감 (O(log N))
        Node* current = root;
        while (!current->isLeaf) {
            InternalNode* internal = static_cast<InternalNode*>(current);

            // 어떤 자식으로 내려갈지 결정 (이진 탐색 등 사용 가능)
            // 여기서는 단순하게 구현
            int childIndex = 0;
            while (childIndex < internal->keys.size() && targetUserId >= internal->keys[childIndex]) {
                childIndex++;
            }
            current = internal->children[childIndex];
            cout << "  -> [Internal Node] 자식 노드로 이동..." << endl;
        }

        // 2단계: 리프 노드 도착
        LeafNode* leaf = static_cast<LeafNode*>(current);
        cout << "  -> [Leaf Node] 도착! 여기서부터 스캔 시작." << endl;

        // 3단계: 스캔 (Scan) - userId가 123인 구간 찾기 + 날짜 비교
        bool foundAny = false;

        // (1) 해당 리프 노드 내에서 userId 탐색 (Lower Bound)
        for (const auto& entry : leaf->entries) {
            int currentUserId = entry.first;
            Record* record = entry.second;

            // userId가 작으면 패스
            if (currentUserId < targetUserId) continue;

            // userId가 더 커져버리면 중단 (인덱스가 정렬되어 있으므로)
            if (currentUserId > targetUserId) {
                cout << "  -> [Stop] userId가 " << currentUserId << "로 바뀌어 탐색 종료." << endl;
                break;
            }

            // userId가 일치하는 경우! (userId == 123)
            // 여기서 인덱스에는 없는 'activityDate'를 확인하기 위해 원본 레코드를 확인 (Random Access)
            cout << "  -> [Check] userId 일치(123). 날짜 확인 중... (" << record->activityDate << ")";

            if (record->activityDate == targetDate) {
                cout << " => 일치함! O";
                record->print(); // 결과 출력
                foundAny = true;
            } else {
                cout << " => 불일치 X" << endl;
            }
        }

        // 실제로는 여기서 leaf->next를 타고 다음 노드도 확인해야 하지만 프로토타입이라 생략
    }
};

// ---------------------------------------------------------
// [4] 메인 함수 (실행 시나리오)
// ---------------------------------------------------------
int main() {
    // 1. 가상의 테이블 데이터 생성 (DB 파일 역할)
    Record r1 = {1, 100, "Login", "2024-01-01", ""};
    Record r2 = {2, 123, "Post",  "2024-05-05", "첫 글"};
    Record r3 = {3, 123, "Reply", "2024-06-01", "댓글"};
    Record r4 = {4, 123, "Login", "2024-07-31", "오전 로그인"}; // Target 1
    Record r5 = {5, 123, "View",  "2024-07-31", "글 조회"};     // Target 2
    Record r6 = {6, 123, "Out",   "2024-08-15", "로그아웃"};
    Record r7 = {7, 200, "Login", "2024-02-02", ""};

    // 2. 인덱스 구축 (수동으로 트리 모양을 만듦)
    BPlusTreeIndex index;

    // 설명 편의상 Root가 바로 Leaf Node인 상황으로 가정
    LeafNode* leaf = static_cast<LeafNode*>(index.root);

    // 인덱스에 데이터 등록 (정렬된 상태로 들어감)
    leaf->entries.push_back({100, &r1});
    leaf->entries.push_back({123, &r2});
    leaf->entries.push_back({123, &r3});
    leaf->entries.push_back({123, &r4});
    leaf->entries.push_back({123, &r5});
    leaf->entries.push_back({123, &r6});
    leaf->entries.push_back({200, &r7});

    // 3. 검색 실행
    // 쿼리: SELECT * FROM activityLog WHERE userId=123 AND activityDate='2024-07-31'
    index.search(123, "2024-07-31");

    return 0;
}