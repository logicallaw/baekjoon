#include <iostream>
using namespace std;

int main() {
    int a = !2;
    int b = !1;
    int c = !0;

    int d = 0 || 0;
    cout << a << " " << b << " " << c << " " << d;
}