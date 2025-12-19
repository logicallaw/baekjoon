#include <iostream>
using namespace std;
int main(void) {
	int size;
	cin >> size;
	int x, y;
	cin >> x >> y;

	//default:x, y
	int minX = x, maxX = x;
	int minY = y, maxY = y;

	for (int i{ 1 }; i < size; i++) {
		cin >> x >> y;
		minX = (minX >= x) ? x : minX;
		maxX = (maxX <= x) ? x : maxX;
		minY = (minY >= y) ? y : minY;
		maxY = (maxY <= y) ? y : maxY;
	}

	cout << (maxX - minX) * (maxY - minY);
	return 0;
}