#include <iostream>
#include <cmath>
using namespace std;

char* getBinary(int n, int num) {
    char* tmp = new char[n+1];
    tmp[n] = '\0';
    while(num != 0) {
        int temp = num % 2;
        tmp[--n] = temp + '0';
        num /= 2;
    }
    while(n != 0) {
        tmp[--n] = '0';
    }
    return tmp;
}

void solution(string str) {
    bool isSeq = false;
    for(int i{ 0 }; i < (str.length() - 1); i++) {
        if(str[i] == '0' && str[i + 1] == '0') {
            isSeq = true;
        }
    }
    if(!isSeq) {
        cout << str << endl;
    }
}

int main(void) {
    int n;
    cin >> n;
    int size = pow(2, n);
    string* arr = new string[size] {};
    for(int i{ size - 1 }; i >= 0; i--) {
        arr[i] = getBinary(n, i);
        solution(arr[i]);
    }
    delete[] arr;
}
