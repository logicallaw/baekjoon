#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void getBinary(int num, int n) {
    int size = n;
    char* tmp = new char[n + 1];
    tmp[n] = '\0';

    while(num != 0) {
        int temp = num % 2;
        tmp[--n] = temp + '0';
        num /= 2;
    }

    while(n != 0) {
        tmp[--n] = '0';
    }

    int cnt = 1;
    for(int i{ 0 }; i < (size - 1); i++) { //0 ~ size-1  i = 0, i = size -1
        if(i == 0) {
            cnt = 1;
        }
        if(tmp[i] == tmp[i + 1]) {
            cnt++;
            if(cnt == 3) {
                return;
            }
        } else {
            cnt = 1;
        }
    }
    cout << tmp << "\n";

}

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;
    int size = pow(2, n);
    for(int i{ 0 }; i < size; i++) {
        getBinary(i, n);
    }
    return 0;
}