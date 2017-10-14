## 问题
Given a n x n matrix where each of the rows and columns are sorted in ascending order, find the kth smallest element in the matrix.

Note that it is the kth smallest element in the sorted order, not the kth distinct element.

Example:
```
matrix = [
   [ 1,  5,  9],
   [10, 11, 13],
   [12, 13, 15]
],
k = 8,
```
return 13.
Note: 
You may assume k is always valid, 1 ≤ k ≤ n^2.

## 代码
```C++
class Solution {
public:
  
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int left = matrix[0][0], right = matrix[matrix.size()-1][matrix[0].size()-1];
        int mid, count;
        
        while(left<right)
        {
            mid = (left+right)>>1;
            count = 0;
            for(int i=0; i<matrix.size(); i++)
            {
                count += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
            }
            if(count<k)
                left = mid+1;
            else
                right = mid;
        }
        return right;
    }
    
};
```
