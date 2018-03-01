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
	//���û�������ʼ�Կն��з����ڴ棬
	//��front��rear����Ϊnullptr�Ļ���
	//�ǲ�����rear->next���ʳ�Ա��
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
	return front == nullptr;  //����������front == rear
}

template <class T>
T& LinkedQueue<T>::TopQueue()
{
	if (isEmpty())
		throw string("TopQueue error: the queue is empty!");
		//������Dequeue�����е�throw�Ƚϣ��Ǹ�catch��ʱ��
	    //ֻ����char*���ͣ��������string����
	T temp(front->data);
	return temp;
}
