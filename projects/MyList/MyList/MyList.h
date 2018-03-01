#pragma once

template <class T>
class MyList
{
public:
	MyList() { first = nullptr; }
	void Insert(const T &elem);  //插入时按照从小到大的顺序
	void Delete(const T &elem);		
	void Invert();
	void Concat(const MyList& b);
	bool isEmpty() const;

	void display() const;	//从头到尾打印链表数据的函数,不过只能显示基本数据类型

private:
	class ListNode
	{
	public:
		T data;
		ListNode *next;

		ListNode(const T& val)
		{
			data = val;
			next = nullptr;
		}
	};

	ListNode *first;
};

template <class T>
bool MyList<T>::isEmpty() const
{
	return first == nullptr;
}

template<class T>
void MyList<T>::display() const
{
	if (isEmpty())
		throw "The list is empty!\n";
	else
	{
		ListNode *current = first;
		do
		{
			std::cout << current->data ;
			if (current->next) std::cout << " -> ";
			current = current->next;
		} while (current != nullptr);
		std::cout << std::endl;
	}
}

template <class T>
void MyList<T>::Insert(const T &elem)
// 插入情况比较复杂，可能在头部、中间、尾部插入，适当拆分可以简化问题
{
	ListNode *temp = new ListNode(elem);
	if (isEmpty())
		first = temp;
	else if (first->data > elem)
	{
		temp->next = first;
		first = temp;
	}
	else
	{
		ListNode *current = first;

		while ((current->next != nullptr) && (current->next->data < elem))  
		{
			current = current->next;
		}
		if (current->next == nullptr)
		{
			current->next = temp;
		}
		else
		{
			temp->next = current->next;
			current->next = temp;
		}
	}
}

template <class T>
void MyList<T>::Delete(const T&elem)
{
	if (isEmpty())
		throw "Delete error: The list is empty!\n";
	
	int delete_count = 0;
	while ((!isEmpty()) && (first->data == elem))  //遇到比较复杂的情况时，可以将多重判断拆分，简化问题
	{
		ListNode* temp = first;
		first = first->next;
		temp->data.~T();
		delete_count++;
	}
	ListNode *current = first;

	while ((!isEmpty()) && (current->next != nullptr))
	{
		if (current->next->data == elem)
		{
			ListNode* temp = current->next;
			current->next = current->next->next;
			temp->data.~T();
			delete_count++;
		}
		else
			current = current->next;
	}
	if(delete_count == 0)
		throw "Delete Error: No such element in the list!\n"; 
}

template <class T>
void MyList<T>::Invert()
{
	ListNode *p, *q, *r;
	p = first;
	q = nullptr;
	while (p)  //这个方法不错
	{
		r = q;
		q = p;
		p = p->next;
		q -> next = r;
	}
	first = q;
}


template <class T>
void MyList<T>::Concat(const MyList& b)
{
	if (isEmpty())
		first = b.first;
	else
	{
		ListNode *current;
		for (current = first; current->next; current = current->next);  //空循环，寻找尾节点
		current->next = b.first;
	}
}


