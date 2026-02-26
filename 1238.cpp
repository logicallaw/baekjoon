#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int UNSEEN = 0x7fffffff;

vector<pair<int, int>> adj[1001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, M, X;
    cin >> N >> M >> X;

    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        adj[a].push_back({c, b});
    }

    vector<int> result[N + 1];
    for (int i = 1; i <= N; i++) {
        vector<bool> visited(N + 1, false);
        vector<int> dist(N + 1, UNSEEN);

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;

        dist[i] = 0;
        Q.push({0, i});

        while (!Q.empty()) {
            pair<int, int> top_node = Q.top();
            Q.pop();

            if (visited[top_node.second]) continue;
            if (dist[top_node.second] != top_node.first) continue;

            visited[top_node.second] = true;

            for (pair<int, int> fringe : adj[top_node.second]) {
                if (visited[fringe.second]) continue;
                if (dist[fringe.second] > dist[top_node.second] + fringe.first) {
                    dist[fringe.second] = dist[top_node.second] + fringe.first;
                    Q.push({dist[fringe.second], fringe.second});
                }
            }
        }
            // cout << i << "\n";
            // for (int i = 1; i <= N; i++) {
            //     cout << dist[i] << " ";
            // }
            // cout << "\n";
        for (int j = 1; j <= N; j++) {
            result[i].push_back(dist[j]);
        }
    }

    int ans_dist = 0;
    for (int i = 1; i <= N; i++) {
        ans_dist = max(ans_dist, result[i][X-1] + result[X][i-1]);
        // cout << i << " " << ans_dist << "\n";
    }

    // for (auto ele : result) {
    //     for (auto el : ele) {
    //         cout << el << " ";
    //     }
    //     cout << "\n";
    // }
    cout << ans_dist;
}