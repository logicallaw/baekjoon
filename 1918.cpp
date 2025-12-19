#include <iostream>
#include <string>
using namespace std;
class Stack{
private:
    char* stack;
    int n;
public:
    Stack(int size) : stack{ new char[size] }, n{ -1 } {}
    ~Stack() {
        delete[] stack;
    }
    void push(char x){
        stack[++n] = x;
    }
    void pop() {
        n--;
    }
    char top() const {
        return stack[n];
    }
    bool empty() const { return (n == -1); }
};
int main(void){
    string userInput;
    cin >> userInput;
    Stack stk(userInput.length());
    for(int i{ 0 }; i < userInput.length(); i++){
        char temp = userInput.at(i);
        if(temp >= 'A' && temp <= 'Z'){
            cout << temp;
        } else {
            if(temp == '('){
                stk.push(temp);
            } else if (temp == '*'  || temp == '/') {
                while(!stk.empty() && (stk.top() == '*' || stk.top() == '/')){
                    cout << stk.top();
                    stk.pop();
                }
                stk.push(temp);
            } else if (temp == '+' || temp == '-'){
                while(!stk.empty() && (stk.top() != '(')){
                    cout << stk.top();
                    stk.pop();
                }
                stk.push(temp);
            } else if (temp == ')') {
                while (!stk.empty() && stk.top() != '(') {
                    cout << stk.top();
                    stk.pop();
                }
                stk.pop();
            }
        }
    }
    while(!stk.empty()){
        cout << stk.top();
        stk.pop();
    }
}