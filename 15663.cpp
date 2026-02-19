#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int N, M;

int num[9];
int arr[9];
bool check[9];

void dfs(int depth) {
    if (depth == M) {
        for (int i = 0; i < M - 1; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }

    int prev = -1;
    for (int i = 0; i < N; i++) {
        if (!check[i] && prev != num[i]) {
            arr[depth] = num[i];
            check[i] = true;
            prev = num[i];
            dfs(depth + 1);
            check[i] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        num[i] = x;
    }

    sort(num, num + N);

    dfs(0);
}