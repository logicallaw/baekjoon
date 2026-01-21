#include <iostream>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  vector<int> I;
  vector<int> H;
  vector<int> diff;

  int N, M;
  cin >> N >> M;


  I.push_back(0);
  int sum = 0;
  for (int i = 0; i < N; i++) {
    int x;
    cin >> x;
    sum += x;
    I.push_back(x);
  }
  diff.push_back(sum);

  sort(I.begin(), I.end());

  for (int i = 1; i < N + 1; i++) {
    H.push_back(I[i] - I[i-1]);
  }

  int cnt = N;
  for (int i = 0; i < N; i++) {
    diff.push_back(diff.back() - (cnt--) * H[i]);
  }

  // for (auto& ele : diff) {
  //   cout << ele << " ";
  // }
  // cout << "==\n";

  // diff: 62 22 7 3 0
  // diff: 158 138 50 8 4 0

  cnt = N;

  int ans = 0;
  for (int i = 0; i < N; i++) {
    int cI = I[i];
    int cD = diff[i];

    if (i != (N-1) && !(cD >= M && M > diff[i+1])) {
      cnt--;
      continue;
    }

    // i = N-1
    ans = ((cD - M) / cnt) + cI;
    break;
  }

  cout << ans;
}