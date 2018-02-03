## [646. Maximum Length of Pair Chain](https://leetcode.com/problems/maximum-length-of-pair-chain/description/)
You are given n pairs of numbers. In every pair, the first number is always smaller than the second number.

Now, we define a pair ```(c, d)``` can follow another pair ```(a, b)``` if and only if ```b < c```. Chain of pairs can be formed in this fashion.

Given a set of pairs, find the length longest chain which can be formed. You needn't use up all the given pairs. You can select pairs in any order.

Example 1:
```
Input: [[1,2], [2,3], [3,4]]
Output: 2
Explanation: The longest chain is [1,2] -> [3,4]
```
Note:
* The number of given pairs will be in the range [1, 1000].

## 代码
#### 1.动态规划 Time O(NlogN) 排序； space: O(n)
```C++
class Solution {
public:
        //这个函数必须设为static的，才能直接用来做比较函数。 
    static bool mySort(vector<int> &lhs, vector<int>&rhs) {   
        return lhs[0] < rhs[0];
    }    
    
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), mySort);
        
        int n = pairs.size();
        vector<int> v(n, 0);
        int max=0;
        int res = 0;
        for(int i=0; i<n; i++) {
            max = 0;
            for(int j=i-1; j>=0; j--) {
                if(pairs[j][1] < pairs[i][0]) {
                    max = v[j];
                    break;
                }
            }
            v[i] = max+1;
            if(res < v[i])
                res = v[i];
        }
        return res;
    }
};
```

#### 2.贪心算法 Time O(NlogN) 排序； space: O(1) 如果快速排序空间复杂度是O(1)的话
```C++
class Solution {
public:
    static bool mySort(vector<int> &lhs, vector<int>&rhs) {
        return lhs[1] < rhs[1];
    }    
    
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), mySort);
        
        int n = pairs.size();
        vector<int> v(n, 0);
        int max=1;
        int res = 0;
        int cur = pairs[0][1];
        for(int i=1; i<n; i++) {
            if(cur < pairs[i][0]) {
                max ++;
                cur = pairs[i][1];
            }
        }
        return max;
    }
};
```

## 总结
* 类中自定义函数用作比较函数时，必须设为**static**的， 不然不能直接用。比如
```C++
static bool mySort(vector<int> &lhs, vector<int>&rhs) {
        return lhs[1] < rhs[1];
    }    
```
