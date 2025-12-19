#include <iostream>
using namespace std;
//가장 긴 변:max, 나머지 두 변:x, y
void getRound(const int& max, const int& x, const int& y);

int main(void) {
	int a, b, c;
	cin >> a >> b >> c;
	(a <= b)
		? ((b <= c) ? getRound(c, a, b) : getRound(b, a, c))
		: ((a <= c) ? getRound(c, a, b) : getRound(a, b, c));
}

void getRound(const int& max, const int& x, const int& y) {
	if (x + y > max)
		cout << x + y + max;
	else //가장 긴 변의 길이를 삼각형 성립되도록 최소로 줄여서 삼각형 둘레의 최댓값을 구한다.
		cout << x + y + (x + y - 1); 
}