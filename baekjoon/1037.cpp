#include <iostream>
using namespace std;
int main(void) {
	unsigned int size;
	cin >> size;
	unsigned int temp;
	cin >> temp;
	/*
	N의 값은 합성수(약수의 개수가 3 이상)이며,
	N의 약수 1과 N을 제외한 약수들 중에서
	가장 작은 값과 큰 값을 곱하면
	N을 구할 수 있게 된다.
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