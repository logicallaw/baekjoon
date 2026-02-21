#include <iostream>
#include <vector>
#define int long long

using namespace std;


vector<pair<int, int>> adj[100'001];
vector<bool> visited;
vector<int> leafs;

void dfs(int x) {
    visited[x] = true;

    if (adj[x].size() == 1) {
        leafs.push_back(x);
    }

    for (pair<int, int> ele : adj[x]) {
        if (visited[ele.second]) continue;
        dfs(ele.second);
    }
}

int result = 0;

void sol(int x, int accum, int st) {
    // cout << "x: " << x << "\n";
    visited[x] = true;

    // if (adj[x].size() == 1) {
    //     cout << "size=1, x: " << x << "\n";
    // }

    if (adj[x].size() == 1 && x != st) {
        // cout << "x: " << x << ", accum: " << accum << "\n";
        result = max(result, accum);
        return;
    }

    for (pair<int, int> ele : adj[x]) {
        // cout << "x: " << x << ", ele: " << ele.second << "\n"; 
        // cout << boolalpha << visited[ele.second] << "\n";
    
        // cout << "GO!" << "\n";
        if (visited[ele.second]) continue;
        sol(ele.second, accum + ele.first, st);
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int v;
    cin >> v;

    visited.assign(v + 1, false);

    for (int i = 0; i < v; i++) {
        int x;
        cin >> x;

        while (true) {
            int y;
            cin >> y;

            if (y == -1) break;

            int z;
            cin >> z;

            adj[x].push_back({z, y});
        }
    }

    dfs(1);
    // for (int i = 1; i <= v; i++) {
    //     for (auto ele : adj[i]) {
    //         cout << ele.second << " ";
    //     }
    //     cout << "\n";
    // }

    for (auto l : leafs) {
        visited.assign(v + 1, false);
        // cout << l << " ";
        sol(l, 0, l);
        // cout << result << "\n";
    }
    cout << result;    
}