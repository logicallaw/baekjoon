// 138 ms
#include <iostream>
#include <string>
#include <queue>
#include <chrono>

using namespace std;

const int MOD = 10000;

int D(int num) {
  num = (num * 2) % MOD;
  return num;
}

int S(int num) {
  num--;
  if (num == -1) {
    num = 9999;
  }
  return num;
}

string getString(int num) {
  string str = to_string(num);
  int lth = str.length();

  if (lth == 4) {
    return str;
  }
  if (lth == 3) {
    return ("0" + str);
  }
  if (lth == 2) {
    return ("00" + str);
  }
  return ("000" + str);
}

int L(int num) {
  string str = getString(num);
  string result = str.substr(1, 4) + str[0];
  return stoi(result);
}

int R(int num) {
  string str = getString(num);
  string result = str[3] + str.substr(0, 3);
  return stoi(result);
}

int main() {
  int T;
  cin >> T;
  auto start = chrono::high_resolution_clock::now();
  while (T--) {
    int A, B;
    cin >> A >> B;

    queue<pair<int, string>> Q;
    vector<bool> visited(10001, false);

    Q.push({A, ""});
    visited[A] = true;

    while (!Q.empty()) {
      pair<int, string> F = Q.front();
      Q.pop();

      if (F.first == B) {
        cout << F.second << "\n";
        break;
      }
      int d = D(F.first);
      int s = S(F.first);
      int l = L(F.first);
      int r = R(F.first);
      // cout << d << " " << s << " " << l << " " << r << "\n";

      if (!visited[d]) {
        Q.push({d, F.second + "D"});
        visited[d] = true;
      }
      if (!visited[s]) {
        Q.push({s, F.second + "S"});
        visited[s] = true;
      }
      if (!visited[l]) {
        Q.push({l, F.second + "L"});
        visited[l] = true;
      }
      if (!visited[r]) {
        Q.push({r, F.second + "R"});
        visited[r] = true;
      }
    }
  }
  auto end = chrono::high_resolution_clock::now();
  chrono::duration<double, milli> elapsed = end - start;
  cout << elapsed.count() << " ms\n";
}