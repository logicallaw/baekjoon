#include <iostream>

using namespace std;

int arr[601][601];
bool visited[601][601];

int N, M;
int p;

int da[4] = {0, 0, 1, -1};
int db[4] = {1, -1, 0, 0};

bool isRange(int a, int b) {
    return (0 <= a && a < N) && (0 <= b && b < M);
}

void dfs(int a, int b) {
    visited[a][b] = true;
    if (arr[a][b] == 'P') {
        p++;
    }

    for (int i = 0; i < 4; i++) {
        int na = a + da[i];
        int nb = b + db[i];
        if (!isRange(na, nb)) continue;
        if (visited[na][nb]) continue;
        if (arr[na][nb] == 'X') continue;
        dfs(na, nb);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    int x, y;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            char c;
            cin >> c;
            arr[i][j] = c;
            if (c == 'I') {
                x = i;
                y = j;
            }
        }
    }

    dfs(x, y);
    if (p == 0) {
        cout << "TT";
    } else {
        cout << p;
    }
}