#include <iostream>
#include <vector>
using namespace std;

vector<int> edges[100000 + 1];
bool visited[100000 + 1] {};
int parent[100000 + 1] {};

void dfs(int x) {
    for(const int y : edges[x]) {
        if(!visited[y]) {
            visited[y] = true;
            parent[y] = x;
            dfs(y);
        }
    }
}

int main(void) {
    int n;
    cin >> n;
    for(int i{ 0 }; i < (n-1); i++) {
        int x, y;
        cin >> x >> y;
        edges[x].push_back(y);
        edges[y].push_back(x);
    }
    visited[1] = true;
    dfs(1);
    for(int i{ 2 }; i <= n; i++) {
        printf("%d\n", parent[i]);
    }
    return 0;
}