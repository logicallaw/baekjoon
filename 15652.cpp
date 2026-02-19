#include <iostream>

using namespace std;

int N, M;

void dfs(string str, int last_idx, int cnt) {
    if (cnt == M) {
        cout << str << "\n";
        return;
    }

    for (int nxt = last_idx; nxt <= N; nxt++) {
        dfs(str + " " + to_string(nxt), nxt, cnt + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    for (int st = 1; st <= N; st++) {
        dfs(to_string(st), st, 1);
    }
}