## [问题](https://leetcode.com/problems/longest-increasing-subsequence/description/)
Given an unsorted array of integers, find the length of longest increasing subsequence.

For example,
Given [10, 9, 2, 5, 3, 7, 101, 18],
The longest increasing subsequence is [2, 3, 7, 101], therefore the length is 4. Note that there may be more than one LIS combination, it is only necessary for you to return the length.

Your algorithm should run in O(n^2) complexity.

**Follow up**: Could you improve it to O(n log n) time complexity?

## 代码
```C++
//O(n^2) complexity
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int N = nums.size();
        if(N<=1) return N;
        vector<int> dp(N);
        dp[0] = 1;
        int max=0;
        for(int i=1; i<N; i++)
        {
            dp[i] = getMax(nums, nums[i], dp, i-1) + 1;
            max = dp[i] > max ? dp[i] : max;
        }
        return max;
    }
    
    int getMax(vector<int>& nums, int target, vector<int>& dp, int right)
    {
        int max = 0;
        for(int i=0; i<=right; i++)
        {
            if(nums[i] < target)
                max = dp[i] > max ? dp[i] : max;
        }
        return max;
    }
};
```

## 其他优化
1. [Short C++ STL-based solution: O(n log n) time, O(1) space, with explanation](https://discuss.leetcode.com/topic/38503/short-c-stl-based-solution-o-n-log-n-time-o-1-space-with-explanation)
。但不是动态规划。
2. [Construction of Longest Increasing Subsequence (N log N)](https://www.geeksforgeeks.org/construction-of-longest-monotonically-increasing-subsequence-n-log-n/)
