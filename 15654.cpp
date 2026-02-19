#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int N, M;

vector<int> arr;

void dfs(string str, int cnt, set<int> s) {
    if (cnt == M) {
        cout << str << "\n";
        return;
    }

    for (int nxt = 0; nxt < N; nxt++) {
        if (s.find(nxt) != s.end()) continue;
        set<int> ss = s;
        ss.insert(nxt);
        dfs(str + " " + to_string(arr[nxt]), cnt + 1, ss);
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
        arr.push_back(x);
    }

    sort(arr.begin(), arr.end());

    // for (auto a : arr) {
    //     cout << a << " ";
    // }
    // cout << "==\n";

    for (int i = 0; i < N; i++) {
        set<int> s;
        s.insert(i);
        dfs(to_string(arr[i]), 1, s);
    }
}