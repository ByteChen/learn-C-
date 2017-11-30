## 问题
Given an integer array with no duplicates. A maximum tree building on this array is defined as follow:

1. The root is the maximum number in the array.
2. The left subtree is the maximum tree constructed from left part subarray divided by the maximum number.
3. The right subtree is the maximum tree constructed from right part subarray divided by the maximum number.

Construct the maximum tree by the given array and output the root node of this tree.

Example 1:
```
Input: [3,2,1,6,0,5]
Output: return the tree root node representing the following tree:

      6
    /   \
   3     5
    \    / 
     2  0   
       \
        1
```        
Note:
* The size of the given array will be in the range [1,1000].

## 代码
#### 代码1:之前做的，不够简洁
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
	TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
		if (nums.size() == 0) return NULL;
		TreeNode* head;
		//head = new TreeNode(max(nums,0,nums.size()));
		vector<int> result = max(nums, 0, nums.size());
		int maxNum = result[0];
		int index = result[1];
		head = new TreeNode(maxNum);
		if (index != 0)
		{
			vector<int> vec;
			copy(&nums[0], &nums[index], back_inserter(vec));
			head->left = constructMaximumBinaryTree(vec);
		}
		if (index != nums.size() - 1)
		{
			vector<int> vec2;
			//copy(&nums[index + 1], &nums[nums.size()], back_inserter(vec));
			copy(nums.begin()+index+1, nums.end(), back_inserter(vec2));
			head->right = constructMaximumBinaryTree(vec2);
		}
		return head;
	}

	vector<int> max(vector<int> nums, int left, int right)
	{
		//int maxNum, index;
		int maxNum = nums[left];
		int  index = left;
		for (int i = left + 1; i < right; i++)
		if (maxNum<nums[i])
		{
			maxNum = nums[i]; index = i;
		}
		return{ maxNum, index };
	}
};
```

#### 代码2：今天做的，递归问题，在原函数的基础上，再写另一个函数专门用于递归，且参数更详细，方便统一处理。
```c++
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        //int max = findMax(nums, 0, nums.size());
        TreeNode *root = construct(nums, 0, nums.size());
        return root;
    }
    
    TreeNode* construct(vector<int>& nums, int left, int right)
    {
        if(left >= right) return NULL;
        int max = findMax(nums, left, right);
        TreeNode *root = new TreeNode(nums[max]);
        root->left = construct(nums, left, max);
        root->right = construct(nums, max+1, right);
        return root;
    }
    
    int findMax(vector<int>& nums, int left, int right)
    {
        int max = nums[left];
        int index = left;
        for(int i=left; i<right; i++)
        {
            if(nums[i] > max)
            {
                index = i;
                max = nums[i];
            }
        }
        return index;
    }
};
```
