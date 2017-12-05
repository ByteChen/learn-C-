#include<iostream>
#include<string>
#include"Sales_item.h"

using namespace std;

int main()
{
	Sales_item book1, book2;
	read(cin, book1);
	read(cin, book2);
	Sales_item book3("123-z", 4, 100);

	//cout << "book1's isbn is: " << book1.isbn() << endl;
	//print(cout, book2);
	Sales_item sum = add(book1, book2);
	print(cout, sum);

	cout << "Combine book1 and book2:" << endl;
	book1.combine(book2);
	print(cout, book1);

	cout << book1.get_avg() << endl;

	system("pause");
	return 0;
}