## 问题
Given a non-negative integer, you could swap two digits at most once to get the maximum valued number. Return the maximum valued number you could get.

Example 1:
```
Input: 2736
Output: 7236
Explanation: Swap the number 2 and the number 7.
```
Example 2:
```
Input: 9973
Output: 9973
Explanation: No swap.
```
Note:
  The given number is in the range [0, 10^8]


## 代码
```C++
//这是leetcode的竞赛题，以下是我竞赛时根据比较直接的思路所写，不过代码有点长。但是有些东西可供以后参考，是为记。
class Solution {
public:
    int maximumSwap(int num) {
        if(num == 0) return 0;
        vector<int> v;
        int temp = num;
        int flag = 0;
        
        for(int i=8; i>=0; i--)     //先将数字们逐个存下，这段代码以后可用
        {
            int shan = temp/(int)pow(10,i);
            if(shan)
            {
                v.push_back(shan);
                temp = temp - shan*((int)pow(10,i));
                flag = 1;
            }
            else if(flag)           //注意补零，比如num==8000，不能仅记录8
                v.push_back(0);
        }
        
        if(v.size() == 1) return num;
        int index;
        
        for(int i=0; i<v.size()-1; i++) //最大的数，肯定是最高位的数值最大，因此让数值从最高位依次往下递减即可
        {
            if(v[i]==9) continue;
            temp = v[i+1];
            index = i+1;
            for(int j=i+2; j<v.size(); j++) //再后面找出最大数字
            {
                if(v[j]>=temp)
                {
                    temp = v[j];
                    index = j;
                }
            }
            if(temp>v[i])       //如果后面找到的最大数字比当前数字大，则替换，并退出
            {
                swap(v[i],v[index]);
                flag = 0;
                break;
            }
        }
        
        if(flag != 0) return num;
        else                  //若交换了，则把数字恢复，并返回
        {
            temp = 0;
            for(int i=v.size()-1, j=0; i>=0; i--,j++)
            {
                temp += v[i]*((int)pow(10,j));
            }
            return temp;
        }
    }
};
```
