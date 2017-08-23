## 问题
Given an integer array, find three numbers whose product is maximum and output the maximum product.

Example 1:
```
Input: [1,2,3]
Output: 6
```
Example 2:
```
Input: [1,2,3,4]
Output: 24
```
Note:
* The length of the given array will be in range [3,104] and all elements are in the range [-1000, 1000].
* Multiplication of any three numbers in the input won't exceed the range of 32-bit signed integer.

## 代码
```C++
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        /*
        if(nums.size() < 3) return {};
        int max, min;
        max = min = nums[0]*nums[1]*nums[2];
        for(int i=3; i<nums.size(); i++)
        {
            max = getmax(max, max*nums[i], min*nums[i]);
            min = getmin(min, max*nums[i], min*nums[i]);
        }
        return max;
        */
        //真是想到则不难，数组问题 想想排序 再 处理！
        sort(nums.begin(),nums.end());
        int size = nums.size();
        return nums[0]*nums[1]*nums[size-1] > nums[size-1]*nums[size-2]*nums[size-3] ? 
            nums[0]*nums[1]*nums[size-1] : nums[size-1]*nums[size-2]*nums[size-3];
    }
};
```
