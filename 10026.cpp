#include <iostream>
using namespace std;

char arr[101][101];
bool visited[101][101];

int area;
int N;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

bool isRange(int a, int b) {
    return (0 <= a && a < N) && (0 <= b && b < N);
}

void dfs(int x, int y, char c) {
    visited[x][y] = true;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (!isRange(nx, ny)) continue;
        if (visited[nx][ny]) continue;
        if (!(arr[nx][ny] == c)) continue;
        dfs(nx, ny, c);
    }
}

void dfs2(int x, int y, char c) {
    // cout << "Welcome " << x << " " << y << "\n";
    visited[x][y] = true;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (!isRange(nx, ny)) continue;
        if (visited[nx][ny]) {
            // cout << "Visited: " << nx << " " << ny << "\n";
            continue;
        }
        if (c == 'B') {
            if (arr[nx][ny] == 'B') {
                dfs2(nx, ny, c);
            }
        } else {
            // cout << "HI " << nx << " " << ny << "\n";
            if (arr[nx][ny] != 'B') {
                dfs2(nx, ny, c);
                // cout << "Go! " << nx << " " << ny << "\n";
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            char x;
            cin >> x;
            arr[i][j] = x;
        }
    }

    area = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (visited[i][j]) continue;
            dfs(i, j, arr[i][j]);
            // cout << i << " " << j << " " << area + 1 << "\n";
            area++;
        }
    }
    cout << area << " ";

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            visited[i][j] = false;
        }
    }

    // for (int i = 0; i < N; i++) {
    //     for (int j = 0; j < N; j++) {
    //         cout << "i: " << i << ", j: " << j << ", visited: " << visited[i][j] << "\n";
    //     }
    // }
    area = 0;

    // cout << "\n dfs2 \n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (visited[i][j]) continue;
            // cout << "==\n";
            dfs2(i, j, arr[i][j]);
            // cout << i << " " << j << " " << area + 1 << "\n";
            area++;
        }
    }
    cout << area;


    // cout << "\n Arr \n";
    // for (int i = 0; i < N; i++) {
    //     for (int j = 0; j < N; j++) {
    //         cout << arr[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
}