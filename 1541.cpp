#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string str;
    cin >> str;

    vector<int> num;
    vector<char> oper;
    vector<int> idx;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '-' || str[i] == '+') {
            idx.push_back(i);
            oper.push_back(str[i]);
        }
    }

    int st = 0;
    for (int i = 0; i < idx.size(); i++) {
        num.push_back(stoi(str.substr(st, idx[i])));
        st = idx[i] + 1;
    }
    num.push_back(stoi(str.substr(st, str.length())));

    int sum = num[0];
    for (int i = 1; i < num.size(); i++) {
        if (oper[i-1] == '-') {
            sum += -num[i];
        } else {
            sum += num[i];
        }
    }
    
    bool pass = false;
    for (int i = 1; i < num.size(); i++) {
        if (oper[i-1] == '-') {
            pass = true;
        } else {
            if (pass) {
                sum = sum  - (num[i] * 2);
            }
        }
    }
    cout << sum;

    // priority_queue<int, vector<int>, greater<int>> Q;
    // Q.push(sum);

    // bool pass = false;
    // int total = 0;
    // for (int i = 1; i < num.size(); i++) {
    //     if (oper[i-1] == '-') {
    //         if (!pass) {
    //             pass = true;
    //             continue;    
    //         }
    //         Q.push(sum + (-total) * 2);
    //         pass = true;
    //         total = 0;
    //     }
    //     if (pass) {
    //         total += num[i];
    //     }
    // }
    // Q.push(sum + (-total) * 2);

    // for (auto& ele : num) {
    //     cout << ele << " ";
    // }
    // cout << "\n";

    // cout << "sum: " << sum << "\n";

    // cout << Q.top();

}
// split 하는 STL은 없을까?