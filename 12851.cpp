#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, K;
    cin >> N >> K;

    queue<pair<int, int>> Q;
    vector<bool> visited(100'001, false);

    Q.push({0, N});

    int cnt = 1;
    int ans = 0x7fffffff;
    while (!Q.empty()) {
        pair<int, int> F = Q.front();
        Q.pop();

        if (F.second > 100'000) continue;
        if (F.first > ans) continue;

        if (F.second == K) {
            if (ans > F.first) {
                ans = F.first;
            } else if (ans == F.first) {
                cnt++;
            }
            continue;
        }
        
        if (!visited[F.second - 1]) {
            visited[F.second - 1] = true;
            Q.push({F.first + 1, F.second - 1});
        }
        if (!visited[F.second + 1]) {
            visited[F.second + 1] = true;
            Q.push({F.first + 1, F.second + 1});
        }
        if (!visited[F.second * 2]) {
            visited[F.second * 2] = true;
            Q.push({F.first + 1, F.second * 2});
        }
    }
    cout << ans << "\n" << cnt;
}