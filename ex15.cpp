#include <iostream>
#include <algorithm>
using namespace std;

void solution(long long num, int length, int n) {
    if(length == n) {
        string numS = to_string(num);
        int cnt = count(numS.begin(), numS.end(), '3');
        if(cnt <= 2) {
            cout << num << "\n";
        }
        return;
    }
    int last = num % 10;
    if(last == 1) {
        solution(num * 10 + last, length + 1, n);
        solution(num * 10 + last + 1, length + 1, n);
        solution(num * 10 + last + 2, length + 1, n);
    } else if (last == 2) {
        solution(num * 10 + last - 1, length + 1, n);
        solution(num * 10 + last, length + 1, n);
        solution(num * 10 + last + 1, length + 1, n);
    } else {
        solution(num * 10 + last - 2, length + 1, n);
        solution(num * 10 + last - 1, length + 1, n);
        solution(num * 10 + last, length + 1, n);
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;
    for(int i{ 1 }; i <= 3; i++) {
        solution(i, 1, n);
    }

    return 0;
}