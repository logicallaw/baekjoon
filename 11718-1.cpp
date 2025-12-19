//C++-style
#include <iostream>
#include <string>
using namespace std;
int main(void) {
	string temp;
	while (getline(cin, temp, '\n'))
		cout << temp << endl;
	return 0;
}