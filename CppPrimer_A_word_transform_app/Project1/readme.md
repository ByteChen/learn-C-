## 总结
1. 使用头文件<fstream> 中的 ifstream 打开文本文件。

2. 使用头文件<sstream> 中的 istringstream 来将一个长string，根据空格划分为若干个短string。比如
```C++
string source, s1, s2, s3;
source = "I am back";
istringstream ss(source);
ss >> s1 >> s2 >> s3;
// And the result is s1="I", s2 = "am", s3 = "back"
```

3. 灵活使用getline()。比如程序中这行：
```C++
while (dict >> key && getline(dict, line))	{...}
```
假设当前行是：
```
brb be right back
```
其中brb是key， 剩余部分是value。先利用dict >> key 将读指针挪到“brb”之后，（其实也不是挪，这时候brb已经不在了），然后getline获取剩余内容。如果使用总结中第二点的方法，则value=“be”，而不是“be right back”， 就不对了。

4. 使用substr等。

5. 更完善的版本可参考C++ primer 393页。
