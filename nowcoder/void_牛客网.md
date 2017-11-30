## 问题
### 题目描述
牛牛拿到了一个藏宝图，顺着藏宝图的指示，牛牛发现了一个藏宝盒，藏宝盒上有一个机关，机关每次会显示两个字符串 s 和 t，根据古老的传说，牛牛需要每次都回答 t 是否是 s 的子序列。注意，子序列不要求在原字符串中是连续的，例如串 abc，它的子序列就有 {空串, a, b, c, ab, ac, bc, abc} 8 种。

### 输入描述:
每个输入包含一个测试用例。每个测试用例包含两行长度不超过 10 的不包含空格的可见 ASCII 字符串。

### 输出描述:
输出一行 “Yes” 或者 “No” 表示结果。

示例1
输入
```
x.nowcoder.com
ooo
```
输出
```
Yes
```

## 代码 1
```C++
#include<iostream>
#include<string>

using namespace std;

int main()
{
    string s, t;
    cin >> s;
    cin >> t;
     int N = s.size();
     int M = t.size();
    if(M = 0)
    {
        cout<<"Yes"<<endl;
        return 0;
    }
    if(N = 0)
    {
        cout<<"No"<<endl;
        return 0;
    }
    for(int i=0; i < t.size(); i++)
    {
        auto found = s.find(t[i]);
        if(found == string::npos)
        {
            cout<<"No"<<endl;
            return 0;
        }
        else 
            s = s.substr(found+1);
    }
    cout<<"Yes"<<endl;
    return 0;
}
```

## 代码2：更优
```C++
#include<iostream>
#include<string>
using namespace std;
 
int main(){
    string str;
    while (cin >> str){
        string str1;
        cin >> str1;
        int a=0, b = 0;
        while (a < str.length()){
            if (str[a++] == str1[b])
                b++;
 
        }
        if (b == str1.length())
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
 
}
```

## 代码3：一开始写错的代码，审题不清，原来 s=abc, t=ba 时， 输出是No
* 使用了unordered_map，可以说是小题大做了。
```C++
#include <iostream>
#include<string>
#include<unordered_map>

using namespace std;

int main()
{
    string s, t;
    cin >> s;
    cin >> t;
    if(t.size() == 0) 
    {
            cout<<"Yes"<<endl;
            return 0;
        }
    if(s.size() == 0)
        {
            cout<<"No"<<endl;
            return 0;
        }
    
    unordered_map<char, int> s_m;
    for(int i=0; i<s.size(); i++)
    {
        s_m[s[i]] ++;
    }
    
    for(int j=0; j<t.size(); j++)
    {
        if(s_m.find(t[j]) == s_m.end() )
        {
            cout<<"No"<<endl;
            return 0;
        }
        else if(s_m[t[j]] <= 0)
        {
            cout<<"No"<<endl;
            return 0;
        }
        else
            s_m[t[j]] --;
    }
    cout<<"Yes"<<endl;
    return 0;
}
```

