#include <vector>
#include <iostream>
using namespace std;

const int SIZE = 51;
vector<int> tree[SIZE];
int n, root, delNode, leaf = 0;

void dfs(int);

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x == -1) {
            root = i;
        } else {
            tree[x].push_back(i);
        }
    }
    cin >> delNode;
    if (delNode != root) {
        dfs(root);
    }
    cout << leaf;
    return 0;
}

void dfs(int idx) {
    if(idx == delNode) {
        leaf++;
    } else {
        bool hasValidChild = false;
        for(int child : tree[idx]) {
            if(child != delNode) {
                hasValidChild = true;
                dfs(child);
            }
        }
        if(!hasValidChild) {
            leaf++;
        }
    }
}