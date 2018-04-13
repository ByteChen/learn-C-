## [滑动窗口的最大值](https://www.nowcoder.com/questionTerminal/1624bc35a45c42c0bc17d17fa0cba788)
给定一个数组和滑动窗口的大小，找出所有滑动窗口里数值的最大值。例如，如果输入数组{2,3,4,2,6,2,5,1}及滑动窗口的大小3，那么一共存在6个滑动窗口，他们的最大值分别为{4,4,6,6,6,5}； 针对数组{2,3,4,2,6,2,5,1}的滑动窗口有以下6个： {[2,3,4],2,6,2,5,1}， {2,[3,4,2],6,2,5,1}， {2,3,[4,2,6],2,5,1}， {2,3,4,[2,6,2],5,1}， {2,3,4,2,[6,2,5],1}， {2,3,4,2,6,[2,5,1]}。

## 代码
* 思路：使用一个deque，存储下标。deque前端是当前窗口内最大元素的下表。O(n)
```C++
class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size)
    {
        int n = num.size();
        vector<int> res;
        if(n < size || size < 1) return res;
        if(size == 1) return num;
        deque<int> q;
        int i=0;
        for(; i<size; i++) {
            while(!q.empty() && num[q.back()] < num[i]) {
                    q.pop_back();
                }
            q.push_back(i);
        }
        res.push_back(num[q.front()]);
        for(; i<n; i++) {
            if(i - q.front() >= size)        //弹出过期的下标
                q.pop_front();
            while(!q.empty() && num[q.back()] < num[i]) {
                    q.pop_back();
                }
            q.push_back(i);
            res.push_back(num[q.front()]);
        }
        return res;
    }
};
```
