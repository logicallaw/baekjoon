#include <iostream>

using namespace std;

int N, M;
int arr[501][501];

bool isRange(int x, int y) {
  return (0 <= x && x < N) && (0 <= y && y < M);
}

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

int dfs(int x, int y, int bx, int by, int cnt, int prefixSum) {
  if (cnt == 4) {
    return prefixSum;
  }

  int tmp = 0;
  for (int i = 0; i < 4; i++) {
    int nx = x + dx[i];
    int ny = y + dy[i];

    if (nx == bx && ny == by) continue;
    if (!isRange(nx, ny)) continue;
    tmp = max(tmp, dfs(nx, ny, x, y, cnt + 1, prefixSum + arr[nx][ny]));
  }
  return tmp;
}

int result = 0;

int main() {
  cin >> N >> M;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> arr[i][j];
    }
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      int total = dfs(i, j, -1, -1, 1, arr[i][j]);
      if (result < total) {
        cout << i << "," << j << "=\n";
      }
      result = max(result, total);
    }
  }
  cout << result;
}