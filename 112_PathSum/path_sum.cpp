#include <iostream>
#include <vector>
#include <cassert>


//Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution 
{
public:
	bool hasPathSum(TreeNode* root, int sum) 
	{
		if (root != NULL)
		{
			if (root->val == sum && root->left == NULL && root->right == NULL)
			{
				return true;
			}
			else
			{
				sum -= root->val;
				if (root->left != NULL)
				{
					if (hasPathSum(root->left, sum))
					{
						return true;
					}
				}
				if (root->right != NULL)
				{
					if (hasPathSum(root->right, sum))
					{
						return true;
					}
				}
			}
		}
		return false;
	}
};

int main()
{
	system("pause");
	return 0;
}