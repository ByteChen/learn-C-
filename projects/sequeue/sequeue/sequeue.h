#pragma once

template <class T>
class SeQueue
{
public:
	SeQueue(int size = 10);
	~SeQueue();
	void push(const T& elem);
	bool isEmpty() const;  //�ܼ�const���ӣ����ɺ�ϰ��
	T& top() const;
	T pop();
	
private:
	//T arr[MAXSIZE];  //�̶����飬���ڱ���ʱ��Ҫȷ�����������ã����綯̬����
	T *sq;
	int front;
	int rear;
	int capacity;
};

template <class T>
SeQueue<T>::SeQueue(int size = 10)
{
	if (size < 2) throw "����Ĵ�С������ڵ���2��";
	capacity = size;
	sq = new T[capacity];
	front = rear = 0; //��-1��,-1�Ļ���(rear+1)%capacity == front �޷����
}

template <class T>
SeQueue<T>::~SeQueue()
{
	delete []sq;
}

template <class T>
void SeQueue<T>::push(const T& elem)
{
	if ((rear + 1) % capacity == front)
		//��������ʱ�����ݳ�����
	{
		T* newq = new T[capacity * 2];
		int start = (front + 1) % capacity;
		if(start < 2)//û�л���
			copy(sq + start, sq + capacity, newq);
		else //����л��ƣ�Ҳ����rear�ܵ�frontǰ������������Ҫ�ȿ����󲿷֣��ٿ���ǰ����
		{
			copy(sq + start, sq + capacity, newq);
			copy(sq, sq + rear + 1, newq + capacity - start);
		}
		delete[]sq;
		sq = newq;
		rear = capacity - 2; // �ǵÿ�������� front �� rear
		front = 2 * capacity - 1;  //�����rear��front�ĸ������н������״�
		capacity = 2 * capacity;
	}
	rear = (rear + 1) % capacity;
	sq[rear] = elem;
}

template <class T>
bool SeQueue<T>::isEmpty() const
{
	return front == rear;
}

template <class T>
T& SeQueue<T>::top() const
{
	if (isEmpty()) throw "top error: the queue is empty!";
	return sq[(front + 1) % capacity];
}

template <class T>
T SeQueue<T>::pop()
{
	if (isEmpty()) throw "pop error: the queue is empty!";
	front = (front + 1) % capacity;
	T temp(sq[front]);
	sq[front].~T();  //�Ե�ǰ�����������
	return temp;
}