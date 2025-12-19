#include <iostream>
using namespace std;

int n;
int arr[100][100] {};

int cnt = 0;

int a = 0;
int b = 0;

int p = 0;

bool isRange(int i, int j) {
    if(i >= 0 && i < n) {
        if(j >= 0 && j < n) {
            return true;
        }
    }
    return false;
}

void dfs(int i, int j) {
    if(arr[i][j] == 0) {
        return;
    }
    //1,2,3
    if (arr[i][j] == 2) {
        p = 2;
    } else if (arr[i][j] == 3) {
        p = 3;
    }

    arr[i][j] = 0;
    cnt++;

    if(isRange(i-1, j)) {
        dfs(i-1, j);
    }
    if(isRange(i+1, j)) {
        dfs(i+1, j);
    }
    if(isRange(i, j-1)) {
        dfs(i, j-1);
    }
    if(isRange(i, j+1)) {
        dfs(i, j+1);
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

    for(int i{ 0 }; i < n; i++) {
        for(int j{ 0 }; j < n; j++) {
            if(arr[i][j] == 2) {
                cnt = 0;
                dfs(i, j);
                a = cnt;
            } else if (arr[i][j] == 3) {
                cnt = 0;
                dfs(i, j);
                b = cnt;
            }
        }
    }

    cout << a << " " << b;
    return 0;
}
/*
17
0 1 0 0 1 0 1 0 1 0 0 0 1 0 1 0 0
0 0 0 0 1 0 0 1 1 0 0 0 0 0 0 0 0
1 0 0 0 1 0 1 1 0 1 1 1 1 0 1 0 0
0 0 0 0 0 1 0 1 0 0 1 0 1 1 1 1 1
1 1 0 0 0 0 0 0 0 0 0 0 1 1 1 1 1
0 1 0 0 1 0 0 0 1 0 0 0 0 0 0 1 0
0 1 1 0 1 1 0 0 0 0 1 0 1 0 1 0 0
1 0 0 0 1 1 0 0 0 0 1 0 1 1 1 0 0
0 0 0 1 0 0 0 0 0 0 0 0 1 0 1 0 1
0 0 1 1 0 0 1 0 1 1 1 1 0 0 0 0 0
0 0 1 0 1 2 1 0 0 0 1 0 0 1 1 1 1
0 0 1 0 1 0 0 0 0 1 1 1 1 0 0 1 1
0 0 0 1 0 1 0 0 1 1 1 3 0 0 0 0 0
1 1 0 0 0 0 1 0 0 0 1 0 0 0 1 0 1
1 0 0 0 0 0 1 0 0 0 0 1 0 1 0 1 0
1 1 0 0 1 0 0 0 0 1 0 0 1 1 0 1 0
1 0 0 0 0 1 0 1 0 1 0 0 0 1 0 0 1

5 14
5 1
 */