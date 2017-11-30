## 问题
Given an array of characters, compress it in-place.

The length after compression must always be smaller than or equal to the original array.

Every element of the array should be a character (not int) of length 1.

After you are done modifying the input array in-place, return the new length of the array.

Example 1:
```
Input:
["a","a","b","b","c","c","c"]

Output:
Return 6, and the first 6 characters of the input array should be: ["a","2","b","2","c","3"]

Explanation:
"aa" is replaced by "a2". "bb" is replaced by "b2". "ccc" is replaced by "c3".
```
Example 2:
```
Input:
["a"]

Output:
Return 1, and the first 1 characters of the input array should be: ["a"]

Explanation:
Nothing is replaced.
```
Example 3:
```
Input:
["a","b","b","b","b","b","b","b","b","b","b","b","b"]

Output:
Return 4, and the first 4 characters of the input array should be: ["a","b","1","2"].

Explanation:
Since the character "a" does not repeat, it is not compressed. "bbbbbbbbbbbb" is replaced by "b12".
Notice each digit has it's own entry in the array.
```
Note:
1. All characters have an ASCII value in [35, 126].
2. 1 <= len(chars) <= 1000.

## 代码
#### 代码1：time complexity: O(n), space complexity: O(n)
```C++
int compress(vector<char>& chars) {
        vector<char> result; 
        result.push_back(chars[0]);
        int prev = chars[0];
        int cnt = 1;
        for(int i=1; i<chars.size(); i++)
        {
            if(chars[i] == prev)
                cnt++;
            else
            {
                if(cnt > 1)
                {
                    string s=to_string(cnt);                //务必记住使用函数 to_string（），不然自己写，很痛苦。。
                    for(char each : s)                      //for(char each : s)   其中的char不能漏
                        result.push_back(each);
                }
                cnt = 1;
                prev = chars[i];
                result.push_back(chars[i]);
            }
        }
        if(cnt > 1)                   //最后一个字母，由于到了 i=chars.size()，循环停止，所以不能漏
        {
            string s=to_string(cnt);
            for(char each : s)
                result.push_back(each);
        }
        copy(result.begin(), result.end(), chars.begin());
        return result.size();
    }
```

#### 代码2：time complexity: O(n), space complexity: O(1),直接在原vector进行操作。最佳方法
```C++
int compress(vector<char>& chars) {
      int j=0, cnt=1, size = chars.size();    //j代表长度
      for(int i=1; i<=size; i++, cnt++)       //为了避免上代码1那样对最后一个字母需要额外处理，这里需要令i<=size，且cnt++放在括号里
      {
          if(i<size && chars[i] == chars[i-1]) continue;  //如果 i != size，则继续；若i==size，说明最后一个字母了，进入else将cnt记录
          else
          {
              chars[j++] = chars[i-1];
              if(cnt > 1)
              {
                  string s = to_string(cnt);
                  for(int i=0; i<s.size(); i++)
                      chars[j++] = s[i];
              }
              cnt = 0;  //cnt复原为0，而不是1
          }
      }
      return j;
  }
```

#### 代码3：竞赛时当场写的，当时不知道 to_string（）函数，而且对于最后一个字母的处理放在循环外，傻傻写了一大堆
```C++
int compress(vector<char>& chars) {
      vector<char> result; 
      result.push_back(chars[0]);
      int len = 1;
      int prev = chars[0];
      int cnt = 1;
      int flag = 0;
      for(int i=1; i<chars.size(); i++)
      {
          if(chars[i] == prev)
              cnt++;
          else
          {
              if(cnt > 1)
              {
                  if(cnt == 1000) 
                  {
                      result.push_back(49);
                      result.push_back(0);
                      result.push_back(0);
                      result.push_back(0);
                  }
                  else if(cnt >= 100) 
                  {
                      if(cnt / 100 != 0) 
                      {
                          result.push_back(cnt/100 +48);
                          flag = 1;
                      }
                      cnt = cnt%100;
                      if(flag || cnt/10 != 0)
                      {
                          result.push_back(cnt / 10 +48);
                          flag = 1;
                      }
                      cnt = cnt%10;
                      if(flag || cnt != 0)
                      {
                          result.push_back(cnt +48);
                      }
                      flag = 0;
                  }
                  else if(cnt >= 10 )
                  {
                      if(cnt / 10 != 0) 
                      {
                          result.push_back(cnt/10 +48);
                          flag = 1;
                      }
                      cnt = cnt%10;
                      if(flag || cnt != 0)
                      {
                          result.push_back(cnt +48);
                      }
                  }
                  else result.push_back(cnt +48);
              }
              cnt = 1;
              prev = chars[i];
              result.push_back(chars[i]);
              len ++; //new
          }
      }
      if(cnt > 1)
      {
          if(cnt == 1000) 
          {
              result.push_back(49);
              result.push_back(0);
              result.push_back(0);
              result.push_back(0);
          }
          else if(cnt >= 100) 
          {
              if(cnt / 100 != 0) 
              {
                  result.push_back(cnt/100 +48);
                  flag = 1;
              }
              cnt = cnt%100;
              if(flag || cnt/10 != 0)
              {
                  result.push_back(cnt / 10 +48);
                  flag = 1;
              }
              cnt = cnt%10;
              if(flag || cnt != 0)
              {
                  result.push_back(cnt +48);
              }
              flag = 0;
          }
          else if(cnt >= 10 )
          {
              if(cnt / 10 != 0) 
              {
                  result.push_back(cnt/10 +48);
                  flag = 1;
              }
              cnt = cnt%10;
              if(flag || cnt != 0)
              {
                  result.push_back(cnt +48);
              }
          }
          else result.push_back(cnt +48);
      }
      copy(result.begin(), result.end(), chars.begin());
      return result.size();
  }
```

## 总结
**使用 to_string（）函数；在原数组直接操作以达到O(n)空间复杂度**
