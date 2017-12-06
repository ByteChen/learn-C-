#include<iostream>
#include<string>
#include"Sales_item.h"

using namespace std;
/*
void test()
{
	int a;
	cout << a << endl;
}*/

int aa;
int main()
{
	//test();	//测试函数块中局部变量的默认初始化。结果：不能访问未定义的变量a。
	//int aa = int();	//这个也不行，在main（）函数块内
	if(aa == 0)
		cout << 1;

	Sales_item book1, book2;
	read(cin, book1);
	read(cin, book2);
	Sales_item book3("123-z", 4, 100);

	if (cin)
		cout << "cin ok" << endl;
	else
		cout << "cin not ok" << endl;
	//cout << "book1's isbn is: " << book1.isbn() << endl;
	//print(cout, book2);
	Sales_item sum = add(book1, book2);
	print(cout, sum);

	cout << "Combine book1 and book2:" << endl;
	book1.combine(book2);
	print(cout, book1);

	cout << book1.get_avg() << endl;
	
	Sales_item a;
	cout<<a.get_avg();
	system("pause");
	return 0;
}