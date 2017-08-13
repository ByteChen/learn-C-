## 问题
Given a sorted array, two integers k and x, find the k closest elements to x in the array. 
The result should also be sorted in ascending order. 
If there is a tie, the smaller elements are always preferred.

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
2. Length of the given array is positive and will not exceed 10^4
3. Absolute value of elements in the array and x will not exceed 10^4

## 代码
```C++
class Solution {
public:
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
        
        //当x在数组范围内，比较难处理。参考了别人的“滑动窗口”方法，就简单了
        list<int> ls;   //list能够方便的pop_front()
        for(int i = 0; i< size; i++)
        {
            if(ls.size()<k)
                ls.push_back(arr[i]);
            else
            {
                if(abs(arr[i]-x) < abs(x-ls.front()))
                {
                    ls.push_back(arr[i]);
                    ls.pop_front();
                }
            }
        }
        copy(ls.begin(),ls.end(),result.begin());
        return result;
    }
    
    int abs(int a)
    {
        return a>0?a:-a;
    }
};
```

# 总结
这是leetcode本周竞赛题第二题，本来想着很难的，一个小时没写出来。后来看别人的答案，使用**滑动窗口**的方法，很简单就能完成。

算法的东西，有时候做不出来，只是因为想不到正确的方法；想到了，两下就写出来了。

所以还是要遍刷群题，博闻强记。
