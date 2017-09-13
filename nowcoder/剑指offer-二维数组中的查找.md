## 问题
题目描述
在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。
请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。

## 代码
```C++
class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        auto row = array.size();
        if(row == 0) return false;
        auto col = array[0].size();
        int i = 0, j = col-1;
        while(i<row && j>=0)
            {
            if(array[i][j] == target)
                return true;
            else if(array[i][j] > target)
                j--;
            else
                i++;
        }
        return false;
    }
};
```

## 总结
碰巧在牛客网系列视频《直通BAT算法精讲》看过这个题，总之从左下角或者右上角开始找，最好，复杂度最低；
当然也可以把二维数组当做一行一行看，在每行中使用二分查找。
