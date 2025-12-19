#include <iostream>
using namespace std;
class Stack{
private:
    int* stack;
    int n;
public:
    Stack(int size) : stack{ new int[size]{} }, n{ -1 } {}
    ~Stack() { delete[] stack; }
    void push(int x){
        stack[++n] = x;
    }
    int pop() {
        if(n == -1) {
            return -1;
        } else {
            return stack[n--];
        }
    }
    int size() const {
        return n + 1;
    }
    int top() const {
        if(n == -1) {
            return -1;
        } else {
            return stack[n];
        }
    }
    bool empty() const { return (n == -1); }
};
int main(void) {
    int size;
    cin >> size;
    Stack tempStk{ size };
    int cnt = 1;
    while(size--){
        int userInput;
        cin >> userInput;
        while (!tempStk.empty() && tempStk.top() == cnt) {
            tempStk.pop();
            cnt++;
        }

        if (cnt == userInput) {
            cnt++;
        } else {
            tempStk.push(userInput);
        }
    }
    while(!tempStk.empty() && tempStk.top() == cnt){
        cnt++;
        tempStk.pop();
    }
    if(tempStk.empty()) {
        cout << "Nice" << endl;
    } else {
        cout << "Sad" << endl;
    }
}