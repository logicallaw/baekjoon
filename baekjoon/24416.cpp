#include <iostream>
using namespace std;
int fib(int);
int fibonacci(int);

int cnt1 = 0;
int cnt2 = 0;
int memo[41] { };
int main()
{
    int n;
    cin >> n;
    fib(n);
    fibonacci(n);
    cout << cnt1 << " " << cnt2;
    return 0;
}
int fib(int n) {
    if(n <= 2) {
        cnt1++;
        return 1;
    } else {
        return fib(n-1) + fib(n-2);
    }
}
int fibonacci(int n) {
    if(memo[n] != 0) {
        return memo[n];
    }
    if(n <= 2) {
        memo[n] = 1;
    } else {
        cnt2++;
        memo[n] = fibonacci(n-1) + fibonacci(n-2);
    }
    return memo[n];
}