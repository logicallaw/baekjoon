#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> keys;
    unordered_map<int, int> map;
    //O(n) time
    while(n--) {
        int x;
        cin >> x;
        if(map.find(x) == map.end()) {
            map.insert({x, 1});
            keys.push_back(x);
        } else {
            map[x] += 1;
        }
    }
    //O(nlogn) time
    sort(keys.begin(), keys.end());

    for(const int& key : keys) {
        int cnt = map[key];
        while(cnt--){
            printf("%d\n", key);
        }
    }

    return 0;
}