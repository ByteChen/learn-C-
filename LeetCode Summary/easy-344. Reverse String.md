## 问题
Write a function that takes a string as input and returns the string reversed.

Example:

Given s = "hello", return "olleh".

## 代码
```C++
class Solution {
public:
    string reverseString(string s) {
      //方法一：
        auto size = s.size();
        if(size == 0) return s;
        string str = s;
        for(unsigned int i=0; i<size; i++)
        {
            str[size-1-i] = s[i];
        }
        return str;
        
        //方法2：swap，只要循环一半。多用一些现成的东西也挺好的
        auto size = s.size();
        if(size <= 1) return s;
        for(unsigned int i=0; i<size/2; i++)
            swap(s[i],s[size-1-i]);
        return s;
    }
};
```
