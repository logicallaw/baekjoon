#include <iostream>
using namespace std;
void reverseNum(char* num);
void getMax(char* numA, char* numB);

int main(void) {
	char numA[4];
	char numB[4];
	cin >> numA >> numB;
	reverseNum(numA);
	reverseNum(numB);
	getMax(numA, numB);

	return 0;
}
void reverseNum(char* num) {
	char temp = num[0];
	num[0] = num[2];
	num[2] = temp;
}
void getMax(char* numA, char* numB) {
	char* resultPointer = nullptr;
	for (int i{ 0 }; i < 3; i++) {
		//아스키 코드값을 참고해, char 비교가 아닌 int형으로 비교합니다.
		if ((numA[i] - '0') > (numB[i] - '0')) {
			resultPointer = numA;
			break;
		}
		else if ((numA[i] - '0') < (numB[i] - '0')) {
			resultPointer = numB;
			break;
		}
	}
	cout << resultPointer;
}