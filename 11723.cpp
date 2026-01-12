#include <iostream>
#include <set>

using namespace std;

int main() {
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 cout.tie(0);

 int N;
 cin >> N;

 set<int> S;

 while (N--) {
  string C;
  cin >> C;

  if (C == "add") {
   int val;
   cin >> val;
   S.insert(val);
   continue;
  }

  if (C == "remove") {
   int val;
   cin >> val;
   if (S.find(val) != S.end()) {
    S.erase(val);
   }
   continue;
  }

  if (C == "check") {
   int val;
   cin >> val;
   if (S.find(val) != S.end()) {
    cout << "1\n";
   } else {
    cout << "0\n";
   }
   continue;
  }

  if (C == "toggle") {
   int val;
   cin >> val;
   if (S.find(val) != S.end()) {
    S.erase(val);
   } else {
    S.insert(val);
   }
   continue;
  }

  if (C == "all") {
   S = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
   continue;
  }

  S = {};
 }
}