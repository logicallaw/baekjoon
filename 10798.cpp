#include <iostream>
#include <string>
using namespace std;
int main(void){
    string board[5];
    for(int i{ 0 }; i < 5; i++) {
        cin >> board[i];
    }
    for(int i{ 0 }; i < 15; i++) {
        if(i < board[0].length()) {
            cout << board[0][i];
        }
        if(i < board[1].length()) {
            cout << board[1][i];
        }
        if(i < board[2].length()) {
            cout << board[2][i];
        }
        if(i < board[3].length()) {
            cout << board[3][i];
        }
        if(i < board[4].length()) {
            cout << board[4][i];
        }
    }
}