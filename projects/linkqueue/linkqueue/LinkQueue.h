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
	if (isEmpty())
		throw "TopQueue error: the queue is empty!\n";
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
		throw "DeQueue error: the queue is empty!\n";
	else
	{
		ListNode *temp;
		temp = head->next;
		if (temp->next == nullptr) //如果这是最后一个节点了，要做特殊处理
		{
			head->next = nullptr;
			rear = head;
		}
		else 
			head->next = temp->next;
		T val(temp->data);
		delete temp;
		return val;
	}
}

template <class T>
LinkQueue<T>::~LinkQueue()
{
	
	if (head != rear)
	{
		DeQueue();
	}
	delete head;
	std::cout << "析构函数被调用" << endl;
}

