#include <iostream>
using namespace std;
int gcd(int num1, int num2);
int lcd(const int& num1, const int& num2);

int main(void) {
    int a1, b1;
    int a2, b2;

    //입력
    cin >> a1 >> b1 >> a2 >> b2;

    //최소공배수 후 통분
    int lcdBefore = lcd(b1, b2);
    a1 *= (lcdBefore / b1);
    a2 *= (lcdBefore / b2);

    //분모가 같은 두 분수의 덧셈
    int a = a1 + a2;
    int b = lcdBefore;
    int gcdAfter = gcd(a,b); //기약분수

    cout << a / gcdAfter << " " << b / gcdAfter ;
    return 0;
}

int lcd(const int& num1, const int& num2) {
    int temp = gcd(num1, num2);
    return (num1 * num2) / temp;
}

int gcd(int num1, int num2) {
    if (num2 == 0) return num1;
    else return gcd(num2,num1 % num2);
}