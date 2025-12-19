#include <iostream>
#include <vector>
using namespace std;

int isPrime(const int& idx, vector<int>& primes);

int main(void) {
	int idx1, idx2;
	cin >> idx1 >> idx2;

	int sum = 0;
	vector<int> primes;

	//idx1부터 idx2까지 범위에서 소수를 검증합니다.
	for (; idx1 <= idx2; idx1++) {
		//만약, idx1이 소수라면, sum과 primes 배열의 변화가 있습니다.
		sum += isPrime(idx1, primes);
	}

	//결과 출력문 논리
	if (sum == 0) { //해당 범위에서 isPrime함수가 항상 0을 리턴한 결과.
		cout << -1;
	}
	else { //소수가 존재하며, primes 소수 배열을 순회하며, 소수 중 최솟값을 찾습니다.
		int min = primes[0]; 
		for (int i{ 1 }; i < primes.size(); i++)
			min = (min >= primes[i]) ? primes[i] : min;
		cout << sum << endl << min;
	}
	return 0;
}

int isPrime(const int& idx, vector<int>& primes) {
	for (int i{ 2 }; i <= idx / 2; i++) {
		if (idx % i == 0)
			return 0;
	}
	if (idx == 1) return 0;
	else {
		primes.push_back(idx);
		return idx;
	}
}