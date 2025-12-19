#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
int main(void) {
    string userInput;
    cin >> userInput;
    unordered_map<char, int> map;
    vector<char> mapKeys;
    for(int i{ 0 }; i < userInput.length(); i++) {
        char c = userInput.at(i);
        //??? ??
        if(c >= 'A' && c <= 'Z') {
            c += 32;
        }
        if(map.find(c) == map.end()) {
            map.insert({c, 1});
            mapKeys.push_back(c);
        } else {
            map[c] += 1;
        }
    }
    char result = mapKeys[0];
    if(map.size() == 1) {
        result -= 32; //??? ??
        cout << result;
    } else {
        int max = map[mapKeys[0]];
        int maxCnt = 1;
        for(int i{ 1 }; i < map.size(); i++) {
            char key = mapKeys[i];
            int value = map[key];
            if(value > max) {
                max = value;
                maxCnt = 1;
                result = mapKeys[i];
            } else if (value == max) {
                maxCnt++;
            }
        }
        if(maxCnt > 1) {
            cout << "?";
        } else {
            result -= 32;
            cout << result;
        }
    }
    return 0;
}