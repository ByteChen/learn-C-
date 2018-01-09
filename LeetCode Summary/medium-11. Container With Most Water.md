## [问题](https://leetcode.com/problems/container-with-most-water/description/)
Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container and n is at least 2.

## 代码
#### 时间复杂度 O(n^2)
```C++
int maxArea(vector<int>& height) {
        int max = 0;
        int N = height.size();
        int area;
        
        for(int i=0; i<N; i++)
        {
            if(max >= height[i]*(N-1-i))
                continue;
            for(int j=N-1; j>i; j--)
            {
                if(max >= height[i]*(j-i))
                    break;
                area = (j-i)*(height[j] > height[i] ? height[i] : height[j]);
                max = max > area ? max : area;
            }
        }
        return max;
    }
```

#### 时间复杂度 O(n)
```C++
int maxArea(vector<int>& height) {
        int left = 0, right = height.size()-1;
        int area, max = 0;
        bool left_bigger;
        
        while(left < right)
        {
            left_bigger = height[right] > height[left] ? false : true;
            if(left_bigger)
            {
                area = (right - left) * height[right];
                right --;
            }
            else
            {
                area = (right - left) * height[left];
                left ++;
            }
            max = max > area ? max : area;
        }
        return max;
    }
```

### O(n) 复杂度方法的证明
* Here is a simple proof for the solution.
Use v[low, high] indicates the volume of container with low and high. suppose height[low] < height[high], then we move low to low+1, that means we ingored v[low, high-1],v[low, high-2],etc, if this is safe, then the algorithm is right, and it's obvious that v[low, high-1],high[low, high-2]...... can't be larger than v[low, high] since its width can't be larger than high-low, and its height is limited by height[low].

* [详见](https://discuss.leetcode.com/topic/503/anyone-who-has-a-o-n-algorithm/4)
