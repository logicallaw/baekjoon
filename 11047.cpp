#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, K;
    cin >> N >> K;

    vector<int> V;

    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        V.push_back(x);
    }

    int cnt = 0;
    for (int i = V.size() - 1; i >= 0; i--) {
        if (K == 0) {
            break;
        }
        int tmp = K / V[i];
        if (tmp == 0) {
            continue;
        }
        cnt += tmp;
        K -= V[i] * tmp;
    }
    cout << cnt;
}