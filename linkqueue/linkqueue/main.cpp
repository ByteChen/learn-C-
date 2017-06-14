#include <iostream>
#include "LinkQueue.h"

using namespace std;

int main()
{
	LinkQueue<int> p;
	p.~LinkQueue();
	LinkQueue<int> q;
	q.EnQueue(1);
	q.EnQueue(2);
	q.EnQueue(3);
	q.EnQueue(4);
	q.DeQueue();
	q.isEmpty();
	cout << q.DeQueue() << endl;
	cout << q.DeQueue() << endl;
	cout << q.TopQueue()<< endl;
	//int *a = NULL; //NULL == 0;
	
	system("pause");
	return 0;
}