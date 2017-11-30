## 问题
Initially on a notepad only one character 'A' is present. You can perform two operations on this notepad for each step:

1. **Copy All**: You can copy all the characters present on the notepad (partial copy is not allowed).
2. **Paste**: You can paste the characters which are copied last time.

Given a number n. You have to get exactly n 'A' on the notepad by performing the minimum number of steps permitted.
Output the minimum number of steps to get n 'A'.

Example 1:
```
Input: 3
Output: 3
Explanation:
Intitally, we have one character 'A'.
In step 1, we use Copy All operation.
In step 2, we use Paste operation to get 'AA'.
In step 3, we use Paste operation to get 'AAA'.
```
Note:
* The n will be in the range [1, 1000].

## 代码
#### 递归法
```C++
/**
 * It take 2 op to double, 3 ops to triple, ...
 * if n % 2 == 0, then f(n) = f(n/2) + 2
 * if n % 3 == 0, then f(n) = f(n/3) + 3
 * 2 * 2 = 2 + 2, 2 * 3 > 2 + 3, 4 * 4 > 4 + 4, so it is always better to divide whenever possible.
 * now it became a problem for finding all possible factors;
 */

class Solution {
public:
    int minSteps(int n) {
        if (n == 1) return 0;
        for (int i = 2; i < n; i++)
            if (n % i == 0) return i + minSteps(n / i);
        return n;
    }
};
```

#### 动态规划法
```C++
int minSteps(int n) {
        vector<int> dp(n+1);
        for(int i=2; i<=n; i++)
            for(int j=2; j<=i;j++)
            {
                if(i % j == 0)
                {
                    dp[i] = j + dp[i/j];
                    break;
                }
            }
        return dp[n];
    }
```
