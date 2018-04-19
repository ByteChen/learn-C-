## 一、[55. Jump Game](https://leetcode.com/problems/jump-game/description/)  难度：medium
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

Example 1:
```
Input: [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
```
Example 2:
```
Input: [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum
             jump length is 0, which makes it impossible to reach the last index.
```

### 代码
* 尽管可以使用queue实现，但是很慢。只需要两个循环嵌套，利用left和right即可。
```C++
bool canJump(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1) return true;
        int left=0, right=0;
        while(left <= right) {
            //if(left == right && nums[left] == 0)
                //return false;
            int curRight = right;
            for(int i=left; i<=curRight; i++) {
                //right = right >= (i+nums[i]) ? right : (i+nums[i]);
                if(i+nums[i] > right)
                    right = i+nums[i];
                if(right >= n-1)
                    return true;
            }
            left = curRight+1;
        }
        return false;
    }
```




## 二、题目升级：[45. Jump Game II](https://leetcode.com/problems/jump-game-ii/description/)   难度：hard
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

Example:
```
Input: [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2.
    Jump 1 step from index 0 to 1, then 3 steps to the last index.
```
* Note:
You can assume that you can always reach the last index.

### 代码
* 和上一题思路一样的，多增加一个level对数组经行分层。level=1表示一步可达，level=2表示两跳可达...
```C++
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1) return 0;
        int level = 0;
        int left=0, right=0;
        while(left <= right) {
            level ++;
            int curRight = right;
            for(int i=left; i<=curRight; i++) {
                if(i+nums[i] >= n-1)
                    return level;
                else if(i+nums[i] > right)
                    right = i+nums[i];
            }
            left = curRight+1;
        }
    }
};
```
