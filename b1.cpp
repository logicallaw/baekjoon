#include <iostream>
using namespace std;

int n;
int arr[100][100] {};
int result[100][100] {};

int dx[8] = {-2, -2, +2, +2, -1, -1, +1, +1};
int dy[8] = {-1, +1, -1, +1, -2, +2, -2, +2};

bool isRange(int i, int j) {
    if(i >= 0 && i < n) {
        if(j >=0 && j < n) {
            return true;
        }
    }
    return false;
}

void dfs(int x, int y) {
    if(result[x][y] == 1) {
        return;
    }

    result[x][y] = 1;

    for(int i{ 0 }; i < 8; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(isRange(nx, ny) && arr[nx][ny] == 0) {
            dfs(nx, ny);
        }
    }
}

int main(void) {
    cin >> n;

    for(int i{ 0 }; i < n; i++) {
        for(int j{ 0 }; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    int x, y;
    cin >> x >> y;

    dfs(x-1, y-1);

    for(int i{ 0 }; i < n; i++) {
        for(int j{ 0 }; j < n; j++) {
            cout << result[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}
/*
5
1 1 1 1 1
1 1 1 1 1
1 1 0 0 0
1 1 0 0 0
1 1 0 0 0
5 5
 */