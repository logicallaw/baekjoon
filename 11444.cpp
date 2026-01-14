#include <iostream>
#include <unordered_map>
#define int long long
using namespace std;

const int M = 1'000'000'007;

unordered_map<int, int> UM;

int fibo(int n) {
    if (UM.find(n) != UM.end()) return UM[n];

    int result;
    if (n % 2 == 0)
        result = ((fibo(n / 2 + 1) * fibo(n / 2)) % M + (fibo(n / 2) * fibo(n / 2 - 1)) % M) % M;
    else
        result = ((fibo((n + 1) / 2) * fibo((n + 1) / 2)) % M + (fibo((n - 1) / 2) * fibo((n - 1) / 2)) % M) % M;

    UM.insert({n, result});
    return result;
}

signed main() {
    int n;
    cin >> n;

    UM.insert({0, 0});
    UM.insert({1, 1});
    UM.insert({2, 1});

    cout << fibo(n) % M;

}

/*
-- 정답 코드 --
느낀점:
- O(logN) -> 문제의 크기를 절반씩 줄이자. 재귀를 사용하자.
-
 */