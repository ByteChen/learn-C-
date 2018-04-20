## [不用加减乘除做加法](https://www.nowcoder.com/questionTerminal/59ac416b4b944300b617d4f7f111b215)
写一个函数，求两个整数之和，要求在函数体内不得使用+、-、*、/四则运算符号。


## 代码
* 思路：加法，比如17+5，先不考虑进位就是17+5=12， 然后把个位的进位加到十位上就是22.
同理转为二进制运算，不进位的二进制相加，实际上就是抑或^，进位则是当两个数的对应位都是1时，就会产生进位，这就是按位与&。
```C++
class Solution {
public:
    int Add(int num1, int num2)
    {
        int sum, carry;
        do {
            sum = num1 ^ num2;
            carry = (num1 & num2) << 1;
            num1 = sum;
            num2 = carry;
          } while (num2!=0);
        return sum;
    }
};
```
