#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int arr[1001][1001];
bool visited[1001][1001];

int M, N;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

bool isRange(int x, int y) {
    // cout << "x: " << x << ",y: " << y << "\n";
    if (x >= 0 && x < N) {
        if (y >= 0 && y < M) {
            return true;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> M >> N;

    queue<tuple<int, int, int>> Q;

    int cnt = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int x;
            cin >> x;
            arr[i][j] = x;
            if (x == 1) {
                Q.emplace(i, j, 0);
                visited[i][j] = true;
            } else if (x == 0) {
                cnt++;
            }
        }
    }

    int day = 0;

    while (!Q.empty()) {
        tuple<int, int, int> F = Q.front();
        Q.pop();
        int x = std::get<0>(F);
        int y = std::get<1>(F);
        day = max(day, std::get<2>(F));

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (!isRange(nx, ny)) continue;
            if (visited[nx][ny]) continue;
            if (arr[nx][ny] == -1) continue;
            Q.emplace(nx, ny, std::get<2>(F) + 1);
            visited[nx][ny] = true;
            // cout << "Q.push: " << nx << "," << ny << "," << std::get<2>(F) + 1 << "\n";
            cnt--;
        }
    }

    if (cnt == 0) {
        cout << day;
    } else {
        cout << -1;
    }
}