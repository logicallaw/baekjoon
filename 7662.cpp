#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;

    while (T--) {
        int k;
        cin >> k;

        priority_queue<int> GQ;
        priority_queue<int, vector<int>, greater<int>> LQ;
        unordered_map<int, int> GM, LM;

        for (int i = 0; i < k; i++) {
            string I;
            int n;

            cin >> I >> n;

            if (I == "I") {
                GQ.push(n);
                LQ.push(n);
            } else if (n == 1) {
                while (!GQ.empty()) {
                    int t = GQ.top();
                    if (GM[t] > 0) {
                        GM[t]--;
                        GQ.pop();
                    } else {
                        break;
                    }
                }
                if (!GQ.empty()) {
                    LM[GQ.top()]++;
                    GQ.pop();
                }
            } else {
                while (!LQ.empty()) {
                    int t = LQ.top();
                    if (LM[t] > 0) {
                        LM[t]--;
                        LQ.pop();
                    } else {
                        break;
                    }
                }
                if (!LQ.empty()) {
                    GM[LQ.top()]++;
                    LQ.pop();
                }
            }
        }

        while (!GQ.empty()) {
            int t = GQ.top();
            if (GM[t] > 0) {
                GM[t]--;
                GQ.pop();
            } else {
                break;
            }
        }

        while (!LQ.empty()) {
            int t = LQ.top();
            if (LM[t] > 0) {
                LM[t]--;
                LQ.pop();
            } else {
                break;
            }
        }

        if (GQ.empty()) {
            cout << "EMPTY\n";
        } else {
            cout << GQ.top() << " " << LQ.top() << "\n";
        }
    }
}