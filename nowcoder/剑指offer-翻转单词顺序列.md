## [翻转单词顺序列](https://www.nowcoder.com/questionTerminal/3194a4f4cf814f63919d0790578d51f3)
牛客最近来了一个新员工Fish，每天早晨总是会拿着一本英文杂志，写些句子在本子上。同事Cat对Fish写的内容颇感兴趣，有一天他向Fish借来翻看，但却读不懂它的意思。例如，“student. a am I”。后来才意识到，这家伙原来把句子单词的顺序翻转了，正确的句子应该是“I am a student.”。Cat对一一的翻转这些单词顺序可不在行，你能帮助他么？

## 代码
* 分析：虽然这个题目有更简单的解决方法，比如借助库函数，利用string，split（）等来做，很直接。但是还是尝试一下原始一点的方法，不过于依赖库函数。
* 思路就是相对这个字符串经行一次翻转，然后在对其中的每个单词经行翻转。
```C++
class Solution {
public:
    string ReverseSentence(string str) {
        int n = str.size();
        if(n <= 1) return str;
        reverse(str, 0, n);
        int slow = 0, fast;
        while(slow < n) {
            while(str[slow] == ' ') slow ++;
            fast = slow+1;
            while(str[fast] != ' ' && fast < n)   //务必有后面的fast < n 的判断，因为字符串中可能直到最后都是空格
                fast ++;
            reverse(str, slow, fast);
            slow = fast + 1;
        }
        return str;
    }
    
    void reverse(string& str, int start, int end) {        //左闭右开
        if(start >= end -1)
            return;
        end --;
        while(start < end) {
            //swap(); //不用swap
            char temp = str[start];
            str[start] = str[end];
            str[end] = temp;
            start++, end--;
        }
    }
};
```
