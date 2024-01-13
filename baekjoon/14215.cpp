#include <iostream>
using namespace std;
//���� �� ��:max, ������ �� ��:x, y
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
	else //���� �� ���� ���̸� �ﰢ�� �����ǵ��� �ּҷ� �ٿ��� �ﰢ�� �ѷ��� �ִ��� ���Ѵ�.
		cout << x + y + (x + y - 1); 
}