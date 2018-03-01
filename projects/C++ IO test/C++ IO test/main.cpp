#include<iostream>
#include<string>
#include<vector>

#include<tuple>
extern "C" {
#include<stdio.h>
}
using namespace std;

int main()
{
	string str;
	char* c_str;
	char arr[10];
	/*
	cin >> str;
	cout << str << endl;
	cin.sync();
	cin.sync();
	cin >> str;
	cout << str << endl;
	*/
	cin.getline(arr,16);
	cout << arr << endl;
	//fgets(c_str,10,cin);
	//cin >> str;
	//cout << str << endl;

	//cin >> str;
	//cout << str << endl;

	//cin >> str;
	//cout << str << endl;

	/*	//getline()
	getline(cin, str, 'a');
	cout << str << endl;

	cin >> str;
	cout << str << endl;*/

	/*
	char* c_arr;
	cin >> c_arr;
	cout << c_arr << endl;
	*/

	tuple<size_t, size_t, size_t> three3D = { 1, 2, 3 };

	cout << get<1>(three3D )<< endl;

	auto aa = make_tuple(1, 'a');
	cout << get<1>(aa) << endl;

	tuple<int, char> ha;

	
	system("pause");
	return 0;
}