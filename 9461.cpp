#include <iostream>
#define int long long
using namespace std;

int arr[101];

signed main() {
    int T;
    cin >> T;

    arr[1] = 1;
    arr[2] = 1;
    arr[3] = 1;
    arr[4] = 2;
    arr[5] = 2;
    arr[6] = 3;
    arr[7] = 4;
    arr[8] = 5;
    arr[9] = 7;

    int x = 5;
    int cur = 10;

    while(T--) {
        int N;
        cin >> N;

        if (cur > N) {
            cout << arr[N] << '\n';
            continue;
        }

        for (int i = cur; i <= N; i++) {
            arr[cur] = arr[cur-1] + arr[x];
            cur++;
            x++;
        }
        cout << arr[N] << '\n';
    }
}