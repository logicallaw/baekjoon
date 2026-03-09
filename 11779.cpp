#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int UNSEEN = 0x7fffffff;

vector<pair<int, int>> adj[1001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, M;
    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int st, end, cost;
        cin >> st >> end >> cost;
        adj[st].push_back({cost, end});
    }

    int A, B;
    cin >> A >> B;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> PQ;

    vector<int> dist(N + 1, UNSEEN);
    vector<bool> visited(N + 1, false);
    vector<int> path(N + 1, 0);

    dist[A] = 0;
    path[A] = -1;

    PQ.push({0, A});

    while (!PQ.empty()) {
        pair<int, int> top_node = PQ.top();
        PQ.pop();

        if (dist[top_node.second] != top_node.first) continue;
        if (visited[top_node.second]) continue;

        visited[top_node.second] = true;
        // cout << "HI: " << top_node.second << "\n";

        for (pair<int, int> fringe : adj[top_node.second]) {
            if (visited[fringe.second]) continue;
            if (dist[fringe.second] > dist[top_node.second] + fringe.first) {
                // cout << "===begin==" << "\n";
                // cout << dist[fringe.second] << " > " << dist[top_node.second] + fringe.first << "\n";

                dist[fringe.second] = dist[top_node.second] + fringe.first;
                PQ.push({dist[fringe.second], fringe.second});
                // cout << "path[" << fringe.second << "]" << " = ";

                path[fringe.second] = top_node.second;

                // cout << top_node.second << "\n";
                
                // cout << "===end==" << "\n";
            }
        }
    }

    // for (auto p : path) {
    //     cout << p << " ";
    // }

    cout << dist[B] << "\n";

    vector<int> ans;
    int idx = B;
    while (idx != -1) {
        ans.push_back(idx);
        idx = path[idx];
    }
    reverse(ans.begin(), ans.end());
    cout << ans.size() << "\n";
    for (auto a : ans) {
        cout << a << " ";
    }
}