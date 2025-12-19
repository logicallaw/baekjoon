#include <iostream>
using namespace std;
int getSolution(int row, int col, char** board) {
    char whiteBoard[2][9] = {
            "WBWBWBWB",
            "BWBWBWBW"
    };
    int cnt = 0;
    for(int i{ 0 }; i < 8; i++) {
        for(int j{ 0 }; j < 8; j++) {
            if(whiteBoard[i % 2][j] != board[row + i][col + j]){
                cnt++;
            }
        }
    }
    return cnt;
}
int main(void) {
    int n, m;
    cin >> n >> m;
    char** board = new char*[n];
    for(int i{ 0 }; i < n; i++) {
        board[i] = new char[m];
        for(int j{ 0 }; j < m; j++) {
            cin >> board[i][j];
        }
    }
    int result = INT32_MAX;
    for(int i{ 0 }; i <= (n-8); i++) {
        for(int j{ 0 }; j <= (m-8); j++) {
            int temp = getSolution(i, j, board);
            temp = ((64 - temp) > temp) ? temp : 64- temp;
            if(result > temp) {
                result = temp;
            }
        }
    }
    cout << result;
    for(int i{ 0 }; i < n; i++) {
        delete board[i];
    }
    delete[] board;
    return 0;
}