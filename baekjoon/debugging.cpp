#include <iostream>
using namespace std;

void fun1() {
	cout << "fun1" << endl;
}

void fun2() {
	int result{ 0 };
	for (int i{ 0 }; i < 10; i++) {
		result += i;
	}
	cout << result << endl;
}

int main(void) {
	cout << "F5: start debugging/continue(����� ����/���)" << endl;
	cout << "F9: toggle breakpoint(�ߴ��� ����/����)" << endl;
	cout << "F10: step over(���ν��� ���� ����)" << endl;
	cout << "F11: step into(�� �ܰ辿 �ڵ� ����)" << endl;
	cout << "Shift + F11: step over(���ν��� ������)" << endl;
	cout << "Shift + F5: stop debugging(����� ����)" << endl;

	int a{ 0 };
	for (int i{ 0 }; i < 10; i++) {
		cout << a << endl;
		a += i; //Ctrl + F9: disable/enable breakpoint(�ߴ��� ����/����)
		cout << a << endl;
	}

	fun1();
	fun2();

	int arr[5]{ 1,2,3,4,5 };
	int* ptr{ new int[5] {1,2,3,4,5} };
}

/*
F5:����� ����
����� ���� �� �ߴ������� �ڵ� �����Ѵ�.
F9:�ߴ��� ����/����
Ctrl+F9:�ӽ÷� �ߴ��� ����/����
F10:���ν��� ������ ����(�Լ� ���� �ڵ�� �ǳʶڴ�)
F11:�� �ܰ辿 ����(�Լ� ���� �ڵ� ����)
Shift+F11:���ν��� ������(�Լ� ���� �ڵ忡 ������ ������)
Shift+F5:����� ����
Ctrl+Shift+F5:�ٽ� ����� ����
����/�����(������� heap���� ������ �迭 �� �� �ִ�. ������ �� ��ȭ ���� �����ϴ�.
*/