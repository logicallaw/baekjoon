#include <iostream>
#include <cmath>

using namespace std;

int dp[50'001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;

    for (int i = 4; i <= N; i++) {
        for (int j = sqrt(i); j >= 1; j--) {
            int cur_value = 1 + dp[i - j * j];
            if (j == (int)sqrt(i)) {
                dp[i] = cur_value;
                continue;
            }
            dp[i] = min(dp[i], cur_value);
        }
    }
 
    cout << dp[N];
}