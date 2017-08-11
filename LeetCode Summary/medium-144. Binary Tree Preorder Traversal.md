## 问题
使用**非递归**的方法遍历树
Given a binary tree, return the preorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
```
   1
    \
     2
    /
   3
```
return [1,2,3].

Note: Recursive solution is trivial, could you do it iteratively?

## 代码
```C++
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    //初始方法，类似于非迭代的中序遍历，打败0.92%
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        vector<int> v;
        while(root || !s.empty())
        {
            while(root)
            {
                v.push_back(root->val);
                s.push(root);
                root = root->left;
            }
            root = s.top();
            s.pop();
            root = root->right;
        }
        return v;
    }
    
    
    //首选，比较不错的方法，只入栈右孩子 beat 70%
    vector<int> preorderTraversal(TreeNode* root) {
        if(root == NULL) return {};
        stack<TreeNode*> s;
        vector<int> v;
        s.push(root);
        while(!s.empty())
        {
            while(root)
            {
                v.push_back(root->val);
                if(root->right) s.push(root->right);
                root = root->left;
            }
            root = s.top();
            s.pop();
        }
        return v;
    }
    
    
    //最容易记的方法，只要记住先入栈 右孩子，然后 左孩子 即可。
    //不过由于不必要的入栈/弹栈，导致慢
    vector<int> preorderTraversal(TreeNode* root) {
        if(root == NULL) return vector<int>();
        stack<TreeNode*> s;
        vector<int> v;
        s.push(root);
        while(!s.empty())
        {
            root = s.top();
            v.push_back(root->val); 
            s.pop();                
            if(root->right) s.push(root->right);
            if(root->left)  s.push(root->left); //这里入栈，紧接着又弹栈，浪费时间
        }
        return v;
    }
   
    //别人的高分答案，和上面思想一样，比我的low一点
    vector<int> preorderTraversal(TreeNode *root) {
        if (root==NULL) {
            return vector<int>();
        }
        vector<int> result;
        stack<TreeNode *> treeStack;
        treeStack.push(root);
        while (!treeStack.empty()) {
            TreeNode *temp = treeStack.top();
            result.push_back(temp->val);
            treeStack.pop();
            if (temp->right!=NULL) {
                treeStack.push(temp->right);
            }
            if (temp->left!=NULL) {
                treeStack.push(temp->left);
            }
        }
        return result;
    }
};
```
