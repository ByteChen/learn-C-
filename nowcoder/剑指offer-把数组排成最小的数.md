## [把数组排成最小的数](https://www.nowcoder.com/questionTerminal/8fecd3f8ba334add803bf2a06af1b993)
输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。例如输入数组{3，32，321}，则打印出这三个数字能排成的最小数字为321323。

## 代码
```C++
class Solution {
public:
    /*
    static bool comp(string s, string t) {    //类内的成员函数，不能直接被其他成员函数调用，需要设为 静态
        return s+t < t+s; 
    }*/
    
    class comp {
    public:
        bool operator()(string& s, string& t) {
            return s+t < t+s;
        }
        
    };
    
    string PrintMinNumber(vector<int> numbers) {
        int n = numbers.size();
        if(n <= 0) return "";
        vector<string> sv;
        for(auto each : numbers) {
            string s = to_string(each);
            sv.push_back(s);
        }
        sort(sv.begin(), sv.end(), comp());
        string res;
        for(auto each : sv) {
            res += each;
        }
        return res;
    }
};
```

## 总结
* 本题在于寻找一个合适的排序依据，能够在排序后按顺序输出的是最小数字。因此要使 A+B < B+A。
* 数字转为字符串，使用 to_string() 。参考[int转换为string的两种方法（to_string、字符串流）](http://blog.csdn.net/chavo0/article/details/51038397)
* 类内的成员函数，不能直接被其他成员函数调用，需要设为 静态! 或者是定义一个类，即函数对象。
