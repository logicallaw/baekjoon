#include <iostream>
using namespace std;
int isMultipleOfTwo(int num) {
    int cnt = 0;
    while(num % 2 == 0) {
        cnt++;
        num /= 2;
    }
    return cnt;
}
int isMultipleOfFive(int num) {
    int cnt = 0;
    while(num % 5 == 0) {
        cnt++;
        num /= 5;
    }
    return cnt;
}
int min(int a, int b) {
    return (a < b) ? a : b;
}
int main(void) {
    int n;
    cin >> n;

    int cntOfTwo = 0;
    int cntOfFive = 0;
    for(int i{ n }; i >= 2; i--) {
        cntOfTwo += isMultipleOfTwo(i);
        cntOfFive += isMultipleOfFive(i);
    }
    cout << min(cntOfTwo, cntOfFive);
    return 0;
}