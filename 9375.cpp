#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        unordered_map<string, int> UM;
        vector<int> V;

        for (int i = 0; i < N; i++) {
            string a, b;
            cin >> a >> b;
            if (UM.find(b) == UM.end()) {
                V.push_back(1);
                UM.insert({b, V.size() - 1});
            } else {
                V[UM[b]]++;
            }
        }
        int ans = 1;
        for (int i = 0; i < V.size(); i++) {
            ans *= (V[i] + 1);
        }
        cout << ans - 1 << "\n";
    }
}