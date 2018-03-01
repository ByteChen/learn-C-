#include <iostream>
#include "LinkQueue.h"

using namespace std;

int main()
{
	/*linkqueue<int> p;
	p.~linkqueue();*/
	try {
		LinkQueue<int> q;
		//q.DeQueue();
		q.EnQueue(1);
		q.EnQueue(2);
		q.EnQueue(3);
		//q.EnQueue(4);
		q.DeQueue();
		q.isEmpty();
		cout << q.DeQueue() << endl;
		cout << q.DeQueue() << endl;
		cout << q.TopQueue() << endl;
	}
	catch(char *str){
		cout << str;
	}
	
	LinkQueue <int> pq;
	for (int i = 0; i < 10; i++)
	{
		pq.EnQueue(i);
	}
	for (int i = 0; i < 10; i++)
	{
		cout<<pq.DeQueue()<<endl;
	}
	cout << "finished" << endl;

	system("pause");
	return 0;
}