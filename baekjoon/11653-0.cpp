#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
int main(void) {
	vector<char*> str;
	for (int i{ 0 }; i < 5; i++) {
		char* temp = new char[16];
		cin >> temp;
		str.push_back(temp);	
	}

	for (int i{ 0 }; i < strlen(str[0]) + 1; i++) {
		for (int j{ 0 }; j < 5; j++) {
			cout << str[j][i];
		}
	}

	for (int i{ 0 }; i < str.size(); i++)
		delete[] str[i];
	return 0;
}
