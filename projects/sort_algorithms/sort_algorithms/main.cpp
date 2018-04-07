//lintCode链接，一道整数排序的算法题，方便测试：http://www.lintcode.com/zh-cn/problem/sort-integers/

#include<iostream>
#include<vector>
#include<ctime>
using namespace std;

//冒泡排序，时间复杂度 1/2*n^2, 空间复杂度 O(1)， 稳定
void BubbleSort(vector<int> &A) {
	int n = A.size();
	if (n <= 1) return;
	for (int i = 0; i<n; i++) {
		for (int j = 0; j<n - i - 1; j++) {
			if (A[j] > A[j + 1])				// 如果条件改成A[i] >= A[i + 1],则变为不稳定的排序算法
				swap(A[j], A[j + 1]);
		}
	}
	return;
}

//选择排序：时间复杂度 1/2*n^2, 空间复杂度 O(1)， 稳定
void SelectSort(vector<int> &A) {
	int n = A.size();
	if (n <= 1) return;
	for (int i = 0; i<n; i++) {
		int max = 0;
		for (int j = 1; j<n - i; j++) {
			if (A[max] < A[j])
				max = j;
		}
		if (max != n - i - 1)
			swap(A[max], A[n - i - 1]);
	}
	return;
}

//标准的插入排序：时间复杂度 1/4*n^2, 常系数较小，所以比冒泡和选择排序好一点。空间复杂度 O(1)， 稳定
void SelectSort2(vector<int> &A) {
	int n = A.size();
	if (n <= 1) return;
	for (int i = 1; i<n; i++) {
		int cur = A[i];
		int j = i - 1;
		while (j >= 0 && A[j] > cur) {		//大的往后挪
			A[j + 1] = A[j];
			j--;
		}
		A[++j] = cur;
	}
	return;
}


//插入排序加入二分查找，因为前面部分已经排好序，找插入位置可以用二分查找
void SelectSortPlusBinarySearch(vector<int> &A) {
	int n = A.size();
	if (n <= 1) return;
	//insert sort plus binary search
	for (int i = 1; i<n; i++) {
		int left = 0;
		int right = i - 1;
		int cur = A[i];
		while (left <= right) {   //找到最后一个小于等于它的数 lower_bound ？ upper_bound
			int mid = (left + right) / 2;
			if (A[mid] <= A[i])
				left = mid + 1;
			else
				right = mid - 1;
		}

		for (int j = i; j>left; j--)
			A[j] = A[j - 1];
		A[left] = cur;
	}
	return;
}


//Shell sort:简约模式
void ShellSort(vector<int> &A) {
	int n = A.size();
	if (n <= 1) return;
	for (int step = n / 2; step>0; step /= 2) {
		for (int i = step; i<n; i++)
			for (int j = i - step; j >= 0 && A[j] > A[j + step]; j -= step) {
				swap(A[j], A[j + step]);
			}
	}
}


//Shell sort2:更规范一些的Shell sort，比较像插入排序，上面的像冒泡排序
//步长设置很讲究，不同的步长序列，时间复杂度不一样
//时间复杂度 与步长有关,介于O(n^(2/3))和O(n^2)之间。 空间复杂度 O(1)， 不稳定
void ShellSort2(vector<int> &A) {
	int n = A.size();
	if (n <= 1) return;
	int h = 1;
	while (h < n/3)							//获得初始步长
		h = 3 * h + 1;
	while (h >= 1)
	{
		for (int i = h; i < n; i++)
		{
			int j = i - h;
			int get = A[i];
			while (j >= 0 && A[j] > get)	//小的后移
			{
				A[j + h] = A[j];
				j = j - h;
			}
			A[j + h] = get;
		}
		h = (h - 1) / 3;                    // 递减增量
	}
}

//归并排序
//时间复杂度 O(nlogn), 空间复杂度 O(n)， 稳定
vector<int> merge(const vector<int>& v1, const vector<int>& v2) {
	int n = v1.size();
	int m = v2.size();
	vector<int> res(n + m);
	int index = 0, i = 0, j = 0;
	for (; i<n && j <m; ) {
		if (v1[i] <= v2[j])  // 带等号保证归并排序的稳定性
			res[index++] = v1[i++];
		else
			res[index++] = v2[j++];
	}
	if (i == n)
		while (j<m)
			res[index++] = v2[j++];
	else
		while (i<n)
			res[index++] = v1[i++];
	return res;
}

//递归的归并排序，还有迭代的
vector<int> mergeSortRecursive(vector<int>& v, int left, int right) {
	int n = right - left + 1;
	if (n == 1) return{ v[left] };
	int mid = left + (right - left) / 2;
	vector<int> leftRes = mergeSortRecursive(v, left, mid);         //左闭右闭
	vector<int> rightRes = mergeSortRecursive(v, mid + 1, right);
	vector<int> res = merge(leftRes, rightRes);
	return res;
}


//快速排序
//时间复杂度 O(nlogn), 空间复杂度 跟划分的次数有关，一般O(logn)， 不稳定
int partition(vector<int>& v, int left, int right) {
	if (left >= right) return -1;
	srand(time(0));
	int randomIndex = rand() % (right - left) + left;
	int key = v[randomIndex];
	std::swap(v[randomIndex], v[right]);
	int small = left - 1;
	while (left < right) {
		if (v[left] <= key) {
			small++;
			if (small != left)
				std::swap(v[small], v[left]);
		}
		left++;
	}
	std::swap(v[++small], v[right]);
	return small;
}

void quickSort(vector<int>& v, int left, int right) {
	if (left >= right) return;

	int n = right - left + 1;
	int index = partition(v, left, right);
	quickSort(v, left, index - 1);
	quickSort(v, index + 1, right);
}

//堆排序 heap sort
//时间复杂度 O(nlogn), 空间复杂度 O(1)， 不稳定
void heapify(vector<int>& heap, int i, int size) {
	int leftChild = 2 * i + 1;
	int rightChild = 2 * i + 2;
	/*if (i <= size / 2 - 1) {									//不可如此
		int max = heap[leftChild] >= heap[rightChild] ?
			(heap[leftChild] > heap[i] ? leftChild : i) :
			(heap[rightChild] > heap[i] ? rightChild : i);*/
	int max = i;
	if (leftChild < size && heap[leftChild] > heap[max])
		max = leftChild;
	if (rightChild < size && heap[rightChild] > heap[max])
		max = rightChild;
	if (max != i) {
		std::swap(heap[max], heap[i]);
		heapify(heap, max, size);
	}
}

void buildHeap(vector<int>& heap) {
	int size = heap.size();
	if (size <= 1) return;
	for (int i = size / 2 - 1; i >= 0; i--) {
		heapify(heap, i, size);
	}
}


int main() {
	vector<int> A = { 3,2,1,4,5 };
	int n = A.size();
	buildHeap(A);
	for (int i = n - 1; i>0; i--) {
		std::swap(A[0], A[i]);
		heapify(A, 0, i);
	}
	for (auto each : A)
		cout << each << " ";
	getchar();
	return 0;
}