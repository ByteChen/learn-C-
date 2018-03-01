#include<iostream>
#include "LinkedQueue.h"
#include<string>

using namespace std;

int main()
{
	try {
		LinkedQueue<char> cq;
		//cq.TopQueue();
		//cq.DeQueue();
		cq.EnQueue('a');
		cq.EnQueue('b');
		cq.EnQueue('c');
		cq.DeQueue();
		cout << cq.TopQueue() << endl;
		char &temp = cq.TopQueue();
		temp = 'd';
		cq.TopQueue()++;
		++cq.TopQueue();
		cout << cq.TopQueue() << endl;
	}
	catch(string err)  //比较throw抛出不同类型的字符串时的反应
	{
		cout << err << endl;
	}
	catch (char* err)
	{
		cout << err << endl;
	}

	system("pause");
	return 0;
}