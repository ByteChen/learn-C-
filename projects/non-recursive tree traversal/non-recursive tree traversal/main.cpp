//µü´ú·¨±éÀúÊ÷¡£

#include<iostream>
#include<stack>

using namespace std;

struct TreeNode
{
	TreeNode* left;
	TreeNode* right;
	int val;

	TreeNode(int i) :val(i), left(nullptr), right(nullptr) {}
};

void display(TreeNode* p)
{
	cout << p->val << ' ';
}

void preOrder(TreeNode *root)
{
	stack<TreeNode*> s;
	while (root || !s.empty())
	{
		while (root)
		{
			display(root);
			s.push(root);
			root = root->left;
		}
		root = s.top();
		s.pop();
		root = root->right;
	}
}

void postOrder(TreeNode* root)
{
	stack<TreeNode*> s;
	TreeNode* pre = nullptr;
	while (root || !s.empty())
	{
		while (root)
		{
			s.push(root);
			root = root->left;
		}
		if (!s.empty())
		{
			root = s.top();
			if (root->right && root->right != pre)
			{
				root = root->right;
			}
			else
			{
				display(root);
				pre = root;
				root = nullptr;
				s.pop();
			}
		}
		
	}
}

void inOrder(TreeNode* root)
{
	stack<TreeNode*> s;

	while (root || !s.empty())
	{
		while (root)
		{
			s.push(root);
			root = root->left;
		}
		root = s.top();
		s.pop();
		display(root);
		root = root->right;
	}
}

int main()
{
	TreeNode a = TreeNode(1);
	TreeNode b = TreeNode(2);
	TreeNode c = TreeNode(3);
	TreeNode d = TreeNode(4);
	TreeNode e = TreeNode(5);
	TreeNode f = TreeNode(6);
	TreeNode g = TreeNode(7);
	TreeNode h = TreeNode(8);
	TreeNode i = TreeNode(9);
	TreeNode j = TreeNode(10);

	a.left = &b;
	a.right = &c;
	b.left = &d;
	b.right = &e;
	c.left = &f;
	c.right = &g;
	
	cout << "preorder traversal : ";
	preOrder(&a);
	cout << endl;

	cout << "postorder traversal: ";
	postOrder(&a);
	cout << endl;
	
	cout << "inorder traversal  : ";
	inOrder(&a);
	cout << endl;

	system("pause");
	return 0;
}