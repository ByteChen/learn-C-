## [数值的整数次方](https://www.nowcoder.com/questionTerminal/1a834e5e3e1a4b7ba251417554e07c00)
给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。

## 代码
```C++
class Solution {
public:
    double Power(double base, int exponent) {
    	//判断底数是否为0
        if(equal(base, 0.0) && exponent<0)
            throw "error input: base is 0 and exponent < 0!\n";
        unsigned int uExponent = (unsigned int) exponent;
        if(exponent < 0)
            uExponent = (unsigned int)(-exponent);
        double result = getPowerWithUnsignedInt(base, uExponent);
        if(exponent < 0)
            return 1/result;
        return result;
    }
    
    bool equal(double a, double b)  //判断两个浮点数是否相等
    {
        if((a - b < 0.0000001) && (a - b > -0.0000001))
            return true;
        return false;
    }
    
    double getPowerWithUnsignedInt(double base, unsigned int ex)
    {
        if(ex == 0)
            return 1.0;
        double result = getPowerWithUnsignedInt(base, ex >> 1);
        if(ex & 1)	//判断是否为奇数，比%求余好
            return base*result*result;
        return result*result;
    }
};
```

## 总结
1. 判断**两个浮点数是否相等时，不能直接 d1 == d2 这样判断**，因为计算机在表达小数都有误差，只能通过判断二者之差是否在一定范围内。如上equal()函数。
2. 判断是否奇数时，与其```a % 2```不如```a & 1```，位运算比求余运算效率高。
3. 求整数次方时，32次方可以转换为16次方*16次方，没必要算32次，以此减少运算次数。
