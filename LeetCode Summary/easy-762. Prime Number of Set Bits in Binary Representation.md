## [竞赛问题](https://leetcode.com/contest/weekly-contest-67/problems/prime-number-of-set-bits-in-binary-representation/)
Given two integers L and R, find the count of numbers in the range [L, R] (inclusive) having a prime number of set bits in their binary representation.

(Recall that the number of set bits an integer has is the number of 1s present when written in binary. For example, 21 written in binary is ```10101``` which has 3 set bits. Also, 1 is not a prime.)

Example 1:
```
Input: L = 6, R = 10
Output: 4
Explanation:
6 -> 110 (2 set bits, 2 is prime)
7 -> 111 (3 set bits, 3 is prime)
9 -> 1001 (2 set bits , 2 is prime)
10->1010 (2 set bits , 2 is prime)
```
Example 2:
```
Input: L = 10, R = 15
Output: 5
Explanation:
10 -> 1010 (2 set bits, 2 is prime)
11 -> 1011 (3 set bits, 3 is prime)
12 -> 1100 (2 set bits, 2 is prime)
13 -> 1101 (3 set bits, 3 is prime)
14 -> 1110 (3 set bits, 3 is prime)
15 -> 1111 (4 set bits, 4 is not prime)
```
Note:
1. L, R will be integers L <= R in the range [1, 10^6].
2. R - L will be at most 10000.

## 代码
#### 我的方法
```C++
class Solution {
public:
    int countPrimeSetBits(int L, int R) {
        int cnt=0;
        int cnt1;
        for(int i=L; i<=R; i++)
        {
            cnt1 = countOne(i);
            if(isPrime(cnt1))
                cnt ++;
        }
        return cnt;
    }
    
    int countOne(int a) //计算1的个数
    {
        int cnt = 0;
        do {
            if(a%2==1)
                cnt ++;
            a = a/2;
        } while(a >= 1);
        return cnt;
    }
    
    bool isPrime(int b)
    {
        if(b <= 1)
            return false;
        for(int i=2; i<=sqrt(b); i++)
        {
            if(b%i == 0)
                return false;
        }
        return true;
    }
};
```

#### 别人的方法1：求1的个数更简洁
```C++
class Solution {
public:
    
    bool is_prime(int x) {
        if (x==1) return false;
        for (int i=2; i<=sqrt(x); ++i)
            if (x%i==0)
                return false;
        return true;
    }
    
    int countPrimeSetBits(int L, int R) {
        int ans = 0;
        for (int x=L; x<=R; ++x) {
            int count = 0;
            int t = x;
            while (t) {       //计算1个数的这部分不错，直接 按位与，因为t实际上就是以二进制形式存在内存中的，相当于最低位&1，然后右移（除2）
                count += t&1;
                t >>= 1;
            }
            if (is_prime(count)) ++ans;
        }
        return ans;
    }
};
```

#### 别人的方法2：判断素数更快
* 由于数<=10^6，即小于2^20，所以最大也就20个1，所以判断素数时可以直接从几个值里比较
```C++
class Solution {
public:
    int countPrimeSetBits(int L, int R) {
        unordered_set<int> primes{2,3,5,7,11,13,17,19,23,29,31};
        int ans = 0;
        for(int i = L; i <= R; i++)
        {
            int t = i;
            int temp = 0;
            while(t) temp += t & 1, t >>= 1;
            ans += primes.count(temp);
        }
        return ans;
    }
};
```

## 总结
* 实际上上面三种方法求1个数的原理都是类似的，参考文章:[C/C++：十进制转为二进制（n进制转为十进制）](http://blog.csdn.net/lixiaogang_theanswer/article/details/53471427)
* 如图 ![10进制转2进制](http://img.blog.csdn.net/20161205223920272)
