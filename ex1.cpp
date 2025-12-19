#include <iostream>
#include <count.h>
using namespace std;
int arr[100][100] {};
int n;

bool isRange(int x, int y) {
    if(x >= 0 && x < n) {
        if (y >= 0 && y < n) {
            return true;
        }
    }
    return false;
}

void dfs(const int k, int x, int y) {
    if(arr[x][y] == k) {
        arr[x][y] = 0;
    } else {
        return;
    }
    if(isRange(x-1, y)) {
        dfs(k, x-1, y);
    }
    if (isRange(x+1, y)) {
        dfs(k, x+1, y);
    }
    if (isRange(x, y-1)) {
        dfs(k, x, y-1);
    }
    if (isRange(x, y + 1)) {
        dfs(k, x, y+1);
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;
    for(int i{ 0 }; i < n; i++) {
        for(int j{ 0 }; j < n; j++) {
            cin >> arr[i][j];
        }
    }
    int result[3] {};
    for(int i{ 0 }; i < n; i++) {
        for(int j{ 0 }; j < n; j++) {
            int temp = arr[i][j];
            if (temp == 0) {
                continue;
            }
            dfs(temp, i, j);
            result[temp - 1]++;
        }
    }

    cout << result[0] << " " << result[1] << " " << result[2];
    return 0;
}
/*
5
2 2 1 1 2
2 2 1 1 1
2 2 3 1 1
2 1 3 3 3
1 1 1 3 2
 */