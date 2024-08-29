#include <iostream>
using namespace std;

int n;
int arr[1000][1000] {};
int dp[1000][1000] {};

void init() {
    dp[0][0] = arr[0][0];
    for(int i{ 1 }; i < n; i++) {
        dp[i][0] = dp[i-1][0] + arr[i][0];
        dp[0][i] = dp[0][i-1] + arr[0][i];
    }
}
int main() {

    cin >> n;

    int cnt = n;
    for(int i{ 0 }; i < n; i++) {
        for(int j{ 0 }; j < cnt; j++) {
            cin >> arr[i][j];
        }
        cnt--;
    }
    init();
    for(int i{ 1 }; i <= (n-2); i++) {
        for(int j{ 1 }; j <= (n-i-1) ; j++) {
            dp[i][j] = max(dp[i-1][j] + arr[i][j], dp[i][j-1] + arr[i][j]);
        }
    }
    int max = 0;
    cnt = n - 1;
    for(int i{ 0 }; i < n; i++) {
        int temp = dp[i][cnt];
        max = (max < temp) ? temp : max;
        cnt--;
    }
    cout << max;

    return 0;
}