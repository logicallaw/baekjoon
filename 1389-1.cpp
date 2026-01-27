#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int UNSEEN = 0x7fffffff;

vector<pair<int, int>> adj[101];
vector<bool> visited;
vector<int> dist;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int N, M;
  cin >> N >> M;

  for (int i = 0; i < M; i++) {
    int x, y;
    cin >> x >> y;

    adj[x].push_back({1, y});
    adj[y].push_back({1, x});
  }

  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> result;

  for (int i = 1; i <= N; i++) {
    visited.assign(N + 1, false);
    dist.assign(N+1, UNSEEN);

    // cout << "HI\n";

    dist[i] = 0;
    Q.push({0, i});

    while (!Q.empty()) {
      pair<int, int> top_v = Q.top();
      Q.pop();
      if (visited[top_v.second]) continue;
      if (dist[top_v.second] != top_v.first) continue;
      visited[top_v.second] = true;

      for (auto& fringe : adj[top_v.second]) {
        if (visited[fringe.second]) continue;
        if (dist[fringe.second] > top_v.first + fringe.first) {
          dist[fringe.second] = top_v.first + fringe.first;
          Q.push({dist[fringe.second], fringe.second});
          // cout << dist[fringe.second] << "," << fringe.second << "\n";
        }
      }
    }

    int total = 0;
    for (int i = 1; i <= N; i++) {
      total += dist[i];
    }
    result.push({total, i});
    // cout << total << " " << i << "\n";
  }
  cout << result.top().second;
}