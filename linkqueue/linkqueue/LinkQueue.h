#pragma once

template <class T>
class LinkQueue
{
public:

	LinkQueue();
	~LinkQueue();
	void EnQueue(const T&);
	T DeQueue();
	T& TopQueue();
	bool isEmpty() const;
private:
	struct ListNode
	{
		T data;
		ListNode *next;

		ListNode() { next = nullptr; }
		ListNode(const T& elem): data(elem),next(nullptr) {}
	};
	ListNode *head,*rear;
};

template <class T>
LinkQueue<T>::LinkQueue()
{
	rear = head = new ListNode();
}

template <class T>
void LinkQueue<T>::EnQueue(const T& elem)
{
	ListNode *p = new ListNode(elem);
	rear->next = p;
	rear = p;
}

template <class T>
T& LinkQueue<T>::TopQueue()
{
	//判断empty
	return head->next->data;
}

template <class T>
bool LinkQueue<T>::isEmpty() const
{
	return head == rear;
}

template <class T>
T LinkQueue<T>::DeQueue()
{
	if (isEmpty())
		std::cerr<<"empty"<<endl; //待完善
	else
	{
		T temp(head->next->data);
		ListNode *tempt = head->next;
		head->next = head->next->next;
		delete tempt;
		return temp;
	}
}

template <class T>
LinkQueue<T>::~LinkQueue()
{
	while (head != rear)
	{
		ListNode *temp = head;
		head = head->next;
		delete temp;
	}
	delete head;
	std::cout << "析构函数被调用" << endl;
}

