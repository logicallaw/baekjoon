#include <iostream>
using namespace std;
void getOther(int p[]);
void getOther(int p[]) {
	if (p[0] == p[1])
		cout << p[2] << " ";
	else if (p[0] == p[2])
		cout << p[1] << " ";
	else
		cout << p[0] << " ";
}
int main(void) {
	int x[3];
	int y[3];
	for (int i{ 0 }; i < 3; i++) 
		cin >> x[i] >> y[i];
	getOther(x);
	getOther(y);
	return 0;
}