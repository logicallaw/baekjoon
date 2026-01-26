#include <iostream>
#include <cmath>
#include <cstring>
#include <queue>

using namespace std;

const int MOD = 10000;
//
// struct Node {
//   int num[4];
//   int carry[4];
//
//   Node(int N) {
//     memset(num, 0x00, sizeof(num));
//     memset(carry, 0x00, sizeof(carry));
//     setNum(N);
//   }
//
//   void L() {
//     int tmp = num[0];
//     for (int i = 0; i < 3; i++) {
//       num[i] = num[i+1];
//     }
//     num[3] = tmp;
//   }
//
//   void R() {
//     int tmp = num[3];
//     for (int i = 3; i >= 1; i--) {
//       num[i] = num[i-1];
//     }
//     num[0] = tmp;
//   }
//
//   int D() {
//     // memset(carry, 0x00, sizeof(carry));
//     // for (int i = 3; i >= 0; i--) {
//     //   num[i] = (num[i] * 2) + carry[i];
//     //   if (num[i] > 9) {
//     //     if (i != 0) {
//     //       carry[i-1] = num[i] / 10;
//     //       num[i] %= 10;
//     //     } else {
//     //       num[i] %= 10;
//     //     }
//     //   }
//     // }
//
//   }
//
//   int S() {
//     int N = 0;
//     for (int i = 0; i < 4; i++) {
//       int square = pow(10, 3-i);
//       N += num[i] * square;
//     }
//
//     N -= 1;
//     if (N == -1) N = 9999;
//     return N;
//   }
//
//   void makeNum(int st, int target) {
//     for (int i = st; i < 4; i++) {
//       int square = pow(10, 3-i);
//       num[i] = target / square;
//       target %= square;
//     }
//   }
//
//   void setNum(int N) {
//     memset(num, 0x00, sizeof(num));
//     memset(carry, 0x00, sizeof(carry));
//
//     if (N >= 1000) {
//       makeNum(0, N);
//       return;
//     }
//     if (N >= 100) {
//       makeNum(1, N);
//       return;
//     }
//     if (N >= 10) {
//       makeNum(2, N);
//       return;
//     }
//
//     makeNum(3, N);
//   }
//
//   int getNum() {
//     int total = 0;
//     for (int i = 0; i < 4; i++) {
//       int square = pow(10, 3-i);
//       total += num[i] * square;
//     }
//     return total;
//   }
// };


int D(int n) {
  n *= 2;
  return (n % MOD);
}

int S(int n) {
  n -= 1;
  return (n == -1) ? 9999 : n;
}

int LL(int st, int target) {
  int num[4]{};

  for (int i = st; i < 4; i++) {
    int square = pow(10, 3-i);
    num[i] = target / square;
    target %= square;
  }

  // for (int i = 0; i < 4; i++) {
  //   cout << num[i] << " ";
  // }
  // cout << "\n";

  int tmp = num[0];
  for (int i = 0; i < 3; i++) {
    num[i] = num[i+1];
  }
  num[3] = tmp;

  // for (int i = 0; i < 4; i++) {
  //   cout << num[i] << " ";
  // }
  // cout << "\n";

  int total = 0;
  for (int i = 0; i < 4; i++) {
    int square = pow(10, 3-i);
    total += num[i] * square;
  }
  return total;
}

int L(int N) {
  if (N >= 1000) {
    return LL(0, N);
  }
  if (N >= 100) {
    return LL(1, N);
  }
  if (N >= 10) {
    return LL(2, N);
  }
  return LL(3, N);
}

int RR(int st, int target) {
  int num[4]{};

  for (int i = st; i < 4; i++) {
    int square = pow(10, 3-i);
    num[i] = target / square;
    target %= square;
  }

  int tmp = num[3];
  for (int i = 3; i >= 1; i--) {
    num[i] = num[i-1];
  }
  num[0] = tmp;

  int total = 0;
  for (int i = 0; i < 4; i++) {
    int square = pow(10, 3-i);
    total += num[i] * square;
  }
  return total;
}


int R(int N) {
  if (N >= 1000) {
    return RR(0, N);
  }
  if (N >= 100) {
    return RR(1, N);
  }
  if (N >= 10) {
    return RR(2, N);
  }
  return RR(3, N);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int T;
  cin >> T;

  // cout << L(T) << "\n";
  // return 0;

  while (T--) {
    int A, B;
    cin >> A >> B;

    queue<pair<int, string>> Q;
    Q.emplace(A, "");

    while (!Q.empty()) {
      pair<int, string> F = Q.front();
      Q.pop();

      if (F.first == B) {
        cout << F.second << "\n";
        break;
      }

      Q.push({D(F.first), F.second + "D"});
      Q.push({S(F.first), F.second + "S"});
      Q.push({L(F.first), F.second + "L"});
      Q.push({R(F.first), F.second + "R"});
    }
  }
}