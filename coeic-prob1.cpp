#include <iostream>
#include <iomanip>
#define int long long
using namespace std;

int dp[51][100'002];
int T[100'002];
int P[100'002];

const int UNSEEN = -1;
int n;

signed main() {
    cin >> n;
    for (int i = 0; i < 51; i++) {
        for (int j = 0; j < (n + 2); j++) {
            dp[i][j] = UNSEEN;
        }
    }
    for (int i = 1; i <= n; i++) {
        int t, p;
        cin >> t >> p;
        T[i] = t;
        P[i] = p;
    }

    dp[0][0] = 0;
    for (int day = 0; day < (n + 2); day++) {
        for (int job = 0; job < 51; job++) {
            if (dp[job][day] == UNSEEN) continue;

            if (job > 1) {
                dp[job-1][day+1] = max(dp[job-1][day+1], dp[job][day]);
            } else {
                int new_day = day + 1;
                int new_job = T[new_day];
                if (new_day + new_job - 1 <= n) {
                    int new_gain = P[new_day];
                    dp[new_job][new_day] = max(dp[new_job][new_day], dp[job][day] + new_gain);
                }
                dp[0][day+1] = max(dp[0][day+1], dp[job][day]);
            }
        }
    }
    // for (int i = 0; i < 51; i++) {
    //     for (int j = 0; j < (n + 2); j++) {
    //         cout << left << setw(3) << dp[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    int answer = dp[0][n+1];
    cout << answer;
    return 0;
}
/* // 80
5
1 30
3 40
1 10
2 40
2 50
*/
/*
0   0   30  30  40  70  80  
-1  30  -1  40  70  80  120 
-1  -1  -1  70  80  120 -1  
-1  -1  70  -1  -1  -1  -1  
*/

/* // 120
5
3 100
1 10
2 30
3 80
1 20
*/