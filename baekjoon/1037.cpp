#include <iostream>
using namespace std;
int main(void) {
	unsigned int size;
	cin >> size;
	unsigned int temp;
	cin >> temp;
	/*
	N�� ���� �ռ���(����� ������ 3 �̻�)�̸�,
	N�� ��� 1�� N�� ������ ����� �߿���
	���� ���� ���� ū ���� ���ϸ�
	N�� ���� �� �ְ� �ȴ�.
	*/
	unsigned int min = temp, max = temp;
	for (int i{ 1 }; i < size; i++) {
		cin >> temp;
		min = (min > temp) ? temp : min;
		max = (max < temp) ? temp : max;
	}
	cout << min * max;
	return 0;
}