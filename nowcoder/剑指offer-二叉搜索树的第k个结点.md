## [二叉搜索树的第k个结点](https://www.nowcoder.com/questionTerminal/ef068f602dde4d28aab2b210e859150a)
给定一颗二叉搜索树，请找出其中的第k大的结点。例如， 5 / \ 3 7 /\ /\ 2 4 6 8 中，按结点数值大小顺序第三个结点的值为4。

## 代码
* 涉及树的问题，大都是遍历，又分为递归和非递归遍历。
#### 递归法
```C++
TreeNode* KthNode(TreeNode* pRoot, int k)
    {
        if(k <= 0 || pRoot == NULL) return NULL;
        return getKth(pRoot, k);
        
    }
    
    TreeNode* getKth(TreeNode* p, int& k) {
        if(p == NULL) return NULL;
        if(p->left) {
            TreeNode* temp = getKth(p->left, k);      //需要接收返回值，然后判断如果K此时等于0，表明找到了结果
            if(k == 0)
                return temp;
        }
        if(--k == 0)
            return p;
        if(p->right) {
            TreeNode* temp = getKth(p->right, k);
            if(k == 0)
                return temp;
        }
        return NULL;
        
    }
```


#### 非递归法 比较直观
```C++
TreeNode* KthNode(TreeNode* pRoot, int k)
    {
        if(pRoot == NULL || k < 1) return NULL;
        stack<TreeNode*> s;
        TreeNode* root = pRoot;
        while(root || !s.empty()) {
            while(root) {
                s.push(root);
                root = root->left;
            }
            root = s.top();
            s.pop();
            if(--k == 0)
                return root;
            root = root->right;
        }
        return NULL;
    }
```




