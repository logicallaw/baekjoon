#include <iostream>
#include <cstring>
using namespace std;
int main(void) {
	char numA[4];
	char numB[4];
	cin >> numA >> numB;
	/*
	���� ���մϴ�.
	�̶�, �ƽ�Ű �ڵ尪�� Ŭ���� �������� ũ�� ������,
	�ƽ�Ű �ڵ尪���� ���ص� �����մϴ�.
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