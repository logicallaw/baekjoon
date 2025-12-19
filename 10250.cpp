#include <iostream>
using namespace std;
int main(void) {
	int t;
	int h, w, n;
	cin >> t;
	while (t--) {
		cin >> h >> w >> n;
		int y, x;
		//나머지가 0이면 꼭대기 층을 의미한다.
		if (n % h == 0) {
			y = h; //꼭대기 층
			x = n / h; 
		}
		//나머지가 0이 아니면 나머지가 층을 의미한다.
		else {
			y = n % h;
			x = n / h + 1;
		}
		if (x < 10)
			cout << y << "0" << x << "\n";
		else
			cout << y << x << "\n";
	}
	return 0;
}