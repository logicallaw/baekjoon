#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    int n;
    cin >> n;
    vector<pair<long long, int>> v;
    for(int i{ 0 }; i < n; i++) {
        long long x1, x2;
        cin >> x1 >> x2;
        v.push_back(make_pair(x1, 1));
        v.push_back(make_pair(x2, -1));
    }
    sort(v.begin(), v.end());
    int sum_val = 0;
    int max = v[0].second;
    for(pair<long long, int>& p : v) {
        sum_val += p.second;
        max = (max < sum_val) ? sum_val : max;
    }
    cout << max;
    return 0;
}