#include <iostream>
using namespace std;
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	unsigned int a, b, c;
	cin >> a >> b >> c;
	long long result = a * b * c;
	unsigned int nums[10]{};
	while (result != 0) {
		nums[result % 10]++;
		result /= 10;
	}
	for (const int& num : nums)
		cout << num << "\n";
	return 0;
}