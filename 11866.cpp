#include <iostream>
using namespace std;
class Queue{
private:
    int* array;
    int n;
    int k;
    int idx;
public:
    Queue(int size, int k) {
        this->k = k - 1;
        idx = k - 1;
        n = size;
        array = new int[size];
        for(int i{ 0 }; i < size; i++) {
            array[i] = i + 1;
        }
    }
    ~Queue() {
        delete[] array;
    }
    int pop(){
        int result = array[idx];
        for(int i{ idx }; i < (n - 1); i++){
            array[i] = array[i + 1];
        }
        n--;
        idx = (idx + k) % n;
        return result;
    }
};
int main(void) {
    int N, k;
    cin >> N >> k;
    Queue q(N, k);
    cout << "<";
    int cnt = N - 1;
    while(cnt--) {
        cout << q.pop() << ", ";
    }
    cout << q.pop() << ">";
    return 0;
}