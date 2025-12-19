#include <iostream>
using namespace std;

void printLcm(const long long int a, const long long int b);
int getGcm(long long int num1, long long int num2);

int main(void) {
	long long int a, b;
	cin >> a >> b;
	printLcm(a, b);
	return 0;
}

void printLcm(const long long int a, const long long int b) {
	long long int gcm = getGcm(a, b);
	cout << (a * b) / gcm << endl;
}

int getGcm(long long int num1, long long int num2) {
	if (num2 == 0) return num1;
	else return getGcm(num2, num1 % num2);
}