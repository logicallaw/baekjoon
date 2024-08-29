#include <iostream>
using namespace std;

void solution(int num, int length, int n, int k) {
    if(length == k) {
        string numS = to_string(num);
        for(int i{ 0 }; i < k; i++) {
            cout << numS[i] << " ";
        }
        cout << endl;
        return;
    }
    int last = num % 10;
    if(last == n) {
        for(int i{ 0 }; i < n; i++) {
            solution(num * 10 + last - i, length + 1, n, k);
        }
    } else {
        for(int i{ n }; i >= 1; i--) {
            solution(num * 10 + i, length + 1, n, k);
        }
    }

}

int main() {
    // 여기에 코드를 작성해주세요.
    int n, k;
    cin >> n >> k;
    for(int i{ n }; i >= 1; i--) {
        solution(i, 1, n, k);
    }
    return 0;
}