#include <iostream>
#include "MyList.h"

using namespace std;

class Dog
{
	//
};
int main()
{
	try
	{
		MyList<int> ls;
		//ls.display();  
		ls.Insert(1);
		ls.Insert(100);
		ls.Insert(5);
		ls.Insert(3);
		ls.Insert(1);
		ls.Insert(3);
		ls.Delete(3);
		ls.display();
		ls.Invert();
		ls.display();

		MyList<int> ls2;
		ls2.Insert(1000);
		ls2.Insert(3000);
		ls2.Insert(2000);
		ls2.Concat(ls);
		ls2.display();

		MyList<char> cl;
		cl.Insert('c');
		cl.Insert('b');
		cl.Insert('a');
		cl.Insert('d');
		cl.Insert('c');
		cl.display();
		cl.Delete('c');
		cl.display();

		MyList<Dog> dl;
		Dog a, b;
		/*dl.Insert(a);
		dl.Insert(b);*/
	}
	catch (char* err)
	{
		cout << err << endl;
	}
	system("pause");
	return 0;
}