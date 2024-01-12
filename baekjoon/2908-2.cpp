//나머지 방식
#include <iostream>
using namespace std;

void swap(char* num);
void getMax(char* numA, char* numB);

int main(void) {
	char numA[4];
	char numB[4];
	cin >> numA >> numB;
	swap(numA);
	swap(numB);
	getMax(numA, numB);
	return 0;
}
void swap(char* num) {
	char temp = num[0];
	num[0] = num[2];
	num[2] = temp;
}
void getMax(char* numA, char* numB) {
	char* resultPointer = nullptr;
	for (int i{ 0 }; i < 3; i++) {
		if (numA[i] > numB[i]) {
			resultPointer = numA;
			break;
		}
		else if (numA[i] < numB[i]) {
			resultPointer = numB;
			break;
		}
	}
	cout << resultPointer;
}