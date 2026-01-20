#include <iostream>
using namespace std;

const int MOD = 10'007;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;

  if (n == 1 || n == 2) {
    cout << n;
    return 0;
  }

  int a1 = 1;
  int a2 = 2;
  int a3 = 0;
  for (int i = 3; i <= n; i++) {
    a3 = (a1 + a2) % MOD;
    a1 = a2 % MOD;
    a2 = a3 % MOD;
  }
  cout << a3;
}

/*
이 문제는 신기함.

이 문제를 풀면서 나의 생각 전개 흐름:
1. n=5일 때까지 직접 구함
2. 2x1 타일을 사용하기 위해서는 2개를 동시에 써야함 => 2x2 타일로 치환
3. 다시 n을 1부터 증가시키면서 큰 타일(2x2)과 작은 타일(1x2)의 조합을 직접 구함 => 조합의 규칙성을 발견
하지만, 조합의 규칙성을 이용한 풀이는 nCr 계산 과정에서 팩토리알 계산에서 시간 초과가 되는 문제점
4. n을 짝수 또는 홀수일 때 규칙성을 직접 확인
5. n을 짝수와 홀수일 때 같이 놓고 합의 규칙성이 있는지 확인 => 피보나치와 같은 규칙성이 존재 => n이 최대 1,000이라서 O(N)에 계산 가능!
 */