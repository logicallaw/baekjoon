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
	void size() const;
	void empty() const;
	void top() const;
};
void progress(Stack& stk, const string& word);
Stack::Stack(const int& SIZE)
	: stack{ new int[SIZE] }, indexStack{ 0 } {}
Stack::~Stack() {
	delete[] stack;
}
void Stack::push(const int& temp) {
	stack[indexStack++] = temp;
}
void Stack::pop() {
	if (indexStack != 0)
		cout << stack[--indexStack] << "\n";
	else
		cout << "-1\n";
}
void Stack::size() const {
	cout << indexStack << "\n";
}
void Stack::empty() const {
	if (indexStack != 0)
		cout << "0\n";
	else
		cout << "1\n";
}
void Stack::top() const {
	if (indexStack != 0)
		cout << stack[indexStack - 1] << "\n";
	else
		cout << "-1\n";
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int size;
	cin >> size;

	Stack stk{ size };

	while (size--) {
		string word;
		cin >> word;
		progress(stk, word);
	}

	return 0;
}

void progress(Stack& stk, const string& word) {
	if (word == "push") {
		int temp;
		cin >> temp;
		stk.push(temp);
	}
	else if (word == "pop") {
		stk.pop();
	}
	else if (word == "size") {
		stk.size();
	}
	else if (word == "empty") {
		stk.empty();
	}
	else if (word == "top") {
		stk.top();
	}
}