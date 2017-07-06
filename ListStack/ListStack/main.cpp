#include<iostream>
#include "ListStack.h"

using namespace std;

int main()
{
	ListStack<int> ls;
	ls.push(1);
	ls.push(2);
	cout << ls.Top() << endl;
	cout << ls.pop() << endl;
	cout << ls.Top() << endl;
	system("pause");
	return 0;
}