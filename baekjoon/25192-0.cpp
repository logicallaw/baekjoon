#include <iostream>
#include <vector>
using namespace std;
int main(void) {
	int size;
	cin >> size;
	vector<char*> name;
	char enter;
	cin >> enter;
	size--;
	int counter = 0;
	while (size--) {
		char* temp = new char[21];
		cin >> temp;
		if (name.size() == 0) {
			name.push_back(temp);
			counter++;
		}
		for (int i{ 0 }; i < name.size(); i++) {
			if (name[i] != temp) {
				name.push_back(temp);
				counter++;
			}
		}
		if (temp == "Enter") {
			for (int i{ 0 }; i < name.size(); i++) {
				name.pop_back();
			}
		}
	}
	cout << counter;
	for (int i{ 0 }; i < name.size(); i++)
		delete[] name[i];
	return 0;
}