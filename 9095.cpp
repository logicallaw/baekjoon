#include <iostream>
#include <queue>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int T;
  cin >> T;

  while (T--) {
    int n;
    cin >> n;

    queue<int> Q;

    int cnt = 0;

    Q.push(0);

    while (!Q.empty()) {
      int F = Q.front();
      Q.pop();
      if (F == n) {
        cnt++;
      }

      int a = F + 1;
      int b = F + 2;
      int c = F + 3;

      if (a <= n) {
        Q.push(a);
      }

      if (b <= n) {
        Q.push(b);
      }

      if (c <= n) {
       Q.push(c);
      }
    }

    cout << cnt << "\n";
  }
}