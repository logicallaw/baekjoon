// 60 ms
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <chrono>

using namespace std;

const int MOD = 10000;

int D(int num) {
  num = (num * 2) % MOD;
  return num;
}

int S(int num) {
  num--;
  if (num == -1) {
    num = 9999;
  }
  return num;
}

int L(int num) {
  int m1 = (num % 1000) * 10;
  int m2 = (num / 1000);
  return m1 + m2;
}

int R(int num) {
  int m1 = num / 10;
  int m2 = num % 10;
  return m2 * 1000 + m1;
}

using namespace std;

int main() {
  int T;
  cin >> T;
  auto start = chrono::high_resolution_clock::now();
  while (T--) {
    int A, B;
    cin >> A >> B;

    vector<int> parent(10001, 0);
    vector<char> saved(10001);
    vector<bool> visited(10001, false);

    queue<int> Q;
    Q.push(A);
    parent[A] = -1;
    visited[A] = true;

    while (!Q.empty()) {
      int F = Q.front();
      Q.pop();

      if (F == B) {
        int cur = F;
        string result;
        while (parent[cur] != -1) {
          result += saved[cur];
          cur = parent[cur];
        }
        reverse(result.begin(), result.end());
        cout << result << "\n";
        break;
      }

      int d = D(F);
      int s = S(F);
      int l = L(F);
      int r = R(F);

      // cout << d << " " << s << " " << l << " " << r << "\n";

      if (!visited[d]) {
        Q.push(d);
        parent[d] = F;
        saved[d] = 'D';
        visited[d] = true;
      }
      if (!visited[s]) {
        Q.push(s);
        parent[s] = F;
        saved[s] = 'S';
        visited[s] = true;
      }
      if (!visited[l]) {
        Q.push(l);
        parent[l] = F;
        saved[l] = 'L';
        visited[l] = true;
      }
      if (!visited[r]) {
        Q.push(r);
        parent[r] = F;
        saved[r] = 'R';
        visited[r] = true;
      }
    }
  }
  auto end = chrono::high_resolution_clock::now();
  chrono::duration<double, milli> elapsed = end - start;
  cout << elapsed.count() << " ms\n";
 }