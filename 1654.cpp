#include <iostream>
#include <vector>
#define int long long
using namespace std;

vector<int> V;
int K, N;
int ans = 0;

void f(int st, int end) {
    if (st > end) return;

    int mid = (st + end) / 2;
    int need = 0;
    for (int i = 0; i < V.size(); i++) {
        need += V[i] / mid;
    }
    if (N <= need) {
        ans = max(ans, mid);
        f(mid + 1, end);
    } else {
        f(st, mid - 1);
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> K >> N;

    int st = 1;
    int end = 0;

    for (int i = 0; i < K; i++) {
        int x;
        cin >> x;
        V.push_back(x);
        end = max(end, x);
    }

    f(st, end);
    cout << ans;
}