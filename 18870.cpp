#include <iostream>
#include <set>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  vector<int> V;
  multiset<int> MS;
  unordered_map<int, int> UM;

  int N;
  cin >> N;

  for (int i = 0; i < N; i++) {
    int x;
    cin >> x;
    V.push_back(x);
    MS.insert(x);
  }

  int i = 0;
  for (auto& ele : MS) {
    if (UM.find(ele) == UM.end()) {
      UM.insert({ele, i++});
    }
  }

  for (i = 0; i < N; i++) {
    cout << UM[V[i]] << " ";
  }

}