#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<pair<int, int>> V;

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        V.emplace_back(x, y);
    }

    for (int i = 0; i < N; i++) {
        int rank = 1;
        for (int j = 0; j < N; j++) {
            if (j == i) {
                continue;
            }
            if (V[j].first > V[i].first && V[j].second > V[i].second) {
                rank++;
            }
        }
        cout << rank << " ";
    }
}