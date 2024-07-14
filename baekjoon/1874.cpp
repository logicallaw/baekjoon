#include <iostream>
using namespace std;
template<typename T>
class Stack{
private:
    T* stack;
    int n;
public:
    Stack(int size) : stack{ new T[ size] }, n{ -1 } {}
    ~Stack() {
        delete[] stack;
    }
    void push(T v){
        stack[++n] = v;
    }
    T pop() {
        return stack[n--];
    }
};
int main(void){
    int n;
    cin >> n;
    Stack<int> s(n);
    Stack<int> l(n);
    Stack<string> r(n);
    int cnt = 0;
    int copy_n = n;
    while(copy_n--){
        int temp;
        cin >> temp;
        if(cnt == n){
            int r1 = s.pop();
            int r2 = temp;
            if(r1 > temp){
                cout << "NO" << endl;

            }
            cout << "-" << endl;
            continue;
        }
        if(cnt <= temp){
            int ldx = temp - cnt;
            for(int i{ 0 }; i < ldx; i++){
                s.push(++cnt);
                cout << "+" << endl;
            }
            l.push(s.pop());
            cout << "-" << endl;
        } else if (cnt > temp){
            for(int i{ 0 }; i < (cnt - temp); i++) {
                l.push(s.pop());
                cout << "-" << endl;
            }
        }
    }
    return 0;
}