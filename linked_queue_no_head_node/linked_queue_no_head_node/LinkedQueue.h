#pragma once
#include<string>

template <class T>
class LinkedQueue
{
public:
	LinkedQueue();
	~LinkedQueue();
	void EnQueue(const T&);
	T DeQueue();
	T& TopQueue();
	bool isEmpty() const;
private:
	struct ListNode
	{
		T data;
		ListNode *next;

		ListNode(const T& elem, ListNode *ptr = nullptr)
			:data(elem), next(ptr) {}
	};

	ListNode *front, *rear;
};

template <class T>
LinkedQueue<T>::LinkedQueue()
{
	front = rear = nullptr;
}

template <class T>
LinkedQueue<T>::~LinkedQueue()
{
	while(!isEmpty())
	{
		DeQueue();
	}
}

template <class T>
void LinkedQueue<T>::EnQueue(const T& elem)
{
	if (isEmpty())
	{
		front = rear = new ListNode(elem);
	}
	//如果没有上面初始对空队列分配内存，
	//即front、rear继续为nullptr的话，
	//是不能如rear->next访问成员的
	else 
	{
		rear = rear->next = new ListNode(elem);
	}
}

template <class T>
T LinkedQueue<T>::DeQueue()
{
	if (isEmpty())
		throw "DeQueue error: the queue is empty!";
	ListNode *temp = front;
	T elem(temp->data);
	front = front->next;
	delete temp;
	return elem;
}

template <class T>
bool LinkedQueue<T>::isEmpty() const
{
	return front == nullptr;  //条件不能是front == rear
}

template <class T>
T& LinkedQueue<T>::TopQueue()
{
	if (isEmpty())
		throw string("TopQueue error: the queue is empty!");
		//和上面Dequeue函数中的throw比较，那个catch的时候，
	    //只能是char*类型，这个则是string类型
	T temp(front->data);
	return temp;
}
