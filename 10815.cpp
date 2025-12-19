#include <iostream>
#include <unordered_set>
using namespace std;
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    unordered_set<int> us;
    for(int i{ 0 }; i < n; i++) {
        int x;
        cin >> x;
        us.insert(x);
    }
    int m;
    cin >> m;
    for(int i{ 0 }; i < m; i++) {
        int x;
        cin >> x;
        if(us.find(x) != us.end()) {
            printf("%d ", 1);
        } else {
            printf("%d ", 0);
        }
    }
    return 0;
}