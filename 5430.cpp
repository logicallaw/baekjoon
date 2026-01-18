#include <iostream>
#include <string>

using namespace std;

int arr[100'001];
int st = 0;
int ed = -1;
bool asc = true;

bool isEmpty() {
    return ((ed - st  + 1) == 0);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // for (int i = 0; i < 101; i++) {
    //     if (i % 2 == 0 && i % 3 == 0) {
    //         cout << "R";
    //     } else {
    //         cout << "D";
    //     }
    // }
    // return 0;

    int T;
    cin >> T;

    while (T--) {
        st = 0;
        ed = -1;
        asc = true;

        string p;
        cin >> p;

        int n;
        cin >> n;

        string str;
        cin >> str;

        string tmp;

        for (int i = 1; i < (str.length() - 1); i++) {
            if (str[i] != ',') {
                tmp += str[i];
            } else {
                arr[++ed] = stoi(tmp);
                tmp = "";
            }
        }

        if (!tmp.empty()) {
            arr[++ed] = stoi(tmp);
        }

        // cout << "===  ===\n";
        // cout << "[";
        // for (int i = st; i <= ed - 1; i++) {
        //     cout << arr[i] << ",";
        // }
        // cout << arr[ed] << "]\n";
        //
        // cout << "===  ===\n";

        bool isError = false;
        for (int i = 0; i < p.length(); i++) {
            char c = p[i];

            if (c == 'R') {
                asc = !asc;
            } else {
                if (isEmpty()) {
                    cout << "error\n";
                    isError = true;
                    break;
                }
                if (asc) {
                    st++;
                } else {
                    ed--;
                }
            }
        }

        if (isError) continue;

        if (isEmpty()) {
            cout << "[]\n";
            continue;
        }

        // cout << "st: " << st << ", ed: " << ed << "\n";

        cout << "[";
        if (asc) {
            for (int i = st; i < ed; i++) {
                cout << arr[i] << ",";
            }
            cout << arr[ed] << "]\n";
        } else {
            for (int i = ed; i > st; i--) {
                cout << arr[i] << ",";
            }
            cout << arr[st] << "]\n";
        }
    }
}