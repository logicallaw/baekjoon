#include<iostream>
#include<time.h>
using namespace std;

int main()
{
	clock_t start, end;
	double time1, time2, time3, time4;

	start = clock(); //�ð� ���� ����

	// #time1 "cout << i << endl;"
	for (int i = 0; i < 1000000; i++)
	{
		cout << i << endl;
	}

	end = clock(); //�ð� ���� ��
	time1 = end - start;


	// #time2 "cout << i << "\n";"
	start = clock(); //�ð� ���� ����

	for (int i = 0; i < 1000000; i++)
	{
		cout << i << '\n';
	}

	end = clock(); //�ð� ���� ��
	time2 = end - start;


	// #time3 "printf("%d\n", i);"
	start = clock(); //�ð� ���� ����

	for (int i = 0; i < 1000000; i++)
	{
		printf("%d\n", i);
	}

	end = clock(); //�ð� ���� ��
	time3 = end - start;

	printf("\n\n");
	cout << "cout << i << endl : " << time1 << "ms" << endl;
	cout << "cout << i << '\\n' : " << time2 << "ms" << endl;
	cout << "printf(\"%d\\n\", i) : " << time3 << "ms" << endl;
}