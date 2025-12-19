#include <iostream>
using namespace std;
void progress(int angles[], const int& SIZE);

int main(void) {
	const int SIZE = 3;
	int angles[SIZE];
	for (int& angle : angles)
		cin >> angle;
	progress(angles, SIZE);
	return 0;
}

void progress(int angles[], const int& SIZE) {
	int sum = 0;
	for (int i{ 0 }; i < SIZE; i++)
		sum += angles[i];
	if (sum != 180)
		cout << "Error";
	else
	{
		if (angles[0] == angles[1] && angles[1] == angles[2])
			cout << "Equilateral";
		else if (angles[0] == angles[1] || angles[0] == angles[2] || angles[1] == angles[2])
			cout << "Isosceles";
		else
			cout << "Scalene";
	}
}