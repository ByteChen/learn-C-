## [二叉搜索树与双向链表](https://www.nowcoder.net/questionTerminal/947f6eb80d944a84850b0538bf0ec3a5)
输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。要求不能创建任何新的结点，只能调整树中结点指针的指向。

## 代码
* 由于总是要遍历树，所以分为递归式遍历和非递归遍历两种方法。
#### 1. 递归式
```C++
/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/

class Solution {
public:
    bool isFirstNode = true;
    TreeNode* result;
    TreeNode* lastPtr;
    
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if(pRootOfTree == NULL)
            return NULL;
        result = NULL;
        midTraversal(pRootOfTree);
        return result;
    }
    
    void midTraversal(TreeNode* root)
    {
        if(root->left)
            midTraversal(root->left);
        
        if(isFirstNode)
        {
            isFirstNode = false;
            root->left = NULL;
            result = root;
            lastPtr = root;
        } else {
            lastPtr->right = root;
            root->left = lastPtr;
            lastPtr = root;
        }
        
        if(root->right)
            midTraversal(root->right);
    }
};
```

