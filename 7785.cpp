#include <iostream>
#include <unordered_set>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;
bool comp(string a, string b) {
    if(strcmp(a.c_str(), b.c_str()) > 0) {
        return true;
    } else {
        return false;
    }
}
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    unordered_set<string> us;
    for(int i{ 0 }; i < n; i++) {
        string name, log;
        cin >> name >> log;
        if(log == "enter") {
            us.insert(name);
        } else { // log == "leave"
            us.erase(name);
        }
    }
    vector<string> v;
    for(const string& ele : us) {
        v.push_back(ele);
    }
    sort(v.begin(), v.end(), comp);
    for(const string& ele : v) {
        printf("%s\n", ele.c_str());
    }
    return 0;
}