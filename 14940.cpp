#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int arr[1001][1001];
int ans[1001][1001];

int N, M;

bool isRange(int x, int y) {
  return (0 <= x && x < N) && (0 <= y && y < M);
}

int dx[4] = {1, -1, 0, 0,};
int dy[4] = {0, 0, 1, -1};

// const int INF = 1e9+10;
const int INF = 0x3f3f3f3f;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> N >> M;

  int st = 0, ed = 0;
  for (int i = 0; i < N; i++) {
    memset(ans[i], 0x3f, sizeof(ans[i]));

    for (int j = 0; j < M; j++) {
      int x;
      cin >> x;
      arr[i][j] = x;
      // ans[i][j] = INF;

      // 시작점
      if (x == 2) {
        st = i;
        ed = j;
      }
    }
  }

  // for (int i = 0; i < N; i++) {
  //   for (int j = 0; j < M; j++) {
  //       cout << ans[i][j] << " ";
  //   }
  //   cout << "\n";
  // }

  queue<pair<int, int>> Q;
  Q.emplace(st, ed);
  ans[st][ed] = 0;

  while (!Q.empty()) {
    pair<int, int> F = Q.front();
    Q.pop();

    int x = F.first;
    int y = F.second;

    for (int i = 0; i < 4; i++) {
      int nx = dx[i] + x;
      int ny = dy[i] + y;

      if (!isRange(nx, ny)) continue;
      if (arr[nx][ny] == -1 || arr[nx][ny] == 0) continue;

      if (ans[nx][ny] > ans[x][y] + 1) {
        ans[nx][ny] = ans[x][y] + 1;
        Q.emplace(nx, ny);
      }
    }
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (ans[i][j] == INF) {
        if (arr[i][j] == 0) {
          cout << 0 << " ";
        } else {
          cout << -1 << " ";
        }
      } else {
        cout << ans[i][j] << " ";
      }
    }
    cout << "\n";
  }
}