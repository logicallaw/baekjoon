#include <iostream>
using namespace std;

int n;
int cnt = 0;
int arr[100][100] {};

bool isRange(int, int);
void dfs(int, int);


int main(void) {
    cin >> n;
    for(int i{ 0 }; i < n; i++) {
        for(int j{ 0 }; j < n; j++) {
            cin >> arr[i][j];
        }
    }
    int result = 0;
    for(int i{ 0 }; i < n; i++) {
        for(int j{ 0 }; j < n; j++) {
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
}

bool isRange(int x, int y) {
    if(x >= 0 && x < n) {
        if(y >= 0 && y < n) {
            return true;
        }
    }
    return false;
}

void dfs(int i, int j) {
    if(arr[i][j] == 1) {
        arr[i][j] = 0;
        cnt++;
    } else {
        return;
    }

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

//i=1~2
//j=1~2, 1
//n=4
//(1,1)(1,2)(2,1)