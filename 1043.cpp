#include <iostream>
#include <set>
#include <map>
#include <vector>
using namespace std;

vector<int> adj[51];
vector<int> arr[51];

set<int> truth;
bool visited[51];

void dfs(int x) {
    truth.insert(x);
    visited[x] = true;

    for (auto a : adj[x]) {
        if (visited[a]) continue;
        dfs(a);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, M;
    cin >> N >> M;

    int x;
    cin >> x;

    int st;
    
    if (x == 0) {
        st = 0;
    } else {
        int y;
        cin >> y;
        st = y;

        for (int i = 1; i < x; i++) {
            cin >> y;
            adj[st].push_back(y);
        }
    }

    for (int i = 0; i < M; i++) {
        int a;
        cin >> a;

        if (a == 1) {
            int b;
            cin >> b;
            arr[i].push_back(b);
        } else {
            int prev;
            cin >> prev;
            arr[i].push_back(prev);

            for (int j = 1; j < a; j++) {
                int cur;
                cin >> cur;
                arr[i].push_back(cur);
                adj[prev].push_back(cur);
                adj[cur].push_back(prev);
                prev = cur;
            }
        }
    }

    dfs(st);
    // cout << "\n";

    // for (auto t : truth) {
    //     cout << t << " ";
    // }
    // cout << "\n";

    int ans = 0;
    for (int i = 0; i < M; i++) {
        bool pass = true;
        for (auto a : arr[i]) {
            if (truth.find(a) != truth.end()) {
                pass = false;
                break;
            }
        }
        if (pass) ans++;
    }
    cout << ans;
}