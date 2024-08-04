#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    unordered_set<string> us;
    for(int i{ 0 }; i < n; i++) {
        string userInput;
        cin >> userInput;
        us.insert(userInput);
    }
    int cnt = 0;
    for(int i{ 0 }; i < m; i++) {
        string userInput;
        cin >> userInput;
        if(us.find(userInput) != us.end()) {
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}