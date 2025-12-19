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
        if(map.find(x) == map.end()) {
            keys.push_back(x);
            vector<int>* temp = new vector<int>;
            temp->push_back(y);
            map.insert({x, temp});
        } else {
            map[x]->push_back(y);
        }
    }
    sort(keys.begin(), keys.end());
    for(int i{ 0 }; i < keys.size(); i++) {
        int key = keys[i];
        vector<int>* temp = map[key];
        sort(temp->begin(), temp->end());
        for(int j{ 0 }; j < temp->size(); j++) {
            printf("%d %d\n", key, temp->at(j));
        }
    }
    return 0;
}