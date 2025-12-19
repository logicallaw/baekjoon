#include <iostream>
#include <queue>
#include <vector>
#include <functional>
using namespace std;
int main(void) {
    int n;
    cin >> n;
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i{ 0 }; i < n; i++) {
        int x;
        cin >> x;
        pq.push(x);
    }
    int cnt = 0;
    while(pq.size() > 1) {
        int x = pq.top();
        pq.pop();
        int y = pq.top();
        pq.pop();
        int r = x + y;
        cnt += r;
        pq.push(r);
    }
    printf("%d", cnt);
    return 0;
}