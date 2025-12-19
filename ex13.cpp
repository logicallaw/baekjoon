#include <iostream>
#include <unordered_map>
using namespace std;
int main(void) {
    int n, k;
    cin >> n >> k;
    long long arr[100000] {};
    for(int i{ 0 }; i < n; i++) {
        cin >> arr[i];
    }
    unordered_map<long long, int> map;
    int result = 0;
    for(int i{ 0 }; i < n; i++) {
        if(k >= arr[i]) {
            result += map[k + arr[i]];
        } else {
            if(k != 0) {
                result += map[arr[i] + k];
                result += map[arr[i] - k];
            } else {
                result += map[arr[i]];
            }
        }
        map[arr[i]]++;
    }
    cout << result;
    return 0;
}
/*
5 2
6 6 4 9 8

5 0
4 4 4 4 4
 */