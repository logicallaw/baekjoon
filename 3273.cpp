#include <iostream>
#include <unordered_map>
using namespace std;
int main(void) {
    int n;
    cin >> n;
    int arr[100000] {};
    unordered_map<int, int> map;

    for(int i{ 0 }; i < n; i++) {
        cin >> arr[i];
    }

    int k;
    cin >> k;

    int result = 0;
    for(int i{ 0 }; i < n; i++) {
        int diff = k - arr[i];
        if(map.find(diff) != map.end()) {
            result += map[diff];
        }
        if(map.find(arr[i]) == map.end()) {
            map.insert({arr[i], 1});
        } else {
            map[arr[i]]++;
        }
    }
    cout << result;

    return 0;
}