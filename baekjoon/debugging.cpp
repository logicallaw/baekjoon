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
	cout << "F5: start debugging/continue(디버깅 시작/계속)" << endl;
	cout << "F9: toggle breakpoint(중단점 설정/해제)" << endl;
	cout << "F10: step over(프로시저 단위 실행)" << endl;
	cout << "F11: step into(한 단계씩 코드 실행)" << endl;
	cout << "Shift + F11: step over(프로시저 나가기)" << endl;
	cout << "Shift + F5: stop debugging(디버깅 중지)" << endl;

	int a{ 0 };
	for (int i{ 0 }; i < 10; i++) {
		cout << a << endl;
		a += i; //Ctrl + F9: disable/enable breakpoint(중단점 해제/설정)
		cout << a << endl;
	}

	fun1();
	fun2();

	int arr[5]{ 1,2,3,4,5 };
	int* ptr{ new int[5] {1,2,3,4,5} };
}

/*
F5:디버깅 시작
디버깅 시작 후 중단점까지 코드 실행한다.
F9:중단점 설정/해제
Ctrl+F9:임시로 중단점 설정/해제
F10:프로시저 단위로 실행(함수 내부 코드는 건너뛴다)
F11:한 단계씩 실행(함수 내부 코드 들어간다)
Shift+F11:프로시저 나가기(함수 내부 코드에 있으면 나간다)
Shift+F5:디버깅 중지
Ctrl+Shift+F5:다시 디버깅 실행
로컬/조사식(조사식은 heap공간 포인터 배열 알 수 있다. 변수나 식 변화 관찰 가능하다.
*/