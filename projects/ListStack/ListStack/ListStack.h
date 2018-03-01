#pragma once
template<class T>
class ListStack;

template <class T>
class Node
{
friend class ListStack<T>;
public:
	Node(const T&elem, Node* p = nullptr)  //����Ĭ��ֵ��ָ���ʼ��Ϊnullptr��
		:data(elem), next(p) {}
private:
	T data;
	Node *next;
};

template <class T>
class ListStack
{
public:
	ListStack() :top(nullptr) {}
	~ListStack();
	void push(const T&);
	T pop();
	T& Top() const;  //����Ҫ�ǵö��const
	bool isEmpty()const;
private:
	Node<T> *top;
};

template <class T>
bool ListStack<T>::isEmpty() const
{
	return top == nullptr;
}

template <class T>
void ListStack<T>::push(const T& elem)
{
	//if (isEmpty())
	//{
	//	top = new Node<T>(elem,nullptr);
	//}
	//else
	//{
	//	Node<T>* temp = new Node<T>(elem, nullptr);
	//	temp->next = top;
	//	top = temp;
	//}

	//���õ���������
	top = new Node<T>(elem, top);	//�½�һ���ڵ㣬data=elem��nextָ����ǰ��top,Ȼ�󷵻ؽڵ��ַ��top������дҪ��Node���캯��Ҫ����������д��
}

template <class T>
T& ListStack<T>::Top() const
{
	if (isEmpty()) throw "stack is empty!\n";
	return top->data;
}

template<class T>
T ListStack<T>::pop()
{
	if (isEmpty()) throw "Pop error: stack is empty!\n";
	Node<T>* temp = top;
	top = top->next;
	T elem(temp->data);
	delete temp;
	return elem;
}

template <class T>
ListStack<T>::~ListStack()
{
	while (!isEmpty())
		pop();
}