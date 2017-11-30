## 问题
Given a sorted array, two integers k and x, find the k closest elements to x in the array. The result should also be sorted in ascending order. If there is a tie, the smaller elements are always preferred.

Example 1:
```
Input: [1,2,3,4,5], k=4, x=3
Output: [1,2,3,4]
```
Example 2:
```
Input: [1,2,3,4,5], k=4, x=-1
Output: [1,2,3,4]
```
Note:
1. The value k is positive and will always be smaller than the length of the sorted array.
2. Length of the given array is positive and will not exceed 10^4.
3. Absolute value of elements in the array and x will not exceed 10^4.

## 代码
```C++
vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> result(k);  //最好初始化时设定容量，后面copy就不需要使用back_inserter了
        auto size = arr.size();
        if(x<=arr[0]) 
        {
            copy(arr.begin(),arr.begin()+k,result.begin()); //左闭右开
            return result;
        }
        if(x>=arr[size-1])
        {
            copy(arr.end()-k,arr.end(),result.begin());
            return result;
        }
        
        int i;
        for( i=0; i<size-k; i++)
        {
            if(arr[i+k] < x) continue;
            else if(x - arr[i] > arr[i+k] - x) continue;
            else break;
        }
        int cnt=0;
        while(cnt != k)
        {
            result[cnt] = arr[i];
            i++;
            cnt++;
        }
        return result;
    }
```

Note:
  发现这个题目在我做过之后被官方修改过，所以状态变成attempt，而不是accept。以前的总结在 [Here](https://github.com/ByteChen/learn-CPP/blob/master/LeetCode%20Summary/medium-658.%20Find%20K%20Closest%20Elements.md)
  
