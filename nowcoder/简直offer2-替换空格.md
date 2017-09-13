## 问题
请实现一个函数，将一个字符串中的空格替换成“%20”。例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。

## 代码
```C++
class Solution {
public:
	void replaceSpace(char *str,int length) {
		string s;
        int len = strlen(str);
        int i = 0;
        while(str[i] != '\0')
            {
            if(str[i] == ' ')
                s = s+"%20";    //不用对%转义，如“%%20”
            else
                s = s + str[i];
            i++;
        }
        strcpy(str, s.c_str());		// 一定要使用strcpy()函数
        // str = s.c_str();       //不对，一来s.c_str()返回的是const型char*，不能赋值给char*；
                                  //二来c_str()返回的是一个临时指针，指向的对象也会被析构
	}
};
```

## 总结
* **注意**：
一定要使用strcpy()函数 等来操作方法c_str()返回的指针!!
```C++
比如：最好不要这样:
char* c;
string s="1234";
c = s.c_str(); //c最后指向的内容是垃圾,因为s对象被析构,其内容被处理
应该这样用：
char c[20];
string s="1234";
strcpy(c,s.c_str());
这样才不会出错,c_str()返回的是一个临时指针,不能对其进行操作.
```
* 二、string转换为char*有3中方法：
```C++
data（），不包含'\0'
string str="good boy";
const char *p=str.data();

c_str（）
string str="good boy";
const char *p=str.c_str();

copy（）
string str="good boy";
char p[20];
str.copy(p,5,0); //这里5，代表复制几个字符，0代表复制的位置
*(p+5)='\0'; //要手动加上结束符
```
* 三、char*转换为string
```C++
char* s="good boy";
string str=s;

或者

char s[20]="good boy";
string str=s;
```
