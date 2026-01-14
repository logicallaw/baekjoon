#include <iostream>
#include <unordered_map>
#define int long long

using namespace std;

unordered_map<int, pair<int, int>> um;

pair<int, int> fibonacci(int n) {
    if (um.find(n) != um.end()) {
        return {um[n].first, um[n].second};
    }
    pair<int, int> p1 = fibonacci(n - 1);
    pair<int, int> p2 = fibonacci(n - 2);
    pair<int, int> total = {p1.first + p2.first, p1.second + p2.second};

    um.insert({n, total});
    return total;
}


signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        um.insert({0, {1, 0}});
        um.insert({1, {0, 1}});

        fibonacci(N);

        cout << um[N].first << " " << um[N].second << "\n";
    }
}