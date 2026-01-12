#include <iostream>
#include <set>
#include <iterator>

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
        multiset<int> MS;

        while (k--) {
            string I;
            int n;

            cin >> I >> n;

            if (I == "I") {
                MS.insert(n);
            } else if (n == 1) {
                if (!MS.empty()) {
                    MS.erase(prev(MS.end()));
                }
            } else {
                if (!MS.empty()) {
                    MS.erase(MS.begin());
                }
            }
        }

        if (MS.empty()) {
            cout << "EMPTY\n";
        } else {
            cout << *(prev(MS.end())) << " " << *(MS.begin()) << "\n";
        }
    }


}