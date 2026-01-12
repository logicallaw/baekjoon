#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> adj[101];
vector<bool> visited;

bool pass;

void dfs(int x, int y) {
    if (visited[x]) {
        return;
    }

    visited[x] = true;

    for (auto& ele : adj[x]) {
        if (ele == y) {
            pass = true;
            return;
        }
        if (!visited[ele]) {
            dfs(ele, y);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;


    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            int x;
            cin >> x;
            if (x == 1) {
                adj[i].push_back(j);
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            visited.assign(N + 1, false);
            pass = false;

            dfs(i, j);
            if (pass) cout << 1 << " ";
            else cout << 0 << " ";

        }
        cout << "\n";
    }
}