#include <iostream>
#include <unordered_map>
#include <cmath>
#define int long long

using namespace std;

const int M = 1234567891;
const int R = 31;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    string input;
    cin >> input;

    int total = 0;
    for (int i = 0; i < N; i++) {
        int num = input[i] - 'a' + 1;
        int r_power = 1;

        int r_power_cnt = 0;
        while (true) {
            if (r_power_cnt == i) {
                break;
            }
            r_power = (r_power * R) % M;
            r_power_cnt++;
        }
        int element = (num * r_power) % M;
        total = (total + element) % M;
    }
    cout << total % M;

}