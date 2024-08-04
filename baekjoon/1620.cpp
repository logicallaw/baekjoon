#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    unordered_map<string, int> um1;
    unordered_map<int, string> um2;
    for(int i{ 1 }; i <= n; i++) {
        string s;
        cin >> s;
        um1.insert({s, i});
        um2.insert({i, s});
    }
    for(int i{ 0 }; i < m; i++) {
        string s;
        cin >> s;
        char firstChar = s[0];
        if(firstChar >= 'A' && firstChar <= 'Z') {
            printf("%d\n", um1[s]);
        } else {
            printf("%s\n", um2[stoi(s)].c_str());
        }
    }
}