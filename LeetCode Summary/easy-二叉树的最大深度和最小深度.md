## 问题1 [二叉树的最小深度](http://www.lintcode.com/zh-cn/problem/minimum-depth-of-binary-tree/#)
```
给定一个二叉树，找出其最小深度。

二叉树的最小深度为根节点到最近叶子节点的距离。

样例
给出一棵如下的二叉树:

        1

     /     \ 

   2       3

          /    \

        4      5  

这个二叉树的最小深度为 2
```

#### 代码
* 注意：此题易错，**树的深度的意思是 根节点到 叶子节点 之间的路径长度**。因为深度是必须到叶子节点的距离，因此使用深度遍历时，不能单纯的比较左右子树的递归结果返回较小值，因为对于有单个孩子为空的节点，为空的孩子会返回0，但这个节点并非叶子节点，故返回的结果是错误的。
```C++
int minDepth(TreeNode * root) {
        if(root == NULL) return 0;
        if(root->left==NULL && root->right == NULL) return 1;
        
        //当某边子树为空时：
        else if(root->left && root->right == NULL) return 1 + minDepth(root->left);
        else if(root->left == NULL && root->right) return 1 + minDepth(root->right);
        
        int leftDepth = minDepth(root->left);
        int rightDepth = minDepth(root->right);
        return 1 + (leftDepth <= rightDepth ? leftDepth : rightDepth);
    }
```

## 问题2 [二叉树的最大深度](http://www.lintcode.com/zh-cn/problem/maximum-depth-of-binary-tree/)
```
给定一个二叉树，找出其最大深度。

二叉树的深度为根节点到最远叶子节点的距离。

样例
给出一棵如下的二叉树:

  1
 / \ 
2   3
   / \
  4   5
这个二叉树的最大深度为3.
```

#### 代码
```C++
int maxDepth(TreeNode * root) {
        if(root == NULL) return 0;
        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);
        return 1 + (leftDepth >= rightDepth ? leftDepth : rightDepth);
    }
```
