## [字符串的排列](https://www.nowcoder.com/questionTerminal/fe6b651b66ae47d7acce78ffdd9a96c7)
* 输入一个字符串,按字典序打印出该字符串中字符的所有排列。例如输入字符串abc,则打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。 
* 输入描述:
  * 输入一个字符串,长度不超过9(可能有字符重复),字符只包括大小写字母。

## 代码
#### 方法1：忘了使用swap，用了很蠢的方法（用substr来重组字符串），但是很直接，一遍就对了
* 使用set来存储，从而避免重复结果。set设为一个类似全局的变量（成员变量），其实可以作为参数传引用进去，更简洁。
```C++
class Solution {
public:
    set<string> res;
    vector<string> Permutation(string str) {
        res.clear();
        if(str.size() == 0)
            return {};
        else
            permute("", str);
        vector<string> sv(res.size());
        copy(res.begin(), res.end(), sv.begin());
        return sv;
    }
    
    void permute(string used, string rest)
    {
        if(rest.size() == 1)
        {
            string s = used + rest;
            res.insert(s);
        }
        else if(rest.size() > 1) {
            for(int i=0; i<rest.size(); i++) {
                char cur = rest[i];
                string next = stringDeleteOneChar(rest, i);
                permute(used + cur, next);
            }
        }
    }
    
    //用来去掉string中的一个字符，返回剩余部分
    string stringDeleteOneChar(string s, int i) {
        if(i == 0) {
            return s.substr(1);
        }
        else if(i == s.size()-1) {
            return s.substr(0, s.size()-1);
        }
        else {
            return s.substr(0,i) + s.substr(i+1);
        }
    }
};
```

#### 方法二：参考剑指offer上的排列组合方法，容易错
```C++
class Solution {
public:
    vector<string> res;
    vector<string> Permutation(string str) {
        res.clear();
        if(str.size() == 0)
            return {};
        
        permute(str, str.size(), 0);
        sort(res.begin(), res.end());
        return res;
    }
    
    void permute(string str, int size, int index) {
        if(index == size-1) {
            res.push_back(str);
            return;
        }
        for(int i=index; i<size; i++) {     //除了初次，后面相同字符都不swap，从而避免相同结果。
            if(str[i] == str[index] && i != index) {
                continue;
            }
            else {
                swap(str[index], str[i]);
                permute(str, size, index+1);
                swap(str[index], str[i]);
            }
        }
    }
};
```
