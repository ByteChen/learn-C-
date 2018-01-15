## [问题](https://www.nowcoder.com/practice/e8a1b01a2df14cb2b228b30ee6a92163?tpId=13&tqId=11181&tPage=2&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)
数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。

例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。

由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。如果不存在则输出0。

## 代码
#### 方法一：直接法, 采用unordered_map，对每个数字计数。时间复杂度应该是O(n),空间复杂度O(n)
```C++
int MoreThanHalfNum_Solution(vector<int> numbers) {
        int N = numbers.size();
        unordered_map<int, int> m;
        for(int i=0; i<N; i++)
        {
            if((++m[numbers[i]])>N/2)
                return numbers[i];
        }
        return 0;   
    }
```

#### 方法二：排序。如果存在超过数组长度的一半的数，则排序后中间的数必是那个数。time: O(nlogn), space: O(1)
```C++
int MoreThanHalfNum_Solution(vector<int> numbers) {
        sort(numbers.begin(), numbers.end());
        int mid =  numbers[numbers.size()/2];
        auto left = lower_bound(numbers.begin(), numbers.end(), mid);
        auto right = upper_bound(numbers.begin(), numbers.end(), mid);
        int cnt = int (right - left);
        if(cnt <= numbers.size()/2)
            return 0;
        return mid;
    }
```

#### 方法三：剑指offer的方法，O(n), O(1)
* 思路：
```
采用阵地攻守的思想：
第一个数字作为第一个士兵，守阵地；count = 1；
遇到相同元素，count++;
遇到不相同元素，即为敌人，同归于尽,count--；
当遇到count为0的情况，又以新的i值作为守阵地的士兵，
继续下去，到最后还留在阵地上的士兵，有可能是主元素。
再加一次循环，记录这个士兵的个数看是否大于数组一般即可。
```
```C++
int MoreThanHalfNum_Solution(vector<int> numbers) {
        int res, cnt = 0;
        int N = numbers.size();
        
        for(int i=0; i<N; i++)
        {
            if(cnt == 0)
            {
                res = numbers[i];
                cnt = 1;
            }
            else if(numbers[i] == res)
                cnt ++;
            else
                cnt --;
        }
        
        cnt = 0;
        for(int each : numbers)
            if(each == res)
                cnt ++;
        if(cnt > N/2)
            return res;
        return 0;
    }
```
