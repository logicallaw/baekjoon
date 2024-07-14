#include <iostream>
#include <vector>
using namespace std;
class MinHeap{
private:
    vector<int> v;
    int lastIndex;
public:
    MinHeap(int size) {
        v.push_back(-1);
        lastIndex = 0;
        for(int i{ 0 }; i < size; i++) {
            int x;
            cin >> x;
            insert(x);
        }
    }
    int size() const { return lastIndex; }
    void swap(int x, int y) {
        int temp = v[x];
        v[x] = v[y];
        v[y] = temp;
    }
    void upHeap() {
        int i = lastIndex;
        while(i != 1 && v[i/2] > v[i]) {
            swap(i/2, i);
            i /= 2;
        }
    }
    void downHeap(int idx) {
        int left = 2 * idx;
        int right = 2 * idx + 1;
        int child;
        if(left > size()) {
            return;
        } else if (left == size()) {
            child = left;
        } else {
            if(v[left] <= v[right]) {
                child = left;
            } else {
                child = right;
            }
        }
        if(v[idx] > v[child]) {
            swap(idx, child);
            downHeap(child);
        }
    }
    void insert(int e) {
        v.push_back(e);
        lastIndex++;
        upHeap();
    }
    int removeMin() {
        int result = v[1];
        v[1] = v[lastIndex];
        v.erase(v.begin() + lastIndex);
        lastIndex--;
        downHeap(1);
        return result;
    }
    void sortedPrint() {
        vector<int> tempV;
        tempV.push_back(-1);
        int cnt = lastIndex;
        for(int i{ 0 }; i < cnt; i++) {
            tempV.push_back(removeMin());
        }
        for(int i{ 1 }; i < (tempV.size()); i++) {
            printf("%d\n", tempV[i]);
        }
    }
};
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int size;
    cin >> size;
    //O(n^2) time
    MinHeap h(size);
    //O(n) time
    h.sortedPrint();
}