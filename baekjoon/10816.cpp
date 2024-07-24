#include <iostream>
#include <unordered_map>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    unordered_map<int, int> map;
    while(n--) {
        int x;
        cin >> x;
        map[x]++;
    }
    int m;
    cin >> m;
    while(m--) {
        int x;
        cin >> x;
        cout << map[x] << " ";
    }
    return 0;
}