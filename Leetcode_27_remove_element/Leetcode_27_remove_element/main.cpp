//Leetcode
//27. Remove Element
//Given an array and a value, remove all instances of that value in place and return the new length.
//Do not allocate extra space for another array, you must do this in place with constant memory.
//The order of elements can be changed.It doesn't matter what you leave beyond the new length.
//
//Example:
//Given input array nums = [3, 2, 2, 3], val = 3
//Your function should return length = 2, with the first two elements of nums being 2.

//�ܽ᣺����vector����Ҫִ��erase����ʱ��������ʹ�õ���������ʹ���±������
//ԭ��After erasing or pushing in a vector all the iterators to it may become invalid(if the vector gets reallocated). 
//That is why after erase is performed in the else m_pos may become invalid. My advise is to use indices(at least that is what I do for competetive programming).

//ע�⣺�����ǰ����ʹ�õ������ķ�������VS2015���޷���ȷִ�У�һ�㶼���жϣ�˵�±겻�ɼӻ��߲��ɼ�������vector not iterator decrementable ��������GCC����Ļ���������ȷ���С�
#include<iostream>
#include<vector>

using namespace std;

int removeElement(vector<int>& nums, int val);

int main()
{
	vector<int> ivec = { 1,3,2,2,3,1,5,100,3 };
	cout << removeElement(ivec, 3) << endl;
	system("pause");
	return 0;
}


//����һ
//int removeElement(vector<int>& nums, int val) 
//{
//	for (vector<int>::iterator iter = nums.begin(); iter != nums.end(); iter++)
//	{
//		if (*iter == val)
//		{
//			nums.erase(iter);
//			iter--;
//		}
//	}
//	return nums.size();
//}

// ������
//int removeElement(vector<int>& nums, int val) 
//{
//	auto it = nums.begin();
//	while (it != nums.end()) {
//		if (val == *(it)) nums.erase(it);
//		else it++;
//	}
//	return nums.size();
//}

//������
//int removeElement(vector<int>& nums, int val) 
//{
//	int index = 0;
//	for (int i = 0; i<nums.size(); i++)
//		if (nums[i] != val)
//			nums[index++] = nums[i];
//	return index;
//}

//������
int removeElement(vector<int>& nums, int val)
{
	int cnt = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		if (nums[i] == val)
		{
			cnt++;
		}
		else
		{
			nums[i - cnt] = nums[i];
		}
	}

	return nums.size() - cnt;
}