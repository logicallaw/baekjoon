//동적메모리할당
#include <iostream>
using namespace std;
void isPerfectNumber(const int& num);

int main(void) {
	int temp;
	while (cin >> temp && temp != -1)
		isPerfectNumber(temp);
	return 0;
}

void isPerfectNumber(const int& num) {
	int sum = 0;
	int* divisors = new int[num / 2];
	int cntDivisors = 0;
	for (int i{ 1 }; i < num; i++)
		if (num % i == 0) {
			sum += i;
			divisors[cntDivisors++] = i;
		}
	if (sum == num) {
		cout << num << " = ";
		for (int i{ 0 }; i < cntDivisors; i++) {
			if (i == cntDivisors - 1)
			{
				cout << divisors[i] << endl;
				break;
			}
			else
				cout << divisors[i] << " + ";
		}
	}
	else
		cout << num << " is NOT perfect." << endl;
	delete[] divisors;
}