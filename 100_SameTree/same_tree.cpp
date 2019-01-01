#include <iostream>


//Definition for a binary tree node.
struct TreeNode 
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution 
{
public:
	bool isSameTree(TreeNode* p, TreeNode* q) 
	{
		if (p == nullptr)
		{
			return q == nullptr;
		}
		else if(q == nullptr)
		{
			return p == nullptr;
		}
		if (p->val != q->val)
		{
			return false;
		}
		return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
	}
};

int main()
{
	Solution s;
	std::cout << s.isSameTree(0,0);

	system("pause");
	return 0;
}