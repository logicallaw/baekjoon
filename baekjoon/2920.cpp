#include <iostream>
using namespace std;
int main(void) {
	int startNum;
	cin >> startNum;

	bool isMixed = false;

	if (startNum == 1) {
		int inputNum;
		for (int i{ 1 }; i < 8; i++) {
			cin >> inputNum;
			startNum++;
			if (startNum != inputNum) {
				isMixed = true;
				break;
			}
		}
		if (!isMixed)
			cout << "ascending";
	}
	else if (startNum == 8) {
		int inputNum;
		for (int i{ 1 }; i < 8; i++) {
			cin >> inputNum;
			startNum--;
			if (startNum != inputNum) {
				isMixed = true;
				break;
			}
		}
		if (!isMixed)
			cout << "descending";
	}
	else {
		isMixed = true;
	}
	if (isMixed)
		cout << "mixed";
}