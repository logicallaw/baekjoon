#include <iostream>
#include <unordered_map>
using namespace std;
int main(void) {
    int n;
    cin >> n;
    int groupWord = 0;
    while(n--) {
        string userInput;
        cin >> userInput;
        unordered_map<char, int> map;
        bool isPass = false;
        for(int i{ 0 }; i < userInput.length(); i++) {
            if(isPass) break;
            char c = userInput[i];
            if(map.find(c) == map.end()) {
                map.insert({c, i});
            } else {
                if(map[c] != (i - 1)) {
                    isPass = true;
                } else {
                    map[c] = i;
                }
            }
        }
        if(!isPass) {
            groupWord++;
        }
    }
    cout << groupWord;
}