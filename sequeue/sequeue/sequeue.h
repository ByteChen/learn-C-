#pragma once

template <class T>
class SeQueue
{
public:
	SeQueue(int size = 10);
	~SeQueue();
	void push(const T& elem);
	bool isEmpty() const;  //能加const则多加，养成好习惯
	T& top() const;
	T pop();
	
private:
	//T arr[MAXSIZE];  //固定数组，由于编译时就要确定容量，不好，不如动态数组
	T *sq;
	int front;
	int rear;
	int capacity;
};

template <class T>
SeQueue<T>::SeQueue(int size = 10)
{
	if (size < 2) throw "输入的大小必须大于等于2！";
	capacity = size;
	sq = new T[capacity];
	front = rear = 0; //比-1好,-1的话，(rear+1)%capacity == front 无法达成
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
		//当队列满时，扩容成两倍
	{
		T* newq = new T[capacity * 2];
		int start = (front + 1) % capacity;
		if(start < 2)//没有回绕
			copy(sq + start, sq + capacity, newq);
		else //如果有回绕，也就是rear跑到front前面的情况，则需要先拷贝后部分，再拷贝前部分
		{
			copy(sq + start, sq + capacity, newq);
			copy(sq, sq + rear + 1, newq + capacity - start);
		}
		delete[]sq;
		sq = newq;
		rear = capacity - 2; // 记得拷贝后更新 front 和 rear
		front = 2 * capacity - 1;  //这里对rear和front的更新颇有讲究，易错
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
	sq[front].~T();  //对当前对象进行析构
	return temp;
}