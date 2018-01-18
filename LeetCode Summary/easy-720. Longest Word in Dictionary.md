## [720. Longest Word in Dictionary](https://leetcode.com/problems/longest-word-in-dictionary/description/)
Given a list of strings words representing an English Dictionary, find the longest word in words that can be built one character at a time by other words in words. If there is more than one possible answer, return the longest word with the smallest lexicographical order.

If there is no answer, return the empty string.
Example 1:
```
Input: 
words = ["w","wo","wor","worl", "world"]
Output: "world"
Explanation: 
The word "world" can be built one character at a time by "w", "wo", "wor", and "worl".
```
Example 2:
```
Input: 
words = ["a", "banana", "app", "appl", "ap", "apply", "apple"]
Output: "apple"
Explanation: 
Both "apply" and "apple" can be built from other words in the dictionary. However, "apple" is lexicographically smaller than "apply".
```
Note:

1. All the strings in the input will only contain lowercase letters.
2. The length of words will be in the range [1, 1000].
3. The length of words[i] will be in the range [1, 30].

## 代码
#### 方法1：使用通用规则排序，对能够找到下属的词语入set
* 另外，**set.insert() 换成 set.emplace（），效率更高**。可以参考[C++11新特性emplace操作](http://blog.csdn.net/penghuicheng/article/details/51505625)
```C++
string longestWord(vector<string>& words) {
        
        sort(words.begin(), words.end());
        
        unordered_set<string> s;
        string res = "";
        
        for(string each : words)
        {
            if(each.size() == 1 || s.find(each.substr(0, each.size()-1)) != s.end())
            //if(each.size() == 1 || s.count(each.substr(0, each.size()-1)))
            {
                s.insert(each);
                res = res.size() < each.size() ? each : res;
            }
        }
        return res;      
    }
```

#### 方法2：更优的方法
* 上面的方法，使用通用规则对字符串经行排序，这个规则不够完美，
因为默认规则是不管长度，只看字母表顺序，
比如```{"app", "absojiojoi", "apply", "applee","appe"}```，
排序后是```absojiojoi, app, appe, applee, apply```，这种排序结果，使用上面的方法来遍历是可以的，但是需要遍历整个序列。
* 如果我们自定义一种排序规则，把最长的放在前面，同样长的则把字母表顺序小的放在前面，最短的放最后。
那么我们就能在不遍历整个序列的情况下，提前找到结果。
因为如果排在前面的词语，能够找到它的所有下属的话，那么由于它比它后面的词语都长，或者字母顺序小，所以就是最后的结果了。
* 实现过程：使用函数对象作为compare方法。将words放入到set中，set利用自定义的函数对象将词语进行排序。

```C++
struct strcmp{
            bool operator()(const string& lhs, const string& rhs) {
                if(lhs.size() > rhs.size())
                    return true;
                else if(lhs.size() == rhs.size())
                    return lhs < rhs;
                else
                    return false;
            }
        };
    
    string longestWord(vector<string>& words) {
        //sort(words.begin(), words.end(), strcmp);
        
        set<string, strcmp> s(words.begin(), words.end());
        
        for(string each : s)
        {
            bool isOK = true;
            for(int i=1; i<each.size(); i++)
            {
                if(s.find(each.substr(0, i)) == s.end())
                {
                    isOK = false;
                    break;
                }
            }            
            if(isOK)
                return each;
        }
        return "";
    }
```

## 总结
1. 使用emplace（）替代insert（）可以提高效率；
2. 自定义函数对象；
3. 自定义排序规则，而不是一成不变使用默认规则



