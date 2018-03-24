## [按之字形顺序打印二叉树](https://www.nowcoder.com/questionTerminal/91b69814117f4e8097390d107d2efbe0)
请实现一个函数按照之字形打印二叉树，即第一行按照从左到右的顺序打印，第二层按照从右至左的顺序打印，第三行按照从左到右的顺序打印，其他行以此类推。

## 代码
* 很直接的层序遍历，类似题目 [剑指offer-把二叉树打印成多行](https://github.com/ByteChen/learn-CPP/blob/master/nowcoder/%E5%89%91%E6%8C%87offer-%E6%8A%8A%E4%BA%8C%E5%8F%89%E6%A0%91%E6%89%93%E5%8D%B0%E6%88%90%E5%A4%9A%E8%A1%8C.md)
* 不过需要隔行进行翻转，以便实现“之字形”。
```C++
/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
    vector<vector<int> > Print(TreeNode* pRoot) {
        if(pRoot  == NULL) return {};
        queue<TreeNode*> q;
        q.push(pRoot);
        vector<vector<int> > res;
        //int flag = 0;
        bool shouldReverse = false;    //用这个bool型替换上面的flag，用来判断是否应该翻转
        while(!q.empty()) {
            vector<int> temp;
            int low = 0, high = q.size();
            while(low++ < high) {
                pRoot = q.front();
                q.pop();
                temp.push_back(pRoot->val);
                if(pRoot->left) q.push(pRoot->left);
                if(pRoot->right) q.push(pRoot->right);
            }
            //if(flag % 2 == 1)
            if(shouldReverse)
                reverse(temp.begin(), temp.end());
            res.push_back(temp);
            //flag++;
            shouldReverse = !shouldReverse;        //不错的翻转，比用flag进行奇偶判断好一点点
        }
        return res;
    }
    
};
```
