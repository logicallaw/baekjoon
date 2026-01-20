#include <iostream>
#include <vector>

using namespace std;

enum Status {
 unseen, back, visited
};

vector<int> adj[1002];

vector<Status> V;

void dfs(int n) {
 V[n] = visited;

 for (auto& nei : adj[n]) {
  if (V[nei] == back) continue;
  if (V[nei] == visited) continue;
  dfs(nei);
 }

 V[n] = back;
}

int main() {
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 cout.tie(0);

 int N, M;
 cin >> N >> M;

 V.assign(1001, unseen);

 for (int i = 0; i < M; i++) {
  int u, v;
  cin >> u >> v;
  adj[u].push_back(v);
  adj[v].push_back(u);
 }

 int cnt = 0;
 for (int i = 1; i <= N; i++) {
  if (V[i] == back) {
    continue;
  }
  dfs(i);
  cnt++;
 }

 cout << cnt;
}