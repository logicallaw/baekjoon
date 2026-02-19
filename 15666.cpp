#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int N, M;
vector<int> V;
set<string> cache;

void dfs(string str, int last_idx, int cnt) {
    if (cnt == M) {
        if (cache.find(str) != cache.end()) {
            // cout << str << "==\n";
            return;
        }
        cout << str << "\n";
        cache.insert(str);
        return;
    }

    for (int nxt = last_idx; nxt < N; nxt++) {
        dfs(str + " " + to_string(V[nxt]), nxt, cnt + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        V.push_back(x);
    }

    sort(V.begin(), V.end());

    for (int st = 0; st < N; st++) {
        dfs(to_string(V[st]), st, 1);
    }
}