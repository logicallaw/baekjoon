#include <iostream>
using namespace std;

int arr[100][100] {};
int n;
int cnt = 0;

void dfs(int, int, int);

bool isRange(int x, int y) {
    if(x >= 0 && x < n) {
        if(y >= 0 && y < n) {
            return true;
        }
    }
    return false;
}

void dfs(int x, int y) {
    if(arr[x][y] == 1) {
        arr[x][y] = 0;
        cnt++;
    } else {
        return;
    }
    if(isRange(x-1, y)) {
        dfs(x-1, y);
    }
    if (isRange(x+1, y)) {
        dfs(x+1, y);
    }
    if (isRange(x, y-1)) {
        dfs(x, y-1);
    }
    if (isRange(x, y + 1)) {
        dfs(x, y+1);
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
    int result = 0;
    for(int i{ 0 }; i < n; i++) {
        for(int j{ 0 }; j < n; j++) {
//            if(arr[i][j] != 0 && solution(i, j)) {
//                result++;
//            }
            if(arr[i][j] == 1) {
                dfs(i, j);
                if(cnt == 3) {
                    result++;
                }
                cnt = 0;
            }
        }
    }
    cout << result;
    return 0;
}

/*
5
1 1 0 1 1
1 0 1 0 1
0 0 1 1 1
1 1 0 0 1
0 1 0 1 1
 */