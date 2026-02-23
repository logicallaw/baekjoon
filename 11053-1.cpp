#include <iostream>
#include <vector>

using namespace std;

vector<int> arr;
vector<int> dp;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        arr.push_back(x);
    }

    dp.assign(N, 1);

    for (int i = 1; i < N; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[j] < arr[i]) {
                dp[i] = max(dp[j] + 1, dp[i]);
            }
        }
    }
    int ans = 0;
    for (auto d : dp) {
        ans = max(ans, d);
    }
    cout << ans;

}