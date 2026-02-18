#include <iostream>
#include <vector>

using namespace std;

int parent[51];
vector<int> V[51];

int leader(int v) {
    if (parent[v] < 0) {
        return v;
    }
    return leader(parent[v]);
}

void uni(int x, int y) {
    int lx = leader(x);
    int ly = leader(y);

    if (lx == ly) return;

    if (parent[lx] > parent[ly]) {
        swap(lx, ly);
    }

    if (parent[lx] == parent[ly]) {
        parent[lx]--;
    }

    parent[ly] = lx;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, M;
    cin >> N >> M;

    for (int i = 0; i <= N; i++) {
        parent[i] = -1;
    }

    int x;
    cin >> x;

    int par;
    if (x == 0) {
        par = 0;
    }  else {
        int y;
        cin >> y;

        par = y;

        for (int i = 1; i < x; i++) {
            cin >> y;
            uni(par, y);
        }
    }

    for (int i = 0; i < M; i++) {
        int a;
        cin >> a;

        if (a == 1) {
            int b; 
            cin >> b;
            V[i].push_back(b);
        } else {
            int prev;
            cin >> prev;
            V[i].push_back(prev);

            for (int j = 1; j < a; j++) {
                int cur;
                cin >> cur;
                V[i].push_back(cur);
                uni(prev, cur);
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < M; i++) {
        bool pass = true;
        for (auto a : V[i]) {
            if (leader(a) == leader(par)) {
                pass = false;
                break;
            }
        }
        if (pass) ans++;
    }

    cout << ans;
}