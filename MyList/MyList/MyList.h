#pragma once

template <class T>
class MyList
{
public:
	MyList() { first = nullptr; }
	void Insert(const T &elem);  //����ʱ���մ�С�����˳��
	void Delete(const T &elem);		
	void Invert();
	void Concat(const MyList& b);
	bool isEmpty() const;

	void display() const;	//��ͷ��β��ӡ�������ݵĺ���,����ֻ����ʾ������������

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
// ��������Ƚϸ��ӣ�������ͷ�����м䡢β�����룬�ʵ���ֿ��Լ�����
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
	while ((!isEmpty()) && (first->data == elem))  //�����Ƚϸ��ӵ����ʱ�����Խ������жϲ�֣�������
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
	while (p)  //�����������
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
		for (current = first; current->next; current = current->next);  //��ѭ����Ѱ��β�ڵ�
		current->next = b.first;
	}
}


