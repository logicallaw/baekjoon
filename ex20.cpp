#include <iostream>
#include <climits>
using namespace std;

int n;
int arr[100000] {};
int dp[100000] {};

void init() {
    for(int i{ 0 }; i < n; i++) {
        dp[i] = INT_MIN;
    }
    dp[0] = arr[0];
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;
    for(int i{ 0 }; i < n; i++) {
        cin >> arr[i];
    }
    init();

    for(int i{ 1 }; i < n; i++) {
        dp[i] = max(dp[i-1] + arr[i], arr[i]);
    }

    int result = dp[0];

    for(int i{ 1 }; i < n; i++) {
        result = (result < dp[i]) ? dp[i] : result;
    }
    cout << result;
    return 0;
}