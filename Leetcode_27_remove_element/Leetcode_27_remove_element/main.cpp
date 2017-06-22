//Leetcode
//27. Remove Element
//Given an array and a value, remove all instances of that value in place and return the new length.
//Do not allocate extra space for another array, you must do this in place with constant memory.
//The order of elements can be changed.It doesn't matter what you leave beyond the new length.
//
//Example:
//Given input array nums = [3, 2, 2, 3], val = 3
//Your function should return length = 2, with the first two elements of nums being 2.

//总结：对于vector，需要执行erase操作时，尽量不使用迭代器，而使用下标操作。
//原因：After erasing or pushing in a vector all the iterators to it may become invalid(if the vector gets reallocated). 
//That is why after erase is performed in the else m_pos may become invalid. My advise is to use indices(at least that is what I do for competetive programming).

//注意：下面的前两种使用迭代器的方法，在VS2015中无法正确执行，一般都会中断，说下标不可加或者不可减。比如vector not iterator decrementable 。不过用GCC编译的话，可以正确运行。
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


//方法一
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

// 方法二
//int removeElement(vector<int>& nums, int val) 
//{
//	auto it = nums.begin();
//	while (it != nums.end()) {
//		if (val == *(it)) nums.erase(it);
//		else it++;
//	}
//	return nums.size();
//}

//方法三
//int removeElement(vector<int>& nums, int val) 
//{
//	int index = 0;
//	for (int i = 0; i<nums.size(); i++)
//		if (nums[i] != val)
//			nums[index++] = nums[i];
//	return index;
//}

//方法四
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