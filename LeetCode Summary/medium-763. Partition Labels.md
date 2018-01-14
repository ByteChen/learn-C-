## [竞赛问题](https://leetcode.com/contest/weekly-contest-67/problems/partition-labels/)
A string S of lowercase letters is given. We want to partition this string into as many parts as possible so that each letter appears in at most one part, and return a list of integers representing the size of these parts.

Example 1:
```
Input: S = "ababcbacadefegdehijhklij"
Output: [9,7,8]
Explanation:
The partition is "ababcbaca", "defegde", "hijhklij".
This is a partition so that each letter appears in at most one part.
A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits S into less parts.
```
Note:
1. S will have length in range [1, 500].
2. S will consist of lowercase letters ('a' to 'z') only.

## 代码
#### 我的代码1： 时间复杂度O(n^2)
```C++
  vector<int> partitionLabels(string S) {
        int N = S.size();
        int sum = 0;
        int left = 0;
        int right = N-1;
        int thisPart = 0;
        vector<int> v;
        while(sum < N)
        {
            thisPart = part(S, left, right);
            v.push_back(thisPart);
            sum += thisPart;
        }
        return v;       
    }
    
    int part(string S, int& l, int& r)
    {
        char ch = S[l];
        int hi;
        bool found = false;
        for(int i = l+1; i<=r; i++)
        {
            if(S[i] == ch)
            {
                hi = i;
                found = true;
            }
        }
        if(found == false)
        {
            l ++;
            return 1;
        }
        
        int index = hi;
        //int v[] = {26,0};   //不能这样定义数组
        vector<int> v(26, 0);
        v[S[l] - 'a'] = 1;
        for(int j=l+1; j<index; j++)
        {
            if(v[S[j] - 'a'] == 1)
                continue;
            v[S[j] - 'a'] = 1;
            for(int k=r; k>index; k--)
            {
                if(S[j] == S[k])
                {
                    index = k;
                    break;
                }
            }
        }
        int len = index - l + 1;
        l = index+1;
        return len;
    }
```

#### 我的方法2：时间复杂度O(n)
```C++
vector<int> partitionLabels(string S) {
        int N = S.size();
        vector<vector<int>> v(26, vector<int>(2,0));
        vector<char> firstFound(26,1);
        for(int i=0; i<N; i++)
        {
            if(firstFound[S[i] - 'a'] == 1)
            {
                v[S[i] - 'a'][0] = i;
                firstFound[S[i] - 'a'] = 0;
            }
            else
                v[S[i] - 'a'][1] = i;
        }
        
        vector<int> res;
        char firstChar;
        int left = 0, right;
        while(left < N)
        {
            firstChar = S[left];
            right = v[firstChar - 'a'][1];
            //for(int i=0; i<26; i++)       //不可按照字母顺序来，比如e使得right增大了，包含了新的字符b，但是b不会再被判断了，而最后一个b如果在right之后的话就错了。
            //{
            //    if(v[i][1] > right && v[i][0] < right && v[i][0] > left)
            //        right = v[i][1];
            //}
            for (int i = left+1; i<N; i++)
		    {
			    if (v[S[i]-'a'][1] > right && v[S[i] - 'a'][0] < right && v[S[i] - 'a'][0] > left)
				    right = v[S[i] - 'a'][1];
		    }
            int len;
            if(right == 0) len = 1, right = left;
            else len = right - left + 1;
            res.push_back(len);
            left = right + 1;
        }
        return res;        
    }
```
