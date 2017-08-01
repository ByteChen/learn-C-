## 一、问题
Given a string, find the length of the longest substring without repeating characters.

**Examples:**

Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.

## 二、代码

``` C++
class Solution {
public:
    //方法一：最low方法：时间复杂度是O（$n^2$）
    int lengthOfLongestSubstring(string s) {
        int i,j,k;
        int maxlength = 0;
        int thislength;
        int found;
        for(i = 0; i<s.size(); i++)
        {
            found = 0;
            for(j = i+1;j<s.size();j++)
            {
                for(k=i; k<j; k++)
                {
                    if(s[k] == s[j]) 
                    {
                        found = 1;
                        break;
                    }
                }
                if(found) break;
            }
            thislength = j-i; 
            maxlength = maxlength > thislength ? maxlength : thislength;
            if(thislength > s.size() - i -1) break;
        }
        return maxlength;
    }
    
    //方法二
    /*
    The previous implements all have no assumption on the charset of the string s.
    If we know that the charset is rather small, we can replace the Map with an integer array as direct access table.
    Commonly used tables are:

    int[26] for Letters 'a' - 'z' or 'A' - 'Z'
    int[128] for ASCII
    int[256] for Extended ASCII
    */
    int lengthOfLongestSubstring(string s) {
        vector<int> dict(256, -1);
        int maxLen = 0, start = -1;
        for (int i = 0; i != s.length(); i++) {
            if (dict[s[i]] > start)
                start = dict[s[i]];
            dict[s[i]] = i;
            maxLen = max(maxLen, i - start);
        }
        return maxLen;
    }
    
    //方法三：时间复杂度和上一种方法一样，但是空间复杂度低一点。
    //简单修改，使用map来实现，则是：
    int lengthOfLongestSubstring(string s) {
        map<char, int> charMap;
        int start = -1;
        int maxLen = 0;
        
        for (int i = 0; i < s.size(); i++) {
            if (charMap.count(s[i]) != 0) {   //由于map不包含重复的key，因此m.count(key)取值为0或1，表示是否包含
                start = max(start, charMap[s[i]]);
            }
            charMap[s[i]] = i;
            maxLen = max(maxLen, i-start);
        }
        return maxLen;
    }
};

```

## 三、总结
 不要动不动就使用for循环，很慢，换个思路，想想题目描述中未包含的信息，比如这题字符最多256个这样。

