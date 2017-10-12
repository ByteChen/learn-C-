## 问题一：跳台阶
一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法。

## 分析
这类题目，比较贴近数学，可以先手动算一算找规律，然后发现这其实是一个**斐波那契数列**的题目，所以使用循环可以很简单地得到答案。不过另外这个题目，也可以使用递归，这样更加简单，但是效率很低。

20171012补充：今天在leetcode再次遇到这道题，发现还有动态规划的方法也不错，故补充一些。

还有其他方法，可参考：[leetcode discuss](https://leetcode.com/problems/climbing-stairs/solution/)


## 代码
```C++
class Solution {
public:
    //方法一：循环法
    int jumpFloor(int number) {
        if(number < 0) return -1;
        if(number <= 2) return number;
        int a = 1, b = 2;
        int temp;
        for(int i=number-2; i>0; i--)
            {
            temp = a;
            a = b;
            b = temp + b;
        }
        return b;
    }
    
    //方法二：递归法
    int jumpFloor(int number) {
        if(number <= 2)  return number;
        return jumpFloor(number-1) + jumpFloor(number-2);
    }
    
     //方法三：动态规划 法: dp[i] = dp[i-1] + dp[i-2],主要是要把前面的结果保存下来，免得后面计算。
     int jumpFloor(int number) {
	if( n<= 2) return n;
        vector<int> dp(n+1);
        dp[1] = 1;
        dp[2] = 2;
        for(int i=3; i<=n; i++)
        {
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
     }
};
```

## 问题二：变态跳台阶
一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。求该青蛙跳上一个n级的台阶总共有多少种跳法。

## 分析
这个题，虽然只能递归了，但是还有复杂度低一些的递归。也是看的别人的分析，才发现自己的方法太原始：
参考：[变态跳台阶的回答](https://www.nowcoder.com/questionTerminal/22243d016f6b47f2a6928b4313c85387)
```
链接：https://www.nowcoder.com/questionTerminal/22243d016f6b47f2a6928b4313c85387
来源：牛客网

关于本题，前提是n个台阶会有一次n阶的跳法。分析如下:
f(1) = 1
f(2) = f(2-1) + f(2-2)         //f(2-2) 表示2阶一次跳2阶的次数。
f(3) = f(3-1) + f(3-2) + f(3-3) 
...
f(n) = f(n-1) + f(n-2) + f(n-3) + ... + f(n-(n-1)) + f(n-n) 
 
说明： 
1）这里的f(n) 代表的是n个台阶有一次1,2,...n阶的 跳法数。
2）n = 1时，只有1种跳法，f(1) = 1
3) n = 2时，会有两个跳得方式，一次1阶或者2阶，这回归到了问题（1） ，f(2) = f(2-1) + f(2-2) 
4) n = 3时，会有三种跳得方式，1阶、2阶、3阶，
    那么就是第一次跳出1阶后面剩下：f(3-1);第一次跳出2阶，剩下f(3-2)；第一次3阶，那么剩下f(3-3)
    因此结论是f(3) = f(3-1)+f(3-2)+f(3-3)
5) n = n时，会有n中跳的方式，1阶、2阶...n阶，得出结论：
    f(n) = f(n-1)+f(n-2)+...+f(n-(n-1)) + f(n-n) => f(0) + f(1) + f(2) + f(3) + ... + f(n-1)
    
6) 由以上已经是一种结论，但是为了简单，我们可以继续简化：
    f(n-1) = f(0) + f(1)+f(2)+f(3) + ... + f((n-1)-1) = f(0) + f(1) + f(2) + f(3) + ... + f(n-2)
    f(n) = f(0) + f(1) + f(2) + f(3) + ... + f(n-2) + f(n-1) = f(n-1) + f(n-1)
    可以得出：
    f(n) = 2*f(n-1)
    
7) 得出最终结论,在n阶台阶，一次有1、2、...n阶的跳的方式时，总得跳法为：
              | 1       ,(n=0 ) 
f(n) =        | 1       ,(n=1 )
              | 2*f(n-1),(n>=2)
```

## 代码
```C++
class Solution {
public:
    //原始的递归，效率低
    int jumpFloorII(int number) {
        if(number <= 2) return number;
        int sum = 1;
        for(int i=1; number-i>0; i++)
            {
            sum += jumpFloorII(number-i);
        }
		return sum;
    }
    
    //改进后的，根据规律来，效率提高很多（1ms与4ms的区别）
    int jumpFloorII(int number) {
        if(number <= 2) return number;
        return 2*jumpFloorII(number-1);
    }
};
```

## 总结
这类偏数学的题目，还是应该多用笔算算，找找规律。
