#include <iostream>
using namespace std;

int n;
int arr[1000][1000] {};
int dp[1000][1000] {};

void init() {
    dp[0][0] = arr[0][0];
    for(int i{ 1 }; i < n; i++) {
        dp[i][0] = dp[i-1][0] + arr[i][0];
    }
    for(int i{ 1 }; i < n; i++) {
        dp[0][i] = dp[0][i-1] + arr[0][i];
    }
}

int main(void) {
    cin >> n;
    int cnt = n;
    for(int i{ 0 }; i < n; i++) {
        for(int j{ 0 }; j < cnt; j++) {
            cin >> arr[i][j];
        }
        cnt--;
    }
    init();
    cnt = n; //3
    for(int i{ 1 }; i < n; i++) { //1,2
        for(int j{ 1 }; j < cnt; j++) {
            dp[i][j] = max(dp[i-1][j] + arr[i][j], dp[i][j-1] + arr[i][j]);
        }
        cnt--;
    }
    int sumMax = INT_MIN;

    for(int i{ 0 }; i < n; i++) { //i=0, n=4 i=3, n=4
        sumMax = (sumMax < dp[i][n-i-1]) ? dp[i][n-i-1] : sumMax;
    }
    cout << sumMax;
    return 0;
}
/*
4
6 2 5 1
4 2 9
3 8
4
 */