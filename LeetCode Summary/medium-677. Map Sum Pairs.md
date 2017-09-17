## 问题
Implement a MapSum class with insert, and sum methods.

For the method insert, you'll be given a pair of (string, integer). The string represents the key and the integer represents the value. If the key already existed, then the original key-value pair will be overridden to the new one.

For the method sum, you'll be given a string representing the prefix, and you need to return the sum of all the pairs' value whose key starts with the prefix.

Example 1:
```
Input: insert("apple", 3), Output: Null
Input: sum("ap"), Output: 3
Input: insert("app", 2), Output: Null
Input: sum("ap"), Output: 5
```

## 代码
```C++
class MapSum {
public:
    /** Initialize your data structure here. */
    MapSum() {
        m.clear();
    }
    
    void insert(string key, int val) {
        m[key] = val;
    }
    
    int sum(string prefix) {
        int len = prefix.size();
        int sum = 0;
        for(map<string,int>::iterator iter = m.begin(); iter != m.end(); iter++)
        {
            if((iter->first).substr(0,len) == prefix)
                sum += iter->second;
        }
        return sum;
    }
private:
    map<string, int> m;
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum obj = new MapSum();
 * obj.insert(key,val);
 * int param_2 = obj.sum(prefix);
 */
```

## 总结
* 这是在竞赛时做的，比较直接的方法。题目比较简单，之所以要记下来，是因为需要补充一些字符串的操作。
* [C++常用字符串分割方法实例汇总](http://www.jb51.net/article/55954.htm)
1. 一、用strtok函数进行字符串分割（c语言中的）
```C++
原型： char *strtok(char *str, const char *delim);
功能：分解字符串为一组字符串。
参数说明：str为要分解的字符串，delim为分隔符字符串。
返回值：从str开头开始的一个个被分割的串。当没有被分割的串时则返回NULL。
```
2. 二、用STL进行字符串的分割
```C++
涉及到string类的两个函数find和substr：
1、find函数
原型：size_t find ( const string& str, size_t pos = 0 ) const;
功能：查找子字符串第一次出现的位置。
参数说明：str为子字符串，pos为初始查找位置。
返回值：找到的话返回第一次出现的位置，否则返回string::npos

2、substr函数
原型：string substr ( size_t pos = 0, size_t n = npos ) const;
功能：获得子字符串。
参数说明：pos为起始位置（默认为0），n为结束位置（默认为npos）
返回值：子字符串
其它：strtok函数线程不安全，可以使用strtok_r替代。
```

3. 三、用Boost进行字符串的分割
boost中的正则表达式或者split（）等函数，都不错。

4. 最后，在记录一个不错的程序，用来spilt字符串挺不错的，里面用到了substr（）和find（）函数：
```C++
#include<iostream>  
#include <vector>  
#include<string>  
using namespace std;  
vector<string> split(const string& src, string separate_character)  
{  
    vector<string> strs;  
    int separate_characterLen = separate_character.size();//分割字符串的长度,这样就可以支持如“,,”多字符串的分隔符  
    int lastPosition = 0, index = -1;  
    while (-1 != (index = src.find(separate_character, lastPosition)))  
    {  
        strs.push_back(src.substr(lastPosition, index - lastPosition));  
        lastPosition = index + separate_characterLen;  
    }  
    string lastString = src.substr(lastPosition);//截取最后一个分隔符后的内容  
    if (!lastString.empty())  
        strs.push_back(lastString);//如果最后一个分隔符后还有内容就入队  
    return strs;  
}  

int _tmain(int argc, _TCHAR* argv[])  
{  
    string s = "12.45.78";  
    string del =".";  
    vector<string> strs = split(s,del);  
    for (int i = 0; i < strs.size(); i++)  
    {  
        cout << strs[i]<<' ';  
    }  
    cout << endl;  
    system("pause");  
    return 0;  
} 
```
