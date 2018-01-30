## [二叉搜索树的后序遍历序列](https://www.nowcoder.com/questionTerminal/a861533d45854474ac791d90e447bafd)
输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。如果是则输出Yes,否则输出No。假设输入的数组的任意两个数字都互不相同。

## 代码
```C++
class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        int n = sequence.size();
        if(n == 0)
            return false;
        if(n <= 2)
            return true;
        return verify(sequence, 0, n-1);
    }
    
    bool verify(vector<int>& seq, int left, int right)
    {
        if(right - left <= 1)
            return true;
        int rear = seq[right];
        int bound = right;
        bool flag = true;
        for(int i = left; i< right; i++)
        {
            if(seq[i] > rear && flag)
            {
                bound = i;
                flag = false;
            }
            else if(!flag && seq[i] < rear)
                return false;
        }
        bool firstPart = true, secondPart = true;
        if(bound - 1> left)
        	firstPart = verify(seq, left, bound-1);
        if(right > bound)
            secondPart = verify(seq, bound, right-1);
        return firstPart && secondPart;
    }
};
```
