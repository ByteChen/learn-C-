## [对称的二叉树](https://www.nowcoder.com/questionTerminal/ff05d44dfdb04e1d83bdbdab320efbcb)

请实现一个函数，用来判断一颗二叉树是不是对称的。注意，如果一个二叉树同此二叉树的镜像是同样的，定义其为对称的。

## 代码
#### 递归的方法
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
	bool isSymmetrical(TreeNode* pRoot)
	{
        if(pRoot == NULL) return true;
        return check(pRoot->left, pRoot->right);
    }
    
    bool check(TreeNode* p1, TreeNode* p2) {
        if(p1==NULL && p2==NULL) return true;
        if((p1 && p2==NULL) ||(p1==NULL && p2))
            return false;
        if(p1->val != p2->val)
            return false;
        return check(p1->left, p2->right) && check(p1->right, p2->left);
    }
};
```

#### 迭代法
* 树的问题很多时候都转化为树的遍历，要么递归法，要么迭代。
* 此题使用层序遍历。平时写层序遍历时，判断到树的子节点为NULL时，就不再push入队。不过因为现在相当于比较两棵树，树可能是非完全的，有时候值相等，但是位置不对称，所以应该把NULL也push。

```C++
class Solution {
public:
	bool isSymmetrical(TreeNode* pRoot)
	{
        if (pRoot == NULL) return true;
		queue<TreeNode*> q1, q2;
		//if (pRoot->left->val != pRoot->right->val) return false;
		q1.push(pRoot->left);
		q2.push(pRoot->right);

		TreeNode* t1, *t2;
        while(!q1.empty() && !q2.empty()) {
            t1 = q1.front(); q1.pop();
            t2 = q2.front(); q2.pop();
            if(t1 == NULL && t2 == NULL)
                continue;
            //if((t1==NULL && t2) || (t1 &&t2==NULL))     //可以简化为：
            if(t1 == NULL || t2 ==NULL)
                return false;
            if(t1->val != t2->val) return false;
            q1.push(t1->left);
            q2.push(t2->right);
            q1.push(t1->right);
            q2.push(t2->left);
        }
        return true;
    }
};
```
