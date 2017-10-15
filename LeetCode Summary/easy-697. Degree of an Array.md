## 问题
Given a non-empty array of non-negative integers nums, the degree of this array is defined as the maximum frequency of any one of its elements.

Your task is to find the smallest possible length of a (contiguous) subarray of nums, that has the same degree as nums.

Example 1:
```
Input: [1, 2, 2, 3, 1]
Output: 2
Explanation: 
The input array has a degree of 2 because both elements 1 and 2 appear twice.
Of the subarrays that have the same degree:
[1, 2, 2, 3, 1], [1, 2, 2, 3], [2, 2, 3, 1], [1, 2, 2], [2, 2, 3], [2, 2]
The shortest length is 2. So return 2.
```
Example 2:
```
Input: [1,2,2,3,1,4,2]
Output: 6
```
Note:
* **nums.length** will be between 1 and 50,000.
* **nums[i]** will be an integer between 0 and 49,999.

## 分析
由于最大的 degree of array 可能有不止一种情况，就像example 1中那样，
1和2的degree都是2，这时候1和2分别有一个最小子序列，最终从这两个中选择较短一个即为所求。

所以此题首先需要求出最大的degree对应有几个数字，然后分别求出各个数字对应的最小子序列长度，最后选择最小的，即可。

**求数组中出现次数最多的数字**，当然就是使用**map**来求。

## 代码
### 方法一：
* 我的方法，使用map计数，然后对该map，依据value值从大到小排序，然后从排序后的结果从头往后开始计算子序列长度，选择最小的。
* 对value进行排序时，需要**自定义用于比较的函数或者函数对象**。
* 参考好博客：[C++ STL中Map的按Key排序和按Value排序](http://blog.csdn.net/acidgl8757/article/details/17416439)

```C++
class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        map<unsigned int, unsigned int> m;
        for(int i=0; i<nums.size(); i++)
        {
            m[nums[i]] ++;
        }
        
        vector<pair<unsigned int, unsigned int>> v(m.begin(), m.end()); //看别人对map按value进行排序，都需要先把map拷贝到vector里：因为sort（）函数只能对顺序容器使用
        sort(v.begin(), v.end(), CmpByValue());
        
        int min_len = -1, len;
        for(int i=0; i<v.size(); i++)
        {
            if(i!=0 && v[i].second<v[0].second)
                break;
            len = nums.size() - (find(nums.rbegin(), nums.rend(), v[i].first) - nums.rbegin())    //计算每个子序列长度
                  - (find(nums.begin(), nums.end(),v[i].first) - nums.begin());
            if(min_len == -1)
                min_len = len;
            min_len = min_len<len ? min_len:len;
        }
        return min_len;
    }
    
    //在sort（）函数中使用的函数对象,用作从大到小排序
    struct CmpByValue {  
        bool operator() (const pair<unsigned int, unsigned int>& lhs, const pair<unsigned int, unsigned int>& rhs) 
        {                 
              return lhs.second > rhs.second;  
        }  
    };
}; 
```

### 方法二：
* 上面我自己的方法过于繁琐。这道题是leetcode本周竞赛题，我的方法跑完所有测试用例的耗时是106ms，下面参考的别人的方法，只需要56ms。
* 下面这种方法，将每个数字的的第一次出现位置和最后一次出现位置也都保存在另一个map中，
   同时不停更新最大的degree of array。最后只需要再一次遍历数组，对于出现次数最多的数字，
   计算其子序列长度，取最小的即可。

#### 按照别人思路自己写的代码：
```C++
int findShortestSubArray(vector<int>& nums) {
        map<int,int> cnt, left, right;
        int max_count = 0;
        for(int i=0; i<nums.size(); i++)
        {
            int v = nums[i];
            cnt[v]++;
            max_count = max_count>(++cnt[v]) ? max_count : cnt[v];  //计算出现次数最多的数字
            if(left.find(v) == left.end())  
                left[v] = i;        //对于数组中每个数字，如果left中还没有这个数，则创建这个数，并记录其左起第一个坐标
            right[v] = i;           //该数字的右坐标不断更新，知道最后一次出现
        }
        
        int min_len = -1, len;
        for(int i=0; i<nums.size(); i++)
        {
            int v = nums[i];
            if(cnt[v] == max_count)
            {
                len = right[v] - left[v] + 1;
                if(min_len == -1)
                    min_len = len;
                else 
                    min_len = min_len<len? min_len : len;
            }
        }
        return min_len;
    }
```

#### 别人的原始代码,相比于上面我写的，更完美：
```C++
int findShortestSubArray(vector<int>& a) {
        map<int, int> cnt, mx, mi;
        int deg = 0;
        for (int i = 0; i < a.size(); ++i) {
            int x = a[i];
            deg = max(deg, ++cnt[x]);
            if (cnt[x] == 1) {              //我上面使用的是find（）函数，效率不如这样写来得好
                mx[x] = mi[x] = i;
            } else {
                mx[x] = i;
            }
        }
        int ans = a.size();           //第二次循环，确实没必要遍历这个数组nums，只需要遍历cnt就好了。ans这样初始化，也很美~~
        for (auto it : cnt) {         //map中每个元素都是一个pair，故可以使用first、second范围
            if (it.second == deg) {
                ans = min(ans, mx[it.first] - mi[it.first] + 1);
            }
        }
        return ans;
    }
```
