#include <iostream>
#include <vector>
using namespace std;

vector<int> V;

void f(int st, int end) {
    if (st >= end) {
        return;
    }
    int cur = st + 1;
    while(cur < end) {
        if (V[cur] > V[st]) break;
        cur++;
    }

    f(st+1, cur);
    f(cur, end);

    cout << V[st] << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int x;
    while(cin >> x) {
        V.push_back(x);
    }

    f(0, V.size());
    return 0;
}