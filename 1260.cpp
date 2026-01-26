#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

enum Status { unseen, visit, back };

vector<int> adj[1001];
vector<Status> visited;

void dfs(int x) {
  visited[x] = visit;
  cout << x << " ";

  sort(adj[x].begin(), adj[x].end());
  for (auto& ele : adj[x]) {
    if (visited[ele] == back || visited[ele] == visit) continue;
    dfs(ele);
  }

  visited[x] = back;
}

void bfs(int x) {
  queue<int> Q;
  Q.push(x);
  visited[x] = visit;

  while (!Q.empty()) {
    int FRONT = Q.front();
    Q.pop();
    cout << FRONT << " ";

    sort(adj[FRONT].begin(), adj[FRONT].end());

    for (auto& ele : adj[FRONT]) {
      if (visited[ele] == back || visited[ele] == visit) continue;
      Q.push(ele);
      visited[ele] = visit;
    }
    visited[FRONT] = back;
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int N, M, V;
  cin >> N >> M >> V;

  visited.assign(1001, unseen);

  for (int i = 0; i < M; i++) {
    int x, y;
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }

  dfs(V);
  cout << "\n";
  visited.assign(1001, unseen);
  bfs(V);
}