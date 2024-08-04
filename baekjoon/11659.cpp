#include <iostream>
#include <unordered_map>
using namespace std;
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    unordered_map<int, int> map;
    int sum = 0;
    for(int i{ 1 }; i <= n; i++) {
        int x;
        cin >> x;
        sum += x;
        map.insert({i, sum});
    }
    while(m--) {
        int i, j;
        cin >> i >> j;
        int result;
        if(i == 1) {
            result = map[j];
        } else {
            result = map[j] - map[i-1];
        }
        printf("%d\n", result);
    }
    return 0;
}