## 问题
我们可以用2\*1的小矩形横着或者竖着去覆盖更大的矩形。
请问用n个2\*1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？

## 代码
```
其实就是简单的斐波那契数列， f(n) = f(n-1) + f(n-2)，
因此无论是用递归法或者直接法都很简单。但是递归效率很低。
```

```C++
class Solution {
public:
    //方法一：递归，代码简单，但是耗时长，约500ms
    int rectCover(int number) {
        if(number <= 2) return number;
        else return rectCover(number-1) + rectCover(number-2);
    }
    
    //方法二：非递归，复杂度低，速度快，只要3ms
    int rectCover(int number) {
        if(number <= 2) return number;
        int a=1, b=2, cnt = 2;
        while(cnt < number)
        {
            b += a;
            a = b - a;
            cnt ++;
        }
        return b;
    }
};
```
