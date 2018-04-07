//lintCode���ӣ�һ������������㷨�⣬������ԣ�http://www.lintcode.com/zh-cn/problem/sort-integers/

#include<iostream>
#include<vector>
#include<ctime>
using namespace std;

//ð������ʱ�临�Ӷ� 1/2*n^2, �ռ临�Ӷ� O(1)�� �ȶ�
void BubbleSort(vector<int> &A) {
	int n = A.size();
	if (n <= 1) return;
	for (int i = 0; i<n; i++) {
		for (int j = 0; j<n - i - 1; j++) {
			if (A[j] > A[j + 1])				// ��������ĳ�A[i] >= A[i + 1],���Ϊ���ȶ��������㷨
				swap(A[j], A[j + 1]);
		}
	}
	return;
}

//ѡ������ʱ�临�Ӷ� 1/2*n^2, �ռ临�Ӷ� O(1)�� �ȶ�
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

//��׼�Ĳ�������ʱ�临�Ӷ� 1/4*n^2, ��ϵ����С�����Ա�ð�ݺ�ѡ�������һ�㡣�ռ临�Ӷ� O(1)�� �ȶ�
void SelectSort2(vector<int> &A) {
	int n = A.size();
	if (n <= 1) return;
	for (int i = 1; i<n; i++) {
		int cur = A[i];
		int j = i - 1;
		while (j >= 0 && A[j] > cur) {		//�������Ų
			A[j + 1] = A[j];
			j--;
		}
		A[++j] = cur;
	}
	return;
}


//�������������ֲ��ң���Ϊǰ�沿���Ѿ��ź����Ҳ���λ�ÿ����ö��ֲ���
void SelectSortPlusBinarySearch(vector<int> &A) {
	int n = A.size();
	if (n <= 1) return;
	//insert sort plus binary search
	for (int i = 1; i<n; i++) {
		int left = 0;
		int right = i - 1;
		int cur = A[i];
		while (left <= right) {   //�ҵ����һ��С�ڵ��������� lower_bound �� upper_bound
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


//Shell sort:��Լģʽ
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


//Shell sort2:���淶һЩ��Shell sort���Ƚ�����������������ð������
//�������úܽ�������ͬ�Ĳ������У�ʱ�临�ӶȲ�һ��
//ʱ�临�Ӷ� �벽���й�,����O(n^(2/3))��O(n^2)֮�䡣 �ռ临�Ӷ� O(1)�� ���ȶ�
void ShellSort2(vector<int> &A) {
	int n = A.size();
	if (n <= 1) return;
	int h = 1;
	while (h < n/3)							//��ó�ʼ����
		h = 3 * h + 1;
	while (h >= 1)
	{
		for (int i = h; i < n; i++)
		{
			int j = i - h;
			int get = A[i];
			while (j >= 0 && A[j] > get)	//С�ĺ���
			{
				A[j + h] = A[j];
				j = j - h;
			}
			A[j + h] = get;
		}
		h = (h - 1) / 3;                    // �ݼ�����
	}
}

//�鲢����
//ʱ�临�Ӷ� O(nlogn), �ռ临�Ӷ� O(n)�� �ȶ�
vector<int> merge(const vector<int>& v1, const vector<int>& v2) {
	int n = v1.size();
	int m = v2.size();
	vector<int> res(n + m);
	int index = 0, i = 0, j = 0;
	for (; i<n && j <m; ) {
		if (v1[i] <= v2[j])  // ���Ⱥű�֤�鲢������ȶ���
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

//�ݹ�Ĺ鲢���򣬻��е�����
vector<int> mergeSortRecursive(vector<int>& v, int left, int right) {
	int n = right - left + 1;
	if (n == 1) return{ v[left] };
	int mid = left + (right - left) / 2;
	vector<int> leftRes = mergeSortRecursive(v, left, mid);         //����ұ�
	vector<int> rightRes = mergeSortRecursive(v, mid + 1, right);
	vector<int> res = merge(leftRes, rightRes);
	return res;
}


//��������
//ʱ�临�Ӷ� O(nlogn), �ռ临�Ӷ� �����ֵĴ����йأ�һ��O(logn)�� ���ȶ�
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

//������ heap sort
//ʱ�临�Ӷ� O(nlogn), �ռ临�Ӷ� O(1)�� ���ȶ�
void heapify(vector<int>& heap, int i, int size) {
	int leftChild = 2 * i + 1;
	int rightChild = 2 * i + 2;
	/*if (i <= size / 2 - 1) {									//�������
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