#include <iostream>
#include <cstring>
using namespace std;
int main(void) {
	char numA[4];
	char numB[4];
	cin >> numA >> numB;
	/*
	수를 비교합니다.
	이때, 아스키 코드값이 클수록 정수값도 크기 때문에,
	아스키 코드값으로 비교해도 무관합니다.
	*/
	for (int i{ 2 }; i >= 0; i--) {
		if (numA[i] > numB[i]) {
			cout << numA[2] << numA[1] << numA[0];
			break;
		}
		else if (numA[i] < numB[i])
		{
			cout << numB[2] << numB[1] << numB[0];
			break;
		}
		/*
		else { continue; } //numA[i] == numB[i]
		*/
	}
	return 0;
}