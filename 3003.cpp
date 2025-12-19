#include <iostream>
using namespace std;
int main(void) {
	int nums[6]{ 1,1,2,2,2,8 };
	int temp;
	for (const int& num : nums) {
		cin >> temp;
		cout << num - temp << " ";
	}
	return 0;
}