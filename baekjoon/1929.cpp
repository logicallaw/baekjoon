//�����佺�׳׽��� ä
#include <iostream>
#include <vector>
using namespace std;
void printPrime(int& idx1, int& idx2) {
	vector<bool> nums(idx2, true);
	for (int i{ 2 }; i <= idx2; i++) {
		if (nums[i - 1] == false)
			continue;
		/*
		i�� ����� �����ϸ� false
		i�� ����� ���� = idx2 / i
		*/
		for (int j{ 2 }; j <= idx2 / i; j++)
			nums[i * j - 1] = false;
	}
	for (int i{ idx1 }; i <= idx2; i++)
		if (nums[i - 1])
			cout << i << "\n"; //endl ����ϸ� �ð��ʰ�. �ݵ�� "\n" ���.
}
int main(void) {
	int idx1, idx2;
	cin >> idx1 >> idx2;
	//1�� �Ҽ��� �ռ����� �ƴϴ�.
	if (idx1 == 1)
		printPrime(++idx1, idx2);
	else
		printPrime(idx1, idx2);
	return 0;
}