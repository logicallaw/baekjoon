#include <iostream>
#include <queue>
#include <climits>
#define int long long
using namespace std;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int A, B;
    cin >> A >> B;

    queue<pair<int, int>> Q;
    Q.push({0, A});
    int min_cnt = LONG_MAX;
    bool pass = false;
    while (!Q.empty()) {
        pair<int, int> F = Q.front();
        Q.pop();

        if (F.second > B) continue;

        if (F.second == B) {
            if (min_cnt > F.first) {
                min_cnt = F.first;
                pass = true;
            }
            continue;
        }

        
        Q.push({F.first + 1, F.second * 2});

        string num = to_string(F.second) + "1";
        // cout << num << "\n";
        Q.push({F.first + 1, stol(num)});
    }
    if (!pass) {
        cout << "-1";
    } else {
        cout << min_cnt + 1;
    }
}