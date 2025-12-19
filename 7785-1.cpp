#include <iostream>
#include <map>
using namespace std;
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    map<string, string, greater<string>> m;
    for(int i{ 0 }; i < n; i++) {
        string user, log;
        cin >> user >> log;
        if(log == "enter") {
            m.insert({user, log});
        } else {
            m.erase(user);
        }
    }
    for(map<string, string, greater<string>>::iterator it = m.begin(); it != m.end(); it++) {
        printf("%s\n", it->first.c_str());
    }
    return 0;
}