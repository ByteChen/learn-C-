## 问题
非递归实现的binary_search
给出一个有n个从小到大排序的且无重复的int序列,在数组中查找target并返回位置,如果不存在返回-1.(本题会人工改卷,请使用非递归实现的binary_search实现) 

输入描述:

输入包含两行:

 第一行有两个整数n(1 ≤ n ≤ 100000000),表示数组数字个数n;target,即查找的目标值。 第二行为n个整数,范围均在32位整数,以空格分隔,保证输入数据合法


输出描述:

如果存在,输出target出现的下标,否则输出-1

输入例子1:

7 0 0 1 2 3 4 5 6

输出例子1:

0

## 代码
```C++
#include<iostream>

using namespace std;

int main() {
	int n, target;
	cin >> n >> target;
  
	int* nums = new int[n];   //****从键盘输入若干个数字存到数组！！
	int i = 0;
	while (i<n)
	{
		cin >> nums[i];
		i++;
	}
  
	int left = 0, right = n - 1;
	if (right == left)
	{
		if (nums[0] == target)
			cout << 0;
		else
			cout << -1;
		return 0;
	}
	int mid;
	int flag = 0;
	while (left <= right)
	{
		mid = left + ((right - left) >> 1);
		if (nums[mid] == target)
		{
			//return mid;
			flag = 1;
			break;
		}
		else if (nums[mid]>target)
			right = mid - 1;
		else
			left = mid + 1;
	}
	
	if (flag)
		cout << mid;
	else
		cout << -1;
	return 0;
}
```

## 总结
MDZZ，牛客网竟然输出必须使用cout打印！而不是return，耽误我好多时间！
