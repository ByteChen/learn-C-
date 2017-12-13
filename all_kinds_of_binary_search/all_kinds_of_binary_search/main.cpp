#include<iostream>
#include<vector>
#include<set>

using namespace std;


//一、经典二分查找，查找target，返回下标，若找不到，返回-1
int bin_search(vector<int> &a, int target)
{
	int low= 0, high, mid;
	high = a.size() - 1;	//最好像这样右边也是闭区间
	while (low <= high)
	{
		mid = low + (high - low)/2;		//不要 mid = (low+high）/2，可能会溢出
		if (a[mid] == target)
			return mid;
		else if (a[mid] > target)
			high = mid - 1;
		else
			low = mid + 1;
	}
	return -1;
}


//二、经典二分查找的递归实现
int bin_search_recursive(vector<int> &a, int low, int high, int target)
{
	if (low > high)
		return low;
	int mid = low + (high - low) / 2;
	if (a[mid] == target)
		return mid;
	else if (a[mid] > target)
		return bin_search_recursive(a, low, mid - 1, target);
	else
		return bin_search_recursive(a, mid + 1, high, target);
	return -1;
}



//三、查找第一个大于等于某个数的下标
int bin_search_lower_bound(vector<int> &a, int low, int high, int target)
{
	int mid;
	while (low <= high)
	{
		mid = low + ((high - low) >> 1);
		if (a[mid] >= target)
			high = mid - 1;
		else if (a[mid] < target)
			low = mid + 1;
	}
	return low;	//认为找不到则返回下一个可插入的位置，若要在找不到时返回-1，则 return low >= a.size() ? -1: low;
}


//四、查找第一个大于某个数的下标
int bin_search_upper_bound(vector<int> &a, int low, int high, int target)
{
	int mid;
	while (low <= high)
	{
		mid = low + ((high - low) >> 1);
		if (a[mid] > target)
			high = mid - 1;
		else
			low = mid + 1;
	}
	return low;	//认为找不到则返回下一个可插入的位置，若要在找不到时返回-1，则 return low >= a.size() ? -1: low;
}

int main()
{
	vector<int> a{ 1,2,2,2,4,8,10 };
	vector<int> b{ 5,2,2,2,4,16,8,10 };
	
	cout << "经典二分查找test：" << bin_search(a, 3) << endl;
	cout << "经典二分查找 递归实现test：" << bin_search_recursive(a, 0, a.size() - 1, 4) << endl;

	cout << "lower_bound:" << bin_search_lower_bound(a, 0, a.size() - 1, 2) << endl;
	cout << "upper_bound:" << bin_search_upper_bound(a, 0, a.size() - 1, 2) << endl;


	multiset<int> s(b.begin(), b.end());
	for (auto iter = s.begin(); iter != s.end(); iter++)
		cout << *iter << ' ';

	vector<int> c(s.begin(), s.end());
	for (auto iter = c.begin(); iter != c.end(); iter++)
		cout << *iter << ' ';
	system("pause");
	return 0;
}