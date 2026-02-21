#include <iostream>
#include <queue>
#include <vector>
#define int long long

using namespace std;

const int UNSEEN = -1;

vector<pair<int, int>> adj[100'001];

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int v;
    cin >> v;

    for (int i = 0; i < v; i++) {
        int x;
        cin >> x;

        while (true) {
            // cout << "i: " << i << "\n";
            int y;
            cin >> y;

            if (y == -1) break;

            int z;
            cin >> z;

            adj[x].push_back({z, y});
        }
    }

    priority_queue<pair<int, int>> PQ;

    vector<int> dist(v + 1, UNSEEN);
    vector<bool> visited(v + 1, false);
    int ans = 0;

    for (int i = 1; i <= v; i++) {
        // cout << "HI\n";
        dist.assign(v + 1, UNSEEN);
        visited.assign(v+1, false);

        dist[i] = 0;
        PQ.push({0, i});

        while (!PQ.empty()) {
            pair<int, int> top_node = PQ.top();
            PQ.pop();
            
            if (visited[top_node.second]) continue;
            if (dist[top_node.second] != top_node.first) continue;
            
            visited[top_node.second] = true;

            for (pair<int, int> fringe: adj[top_node.second]) {
                if (visited[fringe.second]) continue;
                if (dist[fringe.second] < fringe.first + dist[top_node.second]) {
                    dist[fringe.second] = fringe.first + dist[top_node.second];
                    ans = max(ans, dist[fringe.second]);
                    PQ.push({dist[fringe.second], fringe.second});
                }
            }
            // cout << "HI\n";
        }
        // cout << "HI2\n";
    }
    cout << ans;

}