#include <iostream>
using namespace std;
class Stack {
private:
	int* stack;
	int indexStack;
public:
	Stack(const int& SIZE);
	~Stack();
	void push(const int& temp);
	void pop();
	void count() const;
	void is_empty() const;
	void peek() const;
};
void menu(const int& temp, Stack& param);
Stack::Stack(const int& SIZE)
	: stack{ new int[SIZE] }, indexStack{ 0 } {}
Stack::~Stack() { delete[] stack; }
void Stack::push(const int& temp) {
	stack[indexStack++] = temp;
}
void Stack::pop() {
	if (indexStack != 0)
		cout << stack[--indexStack] << "\n";
	else
		cout << "-1\n";
}
void Stack::count() const { cout << indexStack << "\n"; }
void Stack::is_empty() const {
	if (indexStack != 0)
		cout << "0\n";
	else
		cout << "1\n";
}
void Stack::peek() const {
	if (indexStack != 0)
		cout << stack[indexStack - 1] << "\n";
	else
		cout << "-1\n";
}

int main(void) {
	int size;
	/*
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); 이 없으면 시간초과가 발생한다.
	*/
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> size;
	Stack stk{ size };
	while (size--) {
		int temp;
		cin >> temp;
		menu(temp, stk);
	}
}

void menu(const int& temp, Stack& stk) {
	switch (temp) {
	case 1:
		int inputTemp;
		cin >> inputTemp;
		stk.push(inputTemp);
		break;
	case 2:
		stk.pop();
		break;
	case 3:
		stk.count();
		break;	
	case 4:
		stk.is_empty();
		break;
	case 5:
		stk.peek();
		break;
	}
}