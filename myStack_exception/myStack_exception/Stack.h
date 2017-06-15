# ifndef STACK_H
#define STACK_H

#include <exception>
#include <deque>

template <class T>
class Stack
{
public:
	T pop();
	T& top();
	void push(const T& val);
	bool isEmpty() const { return c.empty(); }

	class ReadEmptyStack : public std::exception
	{
	public:
		virtual const char* what() const throw()
		{
			return "Read Stack error: the stack is empty;\n";
		}
	};

	//void Stack::push(const T& val)
	//{
	//	c.push_back(val);
	//}

	//T& Stack::top()
	//{
	//	if (c.empty())
	//		throw ReadEmptyStack();
	//	return c.back();
	//}

	//T Stack::pop()
	//{
	//	if (c.empty())
	//		throw ReadEmptyStack();
	//	T temp(c.back());  //使用括号初始化，因为如果是类对象的话，可能没有重载=
	//	c.pop_back();
	//	return temp;
	//}

private:
	std::deque<T> c;
};

template <class T>
void Stack<T>::push(const T& val)  //在类外写函数定义时，Stack后面的<T>不可省略，否则无法将函数的定义与类内的声明匹配
{
	c.push_back(val);
}

template <class T>
T& Stack<T>::top()
{
	if (c.empty())
		throw ReadEmptyStack();
	return c.back();
}

template <class T>
T Stack<T>::pop()
{
	if (c.empty())
		throw ReadEmptyStack();
	T temp (c.back() );  //使用括号初始化，因为如果是类对象的话，可能没有重载=
	c.pop_back();
	return temp;
}
#endif