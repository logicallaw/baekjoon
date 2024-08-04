#include <iostream>
#include <queue>
#include <vector>
#include <functional>
using namespace std;
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for(int i{ 0 }; i < n; i++) {
        int x;
        cin >> x;
        if(x != 0) {
            int abX = (x < 0) ? -x : x;
            pq.push(make_pair(abX, x));
        } else {
            if(pq.empty()) {
                printf("0\n");
            } else {
                pair<int, int> min = pq.top();
                printf("%d\n", min.second);
                pq.pop();
            }
        }
    }
    return 0;
}