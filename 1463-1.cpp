#include <iostream>
#include <vector>

using namespace std;

const int L = 1000001;

int dp[L];

int main() {
    int N;
    cin >> N;

    dp[0] = 0;
    dp[1] = 0;
    dp[2] = 1;

    for (int i = 3; i <= N; i++) {
        vector<int> V;
        if (i % 3 == 0 && i / 3 >= 0) {
            V.push_back(dp[i / 3]);
        }
        if (i % 2 == 0 && i / 2 >= 0) {
            V.push_back(dp[i / 2]);
        }
        if (i - 1 >= 0) {
            V.push_back(dp[i - 1]);
        }
        int MIN = V.front();
        for (auto& ele : V) {
            MIN = min(ele, MIN);
        }
        dp[i] = MIN + 1;
    }
    cout << dp[N];
}