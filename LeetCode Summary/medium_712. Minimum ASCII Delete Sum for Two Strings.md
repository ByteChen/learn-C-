## [问题](https://leetcode.com/contest/leetcode-weekly-contest-55/problems/minimum-ascii-delete-sum-for-two-strings/)
Given two strings s1, s2, find the lowest ASCII sum of deleted characters to make two strings equal.

Example 1:
```
Input: s1 = "sea", s2 = "eat"
Output: 231
Explanation: Deleting "s" from "sea" adds the ASCII value of "s" (115) to the sum.
Deleting "t" from "eat" adds 116 to the sum.
At the end, both strings are equal, and 115 + 116 = 231 is the minimum sum possible to achieve this.
```
Example 2:
```
Input: s1 = "delete", s2 = "leet"
Output: 403
Explanation: Deleting "dee" from "delete" to turn the string into "let",
adds 100[d]+101[e]+101[e] to the sum.  Deleting "e" from "leet" adds 101[e] to the sum.
At the end, both strings are equal to "let", and the answer is 100+101+101+101 = 403.
If instead we turned both strings into "lee" or "eet", we would get answers of 433 or 417, which are higher.
```
Note:
1. 0 < s1.length, s2.length <= 1000.
2. All elements of each string will have an ASCII value in [97, 122].

## 代码
```C++
class Solution {
public:
    /*int minimumDeleteSum(string s1, string s2) {
        
        vector<int> ss1(26);
        vector<int> ss2(26);
        
        for(int i=0; i<s1.size(); i++)
        {
            ss1[s1[i]-97] ++;
        }
        
        for(int i=0; i<s2.size(); i++)
        {
            ss2[s2[i]-97] ++;
        }
        
        int sum = 0;
        int flag1 = 0, flag2 = 0;
        for(int i=0; i<26; i++)
        {
            if(ss1[i] > ss2[i])
            {
                sum += (ss1[i] - ss2[i])*(97+i);
                ss1[i] = ss2[i];
                flag1 = 1;
            }
            else if(ss1[i] < ss2[i])
            {
                sum += (ss2[i] - ss1[i])*(97+i);
                ss2[i] = ss1[i];
                flag2 = 1;
            }
        }
        
        if(flag1 != 1 || flag2 != 1)
        {
            for(int i=0; i<26; i++)
            {
                if(ss1[i] != 0)
                {
                    sum += 2*(97+i);
                    break;
                }
            }
        }
        
        return sum;
    }*/
    
    int minimumDeleteSum(string s1, string s2) {
          int minimumDeleteSum(string s1, string s2) {
        int N = s1.size();
        int M = s2.size();
        
        vector<vector<int>> dp(N+1, vector<int>(M+1, 0));
        for(int i=1; i<=N; i++)
            for(int j=1; j<=M; j++)
            {
                if(s1[i-1] == s2[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else
                    //dp[i][j] = dp[i-1][j-1] + (s1[i-1] > s2[j-1] ? s2[j-1] : s1[i-1]);
                    dp[i][j] = min(dp[i][j-1] + )
            }
        return dp[N][M];
    }
    
    int min(int a, int b)
    {
        return a>b?b:a;
    }
    }
};
```
