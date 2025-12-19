#include <iostream>
#include <string>
using namespace std;
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int size;
	cin >> size;
	while (size--) {
		string word;
		cin >> word;
		int sum = 0;
		int counter = 0;
		for (int i{ 0 }; i < word.length(); i++) {
			if (*(word.begin() + i) == 'O') {
				counter++;
				sum += counter;
			}
			else {
				counter = 0;
			}
		}
		cout << sum << "\n";
	}
	return 0;
}