#include <iostream>
#include <string>
using namespace std;
int main(void) {
	string word;
	cin >> word;
	int time = 0;
	for (int i{ 0 }; i < word.length(); i++) {
		int temp = *(word.begin() + i) - 'A';
		if (temp >= 26)
			time += 11;
		else if (temp >= 22)
			time += 10;
		else if (temp >= 19)
			time += 9;
		else if (temp >= 15)
			time += 8;
		else if (temp >= 12)
			time += 7;
		else if (temp >= 9)
			time += 6;
		else if (temp >= 6)
			time += 5;
		else if (temp >= 3)
			time += 4;
		else
			time += 3;
	}
	cout << time;
	return 0;
}