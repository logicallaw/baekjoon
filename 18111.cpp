#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <climits>
#define int long long

using namespace std;

int ans = LONG_MAX;
int arr[257];

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // for (int i = 0; i < 500 * 500 - 1; i++) {
    //     cout << 0 << " ";
    // }
    // return 0;

    int N, M, B;
    cin >> N >> M >> B;

    for (int i = 0; i < N * M; i++) {
        int x;
        cin >> x;
        arr[x]++;
    }

    int height = 0;

    for (int i = 0; i <= 256; i++) {
        int time = 0;
        int block = B;

        for (int j = i + 1; j <= 256; j++) {
            int diff = arr[j] * (j - i);
            time += 2 * diff;
            block += diff;
        }

        // if (i == 63) cout << time << "\n";

        int need = 0;
        for (int j = 0; j < i; j++) {
            need += arr[j] * (i - j);
        }
        if (i != 0 && need > block) continue;
        time += need;
        if (ans >= time) {
            ans = time;
            // cout << i << " " << time <<  " " <<  height << "\n"; 
            height = max(height, i);
        }
    }

    cout << ans << " " << height; 
}