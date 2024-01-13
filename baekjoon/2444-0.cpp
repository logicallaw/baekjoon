#include <iostream>
using namespace std;
int main(void) {
	int n;
	cin >> n;

	const int SIZE = 2 * n - 1;
	for (int i{ 1 }; i <= SIZE; i++) {
		//°ø¹é
		for (int j{ 0 }; j < n - i; j++) {
			cout << " ";
		}
		//º°
		for (int k{ 0 }; (k < 2 * i - 1) && (i <= n); k++) {
			cout << "*";
		}
		for (int j{ 0 }; j < i - n; i++) {
			cout << " ";
		}
		for (int k{ 0 }; (k < -2 * i + 19) && (i > n); k++) {
			cout << "*";
		}
		cout << endl;
	}
	return 0;
}