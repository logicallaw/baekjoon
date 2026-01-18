#include <iostream>
#include <queue>
#include <climits>

using namespace std;

int N, K;

bool isRange(int x) {
    return (0 <= x && x < 100001);
}

bool visited[100001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> K;

    queue<pair<int, int>> Q;

    Q.push({N, 0});

    int ans = INT_MAX - 1;

    while (!Q.empty()) {
        pair<int, int> F = Q.front();
        Q.pop();
        visited[F.first] = true;

        if (F.first == K) {
            ans = min(ans, F.second);
        }

        int a = F.first - 1;
        int b = F.first + 1;
        int c = F.first * 2;
        int time = F.second + 1;

        if (isRange(a) && !visited[a]) {
            Q.push({a, time});
        }

        if (isRange(b) && !visited[b]) {
            Q.push({b, time});
        }

        if (isRange(c) && !visited[c]) {
            Q.push({c, time});
        }
    }
    cout << ans;
}