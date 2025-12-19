#include <iostream>
#include <unordered_map>
using namespace std;
int main(void) {
    int n;
    long long k1, k2;
    cin >> n >> k1 >> k2;
    long long arr[100000] {};
    for(int i{ 0 }; i < n; i++) {
        cin >> arr[i];
    }

    int r1 = 0, r2 = 0;
    unordered_map<long long, int> m1;
    unordered_map<long long, int> m2;
    for(int i{ 0 }; i < n; i++) {
        long long d1 = k1 - arr[i];
        r1 += m1[d1];
        m1[arr[i]]++;

        long long d2 = k2 - arr[i];
        r2 += m2[d2];
        m2[arr[i]]++;
    }
    cout << r1 << " " << r2;
}
/*
5 12 17
6 6 4 9 8
 */