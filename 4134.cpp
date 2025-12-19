#include <iostream>
#include <cmath>
using namespace std;
void getPrime(long long& number);
bool isPrime(const long long& number);

int main(void) {
	unsigned int size;
	cin >> size;
	while (size--) {
		long long number;
		cin >> number;
		getPrime(number);
	}
	return 0;
}

bool isPrime(const long long& number) {
	if (number == 0 || number == 1)
		return false;

	//for문 범위는 숫자 number의 제곱근 + 1까지 반복한다.
	for (int i{ 2 }; i <= sqrt(number) + 1; i++) {
		//number != i는 숫자 2에 대한 예외처리
		if (number % i == 0 && number != i)
			return false;
	}

	return true;
}
void getPrime(long long& number) {
	while (!isPrime(number++)) {
		continue;
	}
	cout << number - 1 << endl;
}