## 问题
把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
输入一个非递减排序的数组的一个旋转，输出旋转数组的最小元素。 
例如数组 {3,4,5,1,2} 为 {1,2,3,4,5} 的一个旋转，该数组的最小值为 1 。
NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。

## 代码
```C++
class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        int min = rotateArray[0];
        int size = rotateArray.size();
        if(size == 0) return 0;
        int left = 0;
        int right = size -1;  //必须减1，不然错误
        
        while(left < right)
        {
            int mid = (left + right)/2;
            if(rotateArray[mid] >= min)
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
                min = rotateArray[mid];
            }
        }
        return rotateArray[right];
    }
};
```

## 总结
* 有必要了解二分查找的各种变体。
* [二分查找有几种写法？它们的区别是什么？](https://www.zhihu.com/question/36132386)
* [二分查找各种情况大总结](http://blog.csdn.net/yefengzhichen/article/details/52372407)
