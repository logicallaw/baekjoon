#include <iostream>
#include <string>
using namespace std;
int main(void) {
	string numA, numB;
	cin >> numA >> numB;
	for (int i{ 2 }; i >= 0; i--) {
		if (*(numA.begin() + i) > *(numB.begin() + i)) {
			cout << *(numA.begin() + 2) << *(numA.begin() + 1) << *(numA.begin());
			break;
		}
		else if (*(numA.begin() + i) < *(numB.begin() + i)) {
			cout << *(numB.begin() + 2) << *(numB.begin() + 1) << *(numB.begin());
			break;
		}
	}
	return 0;
}