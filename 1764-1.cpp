#include <iostream>
#include <map>
using namespace std;
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    map<string, bool> sm;
    for(int i{ 0 }; i < n; i++) {
        string s;
        cin >> s;
        sm.insert({s, false});
    }
    int size = 0;
    for(int i{ 0 }; i < m; i++) {
        string s;
        cin >> s;
        if(sm.find(s) != sm.end()) {
            sm[s] = true;
            size++;
        }
    }
    printf("%d\n", size);
    for(map<string, bool>::iterator it = sm.begin(); it != sm.end(); it++) {
        if(it->second) {
            printf("%s\n", it->first.c_str());
        }
    }
    return 0;
}