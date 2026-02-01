#include <iostream>
using namespace std;

int arr[301];
int dp[301+3];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        arr[i] = x;
    }

    dp[n] = arr[n];
    // cout << dp[n] << "HI\n";
    for (int i = n-1; i >= 1; i--) {
        int x = 0, y = 0;

        if (i + 1 == n) {
            dp[i] = arr[i] + dp[i+1];
            // cout << i << " " << dp[i] << "\n";
            continue;
        }

        if (i + 1 <= n && i + 3 <= n) {
            x = (arr[i] + arr[i+1]) + dp[i+3];
        }

        if (i + 2 <= n) {
            y = (arr[i] + dp[i+2]);
        }
        dp[i] = max(x, y);
        // cout << "==\n";
        // cout << i << " " << dp[i] << "\n";
        // cout << x << " " << y << "\n";
        // cout << "==\n";
    }
    if (n >= 2) {
        cout << max(dp[1], dp[2]);
    } else {
        cout << dp[1];
    }
}