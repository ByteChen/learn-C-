#include<iostream>
#include"sequeue.h"

using namespace std;

int main()
{
	try {
		SeQueue<char> sq(5);
		//sq.top();
		//sq.pop();
		sq.push('a');
		sq.push('b');
		sq.push('c');
		sq.push('d');
		sq.push('a');
		sq.push('b');
		sq.push('c');
		sq.push('d');
		sq.push('a');
		sq.push('b');
		sq.push('c');
		sq.push('d');
		sq.top();
		sq.pop();
		cout << sq.top() << endl;
	}
	catch (char* err)
	{
		cout << err << endl;
	}
	/*int * a = new int[5];
	int * b = new int[10];
	a[0] = 1;
	a[1] = 2;
	copy(a, a + 5, b);*/
	//_SCL_SECURE_NO_WARNINGS
	//������ǰ��copy����unsafe����Ҫ��Ԥ�����������м�������������������
	system("pause");
	return 0;
}