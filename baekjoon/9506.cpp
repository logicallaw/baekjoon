//vector
#include <iostream>
#include <vector>
using namespace std;
void isPerfectNumber(int& num);

int main(void) {
	int temp;
	while (cin >> temp && temp != -1) 
		isPerfectNumber(temp);
	return 0;
}

void isPerfectNumber(int& num) {
	int sum = 0;
	vector <int> divisors;
	for (int i{ 1 }; i < num; i++)
		if (num % i == 0) {
			sum += i;
			divisors.push_back(i);
		}
	if (sum == num) {
		cout << num << " = ";
		for (int i{ 0 }; i < divisors.size(); i++) {
			if (i == divisors.size() - 1)
			{
				cout << divisors[i] << endl;
				break;
			}
			else
				cout << divisors[i] << " + ";
		}
	}
	else
		cout << num << " is NOT perfect." << endl;
}