#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> keys;
    unordered_map<int, vector<int>*> map;
    int n;
    cin >> n;
    for(int i{ 0 }; i < n; i++) {
        int x, y;
        cin >> x >> y;
        if(map.find(y) == map.end()) {
            keys.push_back(y);
            vector<int>* temp = new vector<int>;
            temp->push_back(x);
            map.insert({y, temp});
        } else {
            map[y]->push_back(x);
        }
    }
    sort(keys.begin(), keys.end());
    for(int i{ 0 }; i < keys.size(); i++) {
        int key = keys[i];
        vector<int>* temp = map[key];
        sort(temp->begin(), temp->end());
        for(int j{ 0 }; j < temp->size(); j++) {
            printf("%d %d\n", temp->at(j), key);
        }
    }
    return 0;
}