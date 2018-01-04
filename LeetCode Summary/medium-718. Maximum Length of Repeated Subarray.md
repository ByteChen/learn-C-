## [问题](https://leetcode.com/problems/maximum-length-of-repeated-subarray/description/)
Given two integer arrays A and B, return the maximum length of an subarray that appears in both arrays.

Example 1:
```
Input:
A: [1,2,3,2,1]
B: [3,2,1,4,7]
Output: 3
Explanation: 
The repeated subarray with maximum length is [3, 2, 1].
```
Note:
1. 1 <= len(A), len(B) <= 1000
2. 0 <= A[i], B[i] < 100

## 代码
#### 错误的方法
* 错误思想：建立一个```dp[A.size()][B.size()]```数组，```dp[i][j]```表示```A[0：i]``` 与 ```B[0:j]```的最长公共子序列。
```C++
class Solution {
public:
    //wrong solution:
    int findLength(vector<int>& A, vector<int>& B) {
        int N = A.size();
        int M = B.size();
        vector<vector<int>> dp(N, vector<int>(M, 0));
        
        //先把第一行第一列搞定
        for(int i=0; i<N; i++)
        {
            if(A[i] == B[0])
                dp[i][0] = 1;
            else if(i == 0)
                dp[i][0] = 0;
            else
                dp[i][0] = dp[i-1][0];
        }
        
        for(int i=0; i<M; i++)
        {
            if(B[i] == A[0])
                dp[0][i] = 1;
            else if(i == 0)
                dp[0][i] = 0;
            else
                dp[0][i] = dp[0][i-1];
        }
        
        int max = 0;
        for(int i=1; i<N; i++)
            for(int j=1; j<M; j++)
            {
                if(A[i] == B[j])
                    dp[i][j] = dp[i-1][j-1] + 1;
                else
                    dp[i][j] = dp[i-1][j] > dp[i][j-1] ? dp[i-1][j] : dp[i][j-1];
                max = max >= dp[i][j] ? max : dp[i][j];
            }
        return max;
    }
};
```

#### 正确的方法：
* 正确的思想：建立一个```dp[A.size()+1][B.size()+1]```数组，```dp[i][j]```表示以 ```A[i]``` 和 ```B[j]``` **结尾** 的最长公共子序列。
```C++
 int findLength(vector<int>& A, vector<int>& B) {
        int N = A.size();
        int M = B.size();
        vector<vector<int>> dp(N+1, vector<int>(M+1, 0));
        
        int max = 0;
        for(int i=0; i<=N; i++)
            for(int j=0; j<=M; j++)
            {
                if(i==0 || j==0)
                    dp[i][j] = 0;
                else if(A[i-1] == B[j-1])
                {
                    dp[i][j] = dp[i-1][j-1] + 1;
                    max = max >= dp[i][j] ? max : dp[i][j];
                }
            }
        return max;
    }
```

## 参考
1. [Java O(mn) time, O(1) space](https://discuss.leetcode.com/topic/109751/java-o-mn-time-o-1-space)
2. [Concise Java DP: Same idea of Longest Common Substring](https://leetcode.com/problems/maximum-length-of-repeated-subarray/discuss/109039/)
