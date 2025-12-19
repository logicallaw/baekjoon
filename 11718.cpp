//C-style
#include <iostream>
#include <cstring>
using namespace std;
int main(void) {
	char temp[101];
	while (cin.getline(temp, sizeof(temp), '\n'))
		cout << temp << endl;
	return 0;
}