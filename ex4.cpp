#include <iostream>
using namespace std;

void solution(long long num, int length, int n) {
    if(length == n) {
        cout << num << "\n";
        return;
    }
    int remainder = num % 10;
    if(remainder > 1) {
        solution(num * 10 + remainder - 1, length + 1, n);
    }
    if(remainder < 9) {
        solution(num * 10 + remainder + 1, length + 1, n);
    }
}
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for (int i{ 1 }; i <= 9; i++) {
        solution(i, 1, n);
    }
    return 0;
}