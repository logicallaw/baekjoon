#include <iostream>
#include <cstring>
using namespace std;
int main(void) {
	char numbers[16];
	cin >> numbers;

	int result = 0;
	for (int i{ 0 }; i < strlen(numbers) + 1; i++) {
		int temp = numbers[i] - 'A';
		if (temp >= 27)
			result += 9;
		else if (temp >= 24)
			result += 8;
		else if (temp >= 21)
			result += 7;
		else if (temp >= 18)
			result += 6;
		else if (temp >= 15)
			result += 5;
		else if (temp >= 12)
			result += 4;
		else if (temp >= 9)
			result += 3;
		else if (temp >= 6)
			result += 2;
		else if (temp >= 3)
			result += 1;
		result += 2;
	}
	cout << result;
	return 0;
}