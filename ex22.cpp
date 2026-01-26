#include <iostream>
#include <vector>
using namespace std;

// 가정: activityLog 테이블에서 userId만 단일 인덱스인 경우

struct Record {
  // 데이터들 담는 변수들 있다고 생각
};

// userId에 대한 B+ Tree의 리프 노드이다.
struct UserIdLeafNode {
  int userId; // 123
  int pk; // primary key

  UserIdLeafNode* prev;
  UserIdLeafNode* next;
};

struct LeafNode {
  int pk;
  vector<Record> records;

  LeafNode* prev;
  LeafNode* next;
};

