## 问题
输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字，
例如，如果输入如下矩阵： 
```
1  2  3  4 
5  6  7  8 
9  10 11 12 
13 14 15 16 
```
则依次打印出数字为：
```
1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.
```

## 代码
```C++
class Solution {
public:
    int cnt;
    vector<int> printMatrix(vector<vector<int> > matrix) {
		int minrow=0, mincol=0, maxrow, maxcol;
        int N = matrix.size();
        int M = matrix[0].size();
        maxrow = N - 1;
        maxcol = M - 1;
        vector<int> s;
        int i = 0, j = 0;
        cnt = 0;
        while(1)
        {
            rightPrint(matrix, s, i, j, maxcol);
            if(cnt >= N*M) return s;
            downPrint (matrix, s, i, j, maxrow);
            if(cnt >= N*M) return s;
            leftPrint (matrix, s, i, j, mincol);
            if(cnt >= N*M) return s;
            upPrint   (matrix, s, i, j, minrow);
            if(cnt >= N*M) return s;
        }
        return s;
    }
    
    void rightPrint(vector<vector<int> >& matrix, vector<int>& s,int& current_i, int& current_j, int& maxcol)
    {
        while(current_j <= maxcol)
        {
            s.push_back(matrix[current_i][current_j]);
            current_j ++;
            cnt ++;
        }
        current_j --;
        current_i ++;
        maxcol --;
        return;
    }
    
    void downPrint(vector<vector<int> >& matrix, vector<int>& s,int& current_i, int& current_j, int& maxrow)
    {
        while(current_i <= maxrow)
        {
            s.push_back(matrix[current_i][current_j]);
            current_i ++;
            cnt ++;
        }
        current_i --;
        current_j --;
        maxrow --;
        return;
    }
    
    void leftPrint(vector<vector<int> >& matrix, vector<int>& s,int& current_i, int& current_j, int& mincol)
    {
        while(current_j >= mincol)
        {
            s.push_back(matrix[current_i][current_j]);
            current_j --;
            cnt ++;
        }
        current_j ++;
        current_i --;
        mincol ++;
        return;
    }
    
    void upPrint(vector<vector<int> >& matrix, vector<int>& s,int& current_i, int& current_j, int& minrow)
    {
        while(current_i > minrow)
        {
            s.push_back(matrix[current_i][current_j]);
            current_i --;
            cnt ++;
        }
        current_i ++;
        current_j ++;
        minrow ++;
        return;
    }
};
```
