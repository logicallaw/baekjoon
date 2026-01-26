#include <iostream>
#include <vector>

using namespace std;

int N, M;
int arr[501][501];

bool isRange(int x, int y) {
  return (0 <= x && x < N) && (0 <= y && y < M);
}

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

vector<pair<int, int>> VP[4] = {
  {{0,-1}, {-1,0}, {1,0}},
  {{-1,0},{0,1},{1,0}},
  {{0,-1},{0,1},{1,0}},
  {{0,-1},{0,1},{-1,0}}
};

int check(int x, int y) {
  int result = 0;

  for (int i = 0; i < 4; i++) {
    int tmp = 0;
    bool pass = true;

    for (int j = 0; j < 3; j++) {
      int nx = x + VP[i][j].first;
      int ny = y + VP[i][j].second;

      if (!isRange(nx, ny)) {
        pass = false;
        break;
      }
      tmp += arr[nx][ny];
    }

    if (pass) {
      result = max(result, tmp);
    }
  }

  return result;
}

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
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> N >> M;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> arr[i][j];
    }
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      int t1 = dfs(i, j, -1, -1, 1, arr[i][j]);
      int t2 = check(i, j) + arr[i][j];

      result = max(result, max(t1, t2));
    }
  }
  cout << result;
}