#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int UNSEEN = 0x7fffffff;

int arr[101][101];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int N, M;
  cin >> N >> M;

  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      if (i == j) {
        arr[i][j] = 0;
      } else {
        arr[i][j] = UNSEEN;
      }
    }
  }

  for (int i = 0; i < M; i++) {
    int x, y;
    cin >> x >> y;
    arr[x][y] = arr[y][x] = 1;
  }

  for (int j = 1; j <= N; j++) {
    for (int i = 1; i <= N; i++) {
      if (i == j) continue;
      if (arr[i][j] == UNSEEN) continue;

      for (int k = 1; k <= N; k++) {
        if (j == k) continue;
        if (arr[j][k] == UNSEEN) continue;
        arr[i][k] = min(arr[i][k], arr[i][j] + arr[j][k]);
      }
    }
  }

  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;

  for (int i = 1; i <= N; i++) {
    int tmp = 0;
    for (int j = 1; j <= N; j++) {
      tmp += arr[i][j];
    }
    Q.push({tmp, i});
  }

  cout << Q.top().second;
}