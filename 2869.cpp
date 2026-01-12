#include <iostream>
#include <unordered_map>
#define int long long

using namespace std;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int A, B, V;
    cin >> A >> B >> V;

    int diff = A - B;
    int R = V - A;
    int M = R / diff;

    if (diff * M + A >= V) {
        cout << M + 1;
    } else {
        cout << M + 2;
    }

}