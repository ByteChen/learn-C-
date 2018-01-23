## [重建二叉树](https://www.nowcoder.com/questionTerminal/8a19cbe657394eeaac2f6ea9b0f6fcf6)

输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。
假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
例如输入前序遍历序列```{1,2,4,7,3,5,6,8}```和中序遍历序列```{4,7,2,1,5,3,8,6}```，则重建二叉树并返回。


## 代码
* 理解就不难了。
```C++
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
		int n = pre.size();
        int m = vin.size();
        if(n!=m || n == 0)
            return NULL;
        return construct(pre, vin, 0, n-1, 0, m-1);
    }
    
    TreeNode* construct(vector<int>& pre, vector<int>& vin, int l1, int r1, int l2, int r2)
    {
        TreeNode* root = new TreeNode(pre[l1]);
        if(r1 == l1)
        {
            return root;
        }
        int val = pre[l1];
        int index;
        for(index = l2; index <= r2; index ++)
        {
            if(vin[index] == val)
                break;
        }
        int left_tree_len  = index - l2;
        int right_tree_len = r2 - index;
        if(left_tree_len > 0)
            root->left = construct(pre, vin, l1+1, l1+left_tree_len, l2, index-1);
        if(right_tree_len >0 )
            root->right = construct(pre, vin, l1+1+left_tree_len, r1, index+1, r2);
        return root;
    }
};
```
