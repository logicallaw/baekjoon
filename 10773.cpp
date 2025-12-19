#include <iostream>
using namespace std;
class Stack {
private:
	int* stack;
	int indexStack;
public:
	Stack(const int& SIZE);
	~Stack();
	void push(int& temp);
	void pop();
	void sum() const;
};
Stack::Stack(const int& SIZE)
	: stack{ new int[SIZE] }, indexStack{ 0 } {}
Stack::~Stack() {
	delete[] stack;
}
void Stack::push(int& temp) {
	stack[indexStack++] = temp;
}
void Stack::pop() {
	stack[--indexStack] = 0;
}
void Stack::sum() const {
	unsigned int sum = 0;
	for (int i{ 0 }; i < indexStack; i++)
		sum += stack[i];
	printf("%d\n", sum);
}


int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int size;
	cin >> size;
	Stack stk{ size };
	while (size--) {
		int temp;
		cin >> temp;
		if (temp != 0)
			stk.push(temp);
		else
			stk.pop();
	}
	stk.sum();
	return 0;
}