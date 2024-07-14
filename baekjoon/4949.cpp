#include <iostream>
using namespace std;
class Stack {
private:
    char* stack;
    int n;
public:
    Stack(int size) : stack{ new char[size + 1] }, n{ -1 } {}
    ~Stack() { delete[] stack; }
    void push(char c) {
        stack[++n] = c;
    }
    char pop() {
        if(n == -1) {
            return '#';
        } else {
            return stack[n--];
        }
    }
};
int main(void){
    while(true){
        string userInput;
        getline(cin, userInput);
        if(userInput == "."){
            return 0;
        }
        Stack stk(userInput.length());
        bool bb = true;
        for(int i = 0; i < userInput.length(); i++){
            char c = userInput.at(i);
            if (c == '(' || c == '[') {
                stk.push(c);
            }
            else if (c == ')' || c == ']') {
                char pop_c = stk.pop();
                //없으면
                if(pop_c == '#') {
                    bb = false;
                    break;
                }
                if(c == ')') {
                    if(pop_c != '(') {
                        bb = false;
                        break;
                    }
                } else {
                    if(pop_c != '['){
                        bb = false;
                        break;
                    }
                }
            }
        }
        if(stk.pop() != '#') {
            bb = false;
        }
        if(bb){
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
    }
}