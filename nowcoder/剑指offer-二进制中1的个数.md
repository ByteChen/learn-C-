## [问题](https://www.nowcoder.com/practice/8ee967e43c2c4ec193b040ea7fbb10b8?tpId=13&tqId=11164&tPage=1&rp=2&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking)
输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示。

## 代码
#### 我的方法
* 说是这种方法在输入负数时会陷入死循环，但是我的方法正常，怪哉。
* 书中说的是：该解法如果输入时负数会陷入死循环，因为负数右移时，在最高位补得是1，二本题最终目的是求1的个数，那么会有无数个1了。
```C++
class Solution {
public:
     int  NumberOf1(int n) {
         if(n == 0) return 0;
         else if(n > 0) return positiveCnt(n);
         else return negativeCnt(n);
     }
    
    int positiveCnt(int n)
    {
        int cnt = 0;
        while(n)
        {
            if(n & 1)
                cnt ++;
            n = n>>1;
        }
        return cnt;
    }
    
    int negativeCnt(int n)
    {
        int cnt = 0;
        int m = n;
        for(int i=31; i>0 && m; i--)
        {
            if(m & 1)
                cnt ++;
            m = m >> 1;
        }
        cnt ++;
        return cnt;
    }
};
```

#### 剑指offer上的常规方法
* 上面的方法是把n右移，既然负数不能右移，那么不妨搞个类似掩码mask似的东西，把mask=1左移，一一确定每一位是否为1.
```C++
int  NumberOf1(int n) {
        unsigned int mask = 1;
        int cnt = 0;
        
        //for(int i=0; i<32; i++)
        while(mask)
        {
            if(n & mask)
                cnt ++;
            mask = mask << 1;
        }
        return cnt;
    }
```

#### 让面试官惊喜的方法。。
* 上面的方法，需要遍历32次（认为int是32bit），而这种方法能够实现有几个1就只遍历几次。
* 原理：一个数减去1，相当于把最右边的1变为0，最右边的1右边的0变为1，减1前和减1后按位与，就把原来的最后一个1去掉了。
* 参考： 书中p81 或者[这里](https://www.nowcoder.com/questionTerminal/8ee967e43c2c4ec193b040ea7fbb10b8)
```C++
int  NumberOf1(int n) {
        if(n == 0) return 0;
        int cnt = 0;
        
        while(n)
        {
            cnt ++;
            n = n & (n-1);
        }
        return cnt;
    }
```

## 补充
* **在计算机中，负数都是使用补码进行表示的**。之所以使用补码表示负数，是为了在硬件上，只需要一个相同的加法器，就能实现正数+正数、正数+负数、负数+负数的运算。
* 具体可以参考这篇博客，很有益： [负数在计算机中如何表示，计算机中负数为什么用补码表示？](http://blog.csdn.net/youcharming/article/details/41982239)


