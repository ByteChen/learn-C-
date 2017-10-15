## 问题
Median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value. So the median is the mean of the two middle value.

Examples: 
[2,3,4] , the median is 3

[2,3], the median is (2 + 3) / 2 = 2.5

Given an array nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position. Your job is to output the median array for each window in the original array.

For example,
Given **nums = [1,3,-1,-3,5,3,6,7]**, and *k* = 3.
```
Window position                Median
---------------               -----
[1  3  -1] -3  5  3  6  7        1
 1 [3  -1  -3] 5  3  6  7       -1
 1  3 [-1  -3  5] 3  6  7       -1
 1  3  -1 [-3  5  3] 6  7        3
 1  3  -1  -3 [5  3  6] 7        5
 1  3  -1  -3  5 [3  6  7]       6
 ```
Therefore, return the median sliding window as **[1,-1,-1,3,5,6]**.

Note: 
You may assume k is always valid, ie: k is always smaller than input array's size for non-empty array.

## 代码
```C++
class Solution {
public:
    //方法一：通过率30/42，当窗口长度=3000+时，运行超时
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        //if(k == 1) return nums;
        vector<double> result;
        for(int i=0; i<=nums.size()-k; i++)
        {
            result.push_back(getMedian(nums,i,k));
        }
        return result;
    }
    
    double getMedian(vector<int>& nums, int left, int k)
    {
        //使用 make_heap(): 并没有排序功能。。。不如直接sort来得干脆
        vector<int> temp(nums.begin()+left,nums.begin()+left+k);
        //make_heap(temp.begin(), temp.end());
        sort(temp.begin(), temp.end());
        if(k%2 == 1)
            return temp[k/2];
        else if(k%2 == 0)
            //return ((double)(temp[k/2]+temp[k/2-1]))/2.0;   //若先加，可能会两个正数之和超出int表示范围从而变成负数。
            return (double)temp[k/2]/2.0 + (double)temp[k/2-1]/2.0;
    }
    
    
    //方法二：multiset
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
    multiset<int> window(nums.begin(), nums.begin() + k);
    auto mid = next(window.begin(), k / 2);
    vector<double> medians;
    for (int i=k; ; i++) {

        // Push the current median.
        medians.push_back((double(*mid) + *prev(mid, 1 - k%2)) / 2);

        // If all done, return.
        if (i == nums.size())
            return medians;
            
        // Insert nums[i].
        window.insert(nums[i]);
        if (nums[i] < *mid)
            mid--;

        // Erase nums[i-k].
        if (nums[i-k] <= *mid)
            mid++;
        window.erase(window.lower_bound(nums[i-k]));
       }
    }
    
};
```

## 总结
* 上面代码使用到了 next（）、 prev（）等函数，用来将迭代器左移或者右移若干位。
* 在set中，数据都是有序的，默认从小到大。在有序的数列中，想要删除某个数，使用window.erase(window.lower_bound(nums[i-k]))， 
  也就是 erase（）+ lower_bound（target）的组合操作，可以删除target。
* 在顺序容器中，使用sort（）、lower_bound（）、upper_bound（）、find（）等STL算法，一般都不是成员函数方式访问，
  而是 sort(xx.begin(), xx.end(), xxx) 之类；
  而在关联容器中，一般则是成员函数方式访问，比如 iset.find(target) 这种。可以参考一下STL源码分析。
