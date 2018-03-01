## [连续子数组的最大和](https://www.nowcoder.com/questionTerminal/459bd355da1549fa8a49e350bf3df484)
* HZ偶尔会拿些专业问题来忽悠那些非计算机专业的同学。
今天测试组开完会后,他又发话了:在古老的一维模式识别中,常常需要计算连续子向量的最大和,当向量全为正数的时候,问题很好解决。
但是,如果向量中包含负数,是否应该包含某个负数,并期望旁边的正数会弥补它呢？
例如:{6,-3,-2,7,-15,1,2,2},连续子向量的最大和为8(从第0个开始,到第3个为止)。
你会不会被他忽悠住？(子向量的长度至少是1)

## 代码
#### 方法一：直接法
```C++
int FindGreatestSumOfSubArray(vector<int> array) {
        int max = array[0];
        int sum, j;
        for(int i=0; i<array.size();)
            {
            if(array[i] <= 0 && array[i] < max)
            {
                i++;
                continue;
            }
            sum = array[i];
            max = max > sum ? max : sum;
            
            for(j=i+1; j<array.size(); j++)
                {
                sum += array[j];
                if(sum <= 0)
                {
                    i = j+1;
                    break;
                }
                max = max > sum ? max : sum;
            }
            if(j == array.size())
                break;
        }
    return max;
    }
```

#### 方法二：动态规划,时间O(n), 空间O(n)
```C++
int FindGreatestSumOfSubArray(vector<int> array) {
        int n = array.size();
        vector<int> dp(n);
        dp[0] = array[0];
        int max = dp[0];
        for(int i=1; i<n; i++) {
            if(dp[i-1] > 0)
                dp[i] = dp[i-1] + array[i];
            else
                dp[i] = array[i];
            max = max > dp[i]? max : dp[i];
        }
        return max;
    }
```

#### 方法3：动态规划,时间O(n), 空间O(1)
```C++
int FindGreatestSumOfSubArray(vector<int> array) {
        int n = array.size();
        int last = array[0];
        int max = last;
        for(int i=1; i<n; i++) {
            last = last>0 ? last+array[i] : array[i];
            max = max > last? max : last;
        }
        return max;
    }
```
