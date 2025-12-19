#include <iostream>
#include <unordered_map>
using namespace std;
int main(void) {
    unordered_map<int, int> map;
    for(int i{ 9 }; i >= 0; i--) {
        map.insert({i, 0});
    }
    string num;
    cin >> num;
    for(int i{ 0 }; i < num.size(); i++) {
        char c = num[i];
        int int_c = c - '0';
        map[int_c]++;
    }
    for(int i{ 9 }; i >= 0; i--) {
        int cnt = map[i];
        while(cnt--) {
            cout << i;
        }
    }
    return 0;
}