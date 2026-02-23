#include <iostream>
#include <vector>
using namespace std;

vector<int> arr[1001];
vector<int> dp[1001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 3; j++) {
            int x;
            cin >> x;
            arr[i].push_back(x);
        }
        dp[i].assign(3, 0);
    }

    dp[N-1][0] = arr[N-1][0];
    dp[N-1][1] = arr[N-1][1];
    dp[N-1][2] = arr[N-1][2];

    // cout << dp[N-1][0] << " " << dp[N-1][1] << " " << dp[N-1][2] << "\n";

    for (int i = N-2; i >= 0; i--) {
        dp[i][0] = arr[i][0] + min(dp[i+1][1], dp[i+1][2]);
        dp[i][1] = arr[i][1] + min(dp[i+1][0], dp[i+1][2]);
        dp[i][2] = arr[i][2] + min(dp[i+1][0], dp[i+1][1]);
        // cout << dp[i][0] << " " << dp[i][1] << " " << dp[i][2] << "\n";
    }

    cout << min(min(dp[0][0], dp[0][1]), dp[0][2]);

}