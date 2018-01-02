## [问题](https://leetcode.com/problems/min-cost-climbing-stairs/description/)
On a staircase, the i-th step has some non-negative cost cost[i] assigned (0 indexed).

Once you pay the cost, you can either climb one or two steps. You need to find minimum cost to reach the top of the floor, and you can either start from the step with index 0, or the step with index 1.

Example 1:
```
Input: cost = [10, 15, 20]
Output: 15
Explanation: Cheapest is start on cost[1], pay that cost and go to the top.
```
Example 2:
```
Input: cost = [1, 100, 1, 1, 1, 100, 1, 1, 100, 1]
Output: 6
Explanation: Cheapest is start on cost[0], and only step on 1s, skipping cost[3].
```
Note:
1. cost will have a length in the range [2, 1000].
2. Every cost[i] will be an integer in the range [0, 999].

## 代码
```C++
class Solution {
public:
  //方法1：
    int minCostClimbingStairs(vector<int>& cost) {
        int N = cost.size();
        if(N == 0) return 0;
        if(N == 1) return cost[0];
        //if(N == 2) return getMin(cost[0], cost[1]);
        int dp[N+1];
        dp[0] = 0;
        dp[1] = 0;
        for(int i=2; i<=N; i++)
        {
            dp[i] = getMin(dp[i-2]+cost[i-2], dp[i-1]+cost[i-1]);
        }
        return dp[N];
    }
    
    int getMin(int a, int b)
    {
        return a > b ? b : a;
    }
    
    //methon 2: O(1) space complexity
    int minCostClimbingStairs(vector<int>& cost) {
        int N = cost.size();
        if(N == 0) return 0;
        if(N == 1) return cost[0];
        int i_2 = 0;
        int i_1 = 0;
        int temp;
        for(int i=2; i<=N; i++)
        {
            temp = i_1;
            i_1 = getMin(i_1+cost[i-1], i_2+cost[i-2]);
            i_2 = temp;
        }
        return i_1;
    }
};
```
