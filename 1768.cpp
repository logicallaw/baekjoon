#include <iostream>
#include <unordered_set>
#include <queue>
#include <vector>
using namespace std;
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    unordered_set<string> us;
    priority_queue<string, vector<string>, greater<string>> pq;
    cin >> n >> m;
    for(int i{ 0 }; i < n; i++) {
        string user;
        cin >> user;
        us.insert(user);
    }
    for(int i{ 0 }; i < m; i++) {
        string user;
        cin >> user;
        if(us.find(user) != us.end()) {
            pq.push(user);
        }
    }
    printf("%d\n", pq.size());
    while(!pq.empty()) {
        printf("%s\n", pq.top().c_str());
        pq.pop();
    }
    return 0;
}