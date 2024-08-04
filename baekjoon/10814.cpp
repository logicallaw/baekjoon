#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> keys;
    unordered_map<int, vector<string>*> map;
    int n;
    cin >> n;
    for(int i{ 0 }; i < n; i++) {
        int age;
        string name;
        cin >> age >> name;
        if(map.find(age) == map.end()) {
            keys.push_back(age);
            vector<string>* temp = new vector<string>;
            temp->push_back(name);
            map.insert({age, temp});
        } else {
            map[age]->push_back(name);
        }
    }
    sort(keys.begin(), keys.end());
    for(int i{ 0 }; i < keys.size(); i++) {
        int key = keys[i];
        vector<string>* temp = map[key];
        for(int j{ 0 }; j < temp->size(); j++) {
            printf("%d %s\n", key, temp->at(j).c_str());
        }
    }

    return 0;
}