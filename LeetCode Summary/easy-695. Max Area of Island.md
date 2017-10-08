## 问题
Given a non-empty 2D array grid of 0's and 1's, an island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

Find the maximum area of an island in the given 2D array. (If there is no island, the maximum area is 0.)

Example 1:
```
[[0,0,1,0,0,0,0,1,0,0,0,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,1,1,0,1,0,0,0,0,0,0,0,0],
 [0,1,0,0,1,1,0,0,1,0,1,0,0],
 [0,1,0,0,1,1,0,0,1,1,1,0,0],
 [0,0,0,0,0,0,0,0,0,0,1,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,0,0,0,0,0,0,1,1,0,0,0,0]]
 ```
Given the above grid, return **6**. Note the answer is not **11**, because the island must be connected 4-directionally.

Example 2:
```
[[0,0,0,0,0,0,0,0]]
```
Given the above grid, return **0**.

Note: The length of each dimension in the given grid does not exceed **50**.

## 思路
这个是leetcode本周的竞赛题。因为对于每个1，都要向上下左右看它的邻居们是不是1，但是比如向左看时，
可能一直往左，但是右边的就不方便回去访问了。为此，参照了树的层序遍历算法，使用队列，对于每一个节点的上下左右，
若是1，则将其下标入队。因为下标有两个，所以用pair组织比较好。对于入队过的每个节点，都手动将1置为0，避免重复计算。

## 代码
```C++
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxarea = 0;
        queue<pair<int,int> > q;
        pair<int,int> temp;         //pair好用啊
        for(int i=0; i<grid.size(); i++)
            for(int j=0; j<grid[0].size(); j++)
            {
                if(grid[i][j] == 1)
                    q.push(pair<int,int>(i,j));
                grid[i][j] = 0;
                int area = 0;
                while(!q.empty())
                {
                    temp = q.front();
                    q.pop();
                    area++;
                    //grid[temp.first][temp.second] = 0;
                    if(temp.first-1>=0 && grid[temp.first-1][temp.second]==1)
                    {
                        q.push(pair<int,int>(temp.first-1, temp.second));
                        grid[temp.first-1][temp.second] = 0;                //将下标入队后，将该节点置为0
                    }
                    if(temp.first+1<grid.size() && grid[temp.first+1][temp.second]==1)
                    {
                        q.push(pair<int,int>(temp.first+1, temp.second));
                        grid[temp.first+1][temp.second] = 0;
                    }
                    if(temp.second-1>=0 && grid[temp.first][temp.second-1]==1)
                    {
                        q.push(pair<int,int>(temp.first, temp.second-1));
                        grid[temp.first][temp.second-1] = 0;
                    }
                    if(temp.second+1<grid[0].size() && grid[temp.first][temp.second+1]==1)
                    {
                        q.push(pair<int,int>(temp.first, temp.second+1));
                        grid[temp.first][temp.second+1] = 0;
                    }
                }
                maxarea = maxarea>area ? maxarea:area;
            }
        return maxarea;
    }
};
```
