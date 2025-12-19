//에라토스테네스의 채
#include <iostream>
#include <vector>
using namespace std;
void printPrime(int& idx1, int& idx2) {
	vector<bool> nums(idx2, true);
	for (int i{ 2 }; i <= idx2; i++) {
		if (nums[i - 1] == false)
			continue;
		/*
		i의 배수가 존재하면 false
		i의 배수의 개수 = idx2 / i
		*/
		for (int j{ 2 }; j <= idx2 / i; j++)
			nums[i * j - 1] = false;
	}
	for (int i{ idx1 }; i <= idx2; i++)
		if (nums[i - 1])
			cout << i << "\n"; //endl 사용하면 시간초과. 반드시 "\n" 사용.
}
int main(void) {
	int idx1, idx2;
	cin >> idx1 >> idx2;
	//1은 소수도 합성수도 아니다.
	if (idx1 == 1)
		printPrime(++idx1, idx2);
	else
		printPrime(idx1, idx2);
	return 0;
}