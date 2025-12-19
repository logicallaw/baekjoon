#include <iostream>
using namespace std;

int n;
int arr[1000][1000] {};
int dp[1000][1000] {};

void init() {
    dp[0][n-1] = arr[0][n-1];
    for(int i{ n - 2 }; i >= 0; i--) {
        dp[0][i] = dp[0][i+1] + arr[0][i];
    }
    for(int i{ 1 }; i <= (n - 1); i++) {
        dp[i][n-1] = dp[i-1][n-1] + arr[i][n-1];
    }
}
int main(void) {
    cin >> n;
    for(int i{ 0 }; i < n; i++) {
        for(int j{ 0 }; j < n; j++) {
            cin >> arr[i][j];
        }
    }
    init();
    for(int i{ 1 }; i <= (n-1); i++) {
        for(int j{ n-2 }; j >= 0; j--) {
            int c = arr[i][j];
            dp[i][j] = max(max(dp[i-1][j] + c, dp[i-1][j+1] + c), dp[i][j+1] + c);
        }
    }
    cout << dp[n-1][0];
//    for(int i{ 0 }; i < n; i++) {
//        for(int j{ 0 }; j < n; j++) {
//            cout << dp[i][j] << " ";
//        }
//        cout << endl;
//    }
}