#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cstring>
using namespace std;
bool comp(string a, string b) {
    if(strcmp(a.c_str(), b.c_str()) < 0) {
        return true;
    }
    else {
        return false;
    }
}
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    unordered_map<int, vector<string>> m1;
    unordered_map<string, int> m2;
    int max = 1;
    for(int i{ 0 }; i < n; i++) {
        string book;
        cin >> book;
        if(m2.find(book) != m2.end()) {
            m2[book]++;
            max = (max < m2[book]) ? m2[book] : max;
        } else {
            m2.insert({book, 1});
        }
        if(m1.find(m2[book]) != m1.end()) {
            m1[m2[book]].push_back(book);
        } else {
            vector<string> v;
            v.push_back(book);
            m1.insert({max, v});
        }
    }
    sort(m1[max].begin(), m1[max].end(), comp);
    cout << m1[max][0];
    return 0;
}