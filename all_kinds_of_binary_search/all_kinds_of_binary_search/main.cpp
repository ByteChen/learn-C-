#include<iostream>
#include<vector>
#include<set>

using namespace std;


//һ��������ֲ��ң�����target�������±꣬���Ҳ���������-1
int bin_search(vector<int> &a, int target)
{
	int low= 0, high, mid;
	high = a.size() - 1;	//����������ұ�Ҳ�Ǳ�����
	while (low <= high)
	{
		mid = low + (high - low)/2;		//��Ҫ mid = (low+high��/2�����ܻ����
		if (a[mid] == target)
			return mid;
		else if (a[mid] > target)
			high = mid - 1;
		else
			low = mid + 1;
	}
	return -1;
}


//����������ֲ��ҵĵݹ�ʵ��
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



//�������ҵ�һ�����ڵ���ĳ�������±�
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
	return low;	//��Ϊ�Ҳ����򷵻���һ���ɲ����λ�ã���Ҫ���Ҳ���ʱ����-1���� return low >= a.size() ? -1: low;
}


//�ġ����ҵ�һ������ĳ�������±�
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
	return low;	//��Ϊ�Ҳ����򷵻���һ���ɲ����λ�ã���Ҫ���Ҳ���ʱ����-1���� return low >= a.size() ? -1: low;
}

int main()
{
	vector<int> a{ 1,2,2,2,4,8,10 };
	vector<int> b{ 5,2,2,2,4,16,8,10 };
	
	cout << "������ֲ���test��" << bin_search(a, 3) << endl;
	cout << "������ֲ��� �ݹ�ʵ��test��" << bin_search_recursive(a, 0, a.size() - 1, 4) << endl;

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