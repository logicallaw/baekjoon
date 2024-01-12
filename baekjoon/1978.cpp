#include <iostream>
using namespace std;
int isPrime(const int& number);

int main(void) {
	int size;
	int result = 0;
	cin >> size;
	while(size--) {
		int temp;
		cin >> temp;
		result += isPrime(temp);
	}
	cout << result;
	return 0;
}

int isPrime(const int& number) {
	for (int i{ 2 }; i <= number / 2; i++)
		if (number % i == 0)
			return 0;
	if (number == 1) return 0;
	else return 1;
}