#include <iostream>
using namespace std;
bool isTriangle(const unsigned int& a, const unsigned int& b, const unsigned int& c);
void printType(const unsigned int& a, const unsigned int& b, const unsigned int& c);

int main(void) {
	unsigned int a, b, c;
	while (cin >> a >> b >> c && (a != 0)) {
		if (isTriangle(a, b, c))
			printType(a, b, c);
		else
			cout << "Invalid" << endl;
	}
	return 0;
}

bool isTriangle(const unsigned int& a, const unsigned int& b, const unsigned int& c) {
	return (a <= b) ? ((b <= c) ? ((c >= a + b) ? false : true) : ((b >= a + c) ? false : true)) : ((a <= c) ? ((c >= a + b) ? false : true) : ((a >= b + c) ? false : true));
}

void printType(const unsigned int& a, const unsigned int& b, const unsigned int& c) {
	if (a == b && b == c)
		cout << "Equilateral" << endl;
	else if (a == b || a == c || b == c)
		cout << "Isosceles" << endl;
	else
		cout << "Scalene" << endl;
}