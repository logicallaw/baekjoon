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
		//�ƽ�Ű �ڵ尪�� ������, char �񱳰� �ƴ� int������ ���մϴ�.
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