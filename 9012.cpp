#include <iostream>
#include <string>
using namespace std;
class Stack {
private:
	int* stack;
	int indexStack;
public:
	Stack();
	~Stack();
	void push();
	void pop();
	void isVPS() const;
	int getIndex() const { return indexStack; }
	void endIndex() { indexStack = -1; }
};

Stack::Stack()
	: stack{ new int[50] }, indexStack{ 0 } {}
Stack::~Stack() {
	delete[] stack;
}
void Stack::push() {
	stack[indexStack++] = 1;
}
void Stack::pop() {
	stack[--indexStack] = 0;
}
void Stack::isVPS() const {
	if (indexStack == 0)
		cout << "YES\n";
	else
		cout << "NO\n";
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int size;
	cin >> size;
	while (size--) {
		string word;
		cin >> word;
		Stack stk;
		for (int i{ 0 }; i < word.size(); i++) {
			if (*(word.begin() + i) == '(') {
				stk.push();
			}
			else { //*(word.begin() + i) == ')'
				if (stk.getIndex() == 0) { //'('가 없는데 제거한다면 에러
					stk.endIndex();
					break;
				}
				else
					stk.pop();
			}
		}
		stk.isVPS();
	}
	return 0;
}

