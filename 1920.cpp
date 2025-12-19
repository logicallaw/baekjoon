#include <iostream>
#include <vector>
using namespace std;
class MinHeap;
class IntNode{
private:
    IntNode* par;
    int ele;
    IntNode* leftC;
    IntNode* rightC;
    friend class MinHeap;
};
class MinHeap{
private:
    vector<int> v;
    int n;
public:
    MinHeap() {
        v.push_back(-1);
        n = 0;
    }
    void swap(int x, int y) {
        int temp = v[x];
        v[x] = v[y];
        v[y] = temp;
    }
    void upHeap(int idx) {
        int i = idx;
        while(i != 1 && v[i / 2] < v[i]){
            swap(i/2, i);
            i /= 2;
        }
    }
    int size() const { return n;}
    void insert(int x) {
        v.push_back(x);
        n++;
        upHeap(n);
    }
//    void downHeap(int idx) {
//        int left = 2 * idx;
//        int right = 2 * idx + 1;
//        int child;
//        if(left > size()) {
//            child =
//        }
//    }
    int removeMin() {
        int result = v[1];
        v[1] = v[n];
        n--;
        downHeap(1);
        return result;
    }
};
using namespace std;

int main(void) {
    int n;
    cin >> n;
    MinHeap h;
    while(n--) {
        int x;
        cin >> x;
        h.insert(x);
    }
    return 0;
}