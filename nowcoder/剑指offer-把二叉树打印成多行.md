## [把二叉树打印成多行](https://www.nowcoder.com/questionTerminal/445c44d982d04483b04a54f298796288)
从上到下按层打印二叉树，同一层结点从左至右输出。每一层输出一行。

## 代码
* 思路：很直接想到使用**层序遍历**算法，不过需要知道什么时候应该换行。 可以引入两个标志位，一个表示当前层的剩余节点数，一个是下一层的节点数。
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
            if(pRoot == NULL) return {};
            vector<vector<int> > res;
            vector<int> temp;
            queue<TreeNode*> q;
            q.push(pRoot);
            int thisLevel = 1;    //当前层的剩余节点数
            int nextLevel = 0;    //下一层的节点数
            while(!q.empty()) {
                if(thisLevel == 0) {    //当当前层的节点数输出完，则换行
                    res.push_back(temp);
                    temp.clear();
                    thisLevel = nextLevel;
                    nextLevel = 0;
                }
                pRoot = q.front();        //queue 没有top()方法，而是front（）方法
                q.pop();
                thisLevel --;
                temp.push_back(pRoot->val);
                if(pRoot->left) {
                    q.push(pRoot->left);
                    nextLevel ++;
                }
                if(pRoot->right) {
                    q.push(pRoot->right);
                    nextLevel ++;
                }
            }
            res.push_back(temp);
            return res;
        }
    
};
```

#### 看到别人的更简洁的代码,算法复杂度应该是一样的。
* 因为当刚访问到新一层的时候，说明这一层已经全部转入队列中，且下一层的还没有入队。因此，此时队列的大小就是当前层的节点数，可以把当前层一口气输出。
```C++
class Solution {
public:
        vector<vector<int> > Print(TreeNode* pRoot) {
            vector<vector<int> > vec;
            if(pRoot == NULL) return vec;
 
            queue<TreeNode*> q;
            q.push(pRoot);
 
            while(!q.empty())
            {
                int lo = 0, hi = q.size();
                vector<int> c;
                while(lo++ < hi)
                {
                    TreeNode *t = q.front();
                    q.pop();
                    c.push_back(t->val);
                    if(t->left) q.push(t->left);
                    if(t->right) q.push(t->right);
                }
                vec.push_back(c);
            }
            return vec;
        }
};
```
