#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int A, B, C;
  cin >> A >> B >> C;

  cout << A + B - C << "\n";
  string a = std::to_string(A);
  string b = std::to_string(B);
  string ab = a + b;
  int ab_int = stoi(ab);
  cout << ab_int - C;
}