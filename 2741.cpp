#include <iostream>
using namespace std;
int main(void) {
	unsigned int n;
	cin >> n;
	unsigned int counter = 1;
	while (counter <= n)
		cout << counter++ << "\n";
	return 0;
}