## [二叉树中和为某一值的路径](https://www.nowcoder.com/questionTerminal/b736e784e3e34731af99065031301bca)
输入一颗二叉树和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。

## 代码
* 每进入下一层，就往path中push一个当前节点值，当要退出这一层，返回上一层时，就弹出这个值，把path恢复原样。
* 当然path也可以不采用传引用的方式，而是采用传值的方式，这样就不需要在推出当前层是pop_back()了。不过这样效率不高吧。
```C++
/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

class Solution {
public:
    /*
     * @param root: the root of binary tree
     * @param target: An integer
     * @return: all valid paths
     */
    vector<vector<int>> res;
    vector<vector<int>> binaryTreePathSum(TreeNode * root, int target) {
        res.clear();
        if(root == NULL) return res;
        vector<int> path;
        int sum = 0;
        getTarget(root, path, target);
        return res;
    }
    
     void getTarget(TreeNode* root, vector<int>& path, int target) {
        path.push_back(root->val);
        if(root->val == target && root->left == NULL && root->right == NULL)
            res.push_back(path);
        if(root->left)
            getTarget(root->left, path, target - root->val);
        if(root->right)
            getTarget(root->right, path, target - root->val);
        path.pop_back();
     }
};
```
