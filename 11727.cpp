#include <iostream>

using namespace std;

const int MOD = 10'007;

int arr[1001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    arr[1] = 1;
    arr[2] = 3;
    for (int i = 3; i <= n; i++) {
        int a = arr[i-1];
        int b = (arr[i-2] * 2) % MOD;
        arr[i] = (a + b) % MOD;
    }
    cout << arr[n];
}