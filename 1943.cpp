#include <iostream>
using namespace std;

void printLcm(const int& a, const int& b);
int getGcm(int num1, int num2);

int main(void) {
	int size;
	cin >> size;
	while (size--) {
		int a, b;
		cin >> a >> b;
		printLcm(a, b);
	}
	return 0;
}

void printLcm(const int& a, const int& b) {
	int gcm = getGcm(a, b);
	cout << (a * b) / gcm << endl;
}

int getGcm(int num1, int num2) {
	if (num2 == 0) return num1;
	else return getGcm(num2, num1 % num2);
}