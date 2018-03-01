#include <iostream>
#include "Stack.h"
using namespace std;

int main()
{
	try {
		Stack<int> st;
		//st.pop();
		st.push(1);
		st.push(2);
		st.push(3);
		cout << st.top() << endl;
	}
	catch (exception& err)
	{
		cerr << err.what() << endl;
	}
	system("pause");
	return 0;

}