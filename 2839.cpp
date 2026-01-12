#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    int M_F = N / 5;

    bool pass = false;
    int ans = 0;
    while (M_F != -1) {
        int tmp = N - M_F * 5;
        if (tmp % 3 == 0) {
            ans += M_F + (tmp / 3);
            pass = true;
            break;
        }
        M_F--;
    }

    cout << ((pass) ? ans : -1);
}