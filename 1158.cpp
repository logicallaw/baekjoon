#include <iostream>
using namespace std;
class Array{
private:
    int* array;
    int N;
    int n;
    int k;
    int jump;
public:
    Array(int size, int k){
        array = new int[size];
        for(int i{0}; i < size; i++){
            array[i] = i + 1;
        }
        N = n = size;
        jump = k - 1;
        this->k = k - 1;

    }
    ~Array() {
        delete[] array;
    }
    void pop() {
        k %= n;
        cout << array[k];
        for(int idx = k; idx < n - 1; idx++) {
            array[idx] = array[idx + 1];
        }

        n--;
        k += jump;
    }
};
int main(void){
    int n, k;
    cin >> n >> k;
    Array arr(n, k);

    cout << "<";
    int copy_n = n - 1;
    while(copy_n--){
        arr.pop();
        cout << ", ";
    }
    arr.pop();
    cout << ">\n";
    return 0;
}