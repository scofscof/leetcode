#include <iostream>
#include <vector>
#include <cassert>

class Solution1 
{
public:
	void rotate(std::vector<int>& nums, int k) 
	{
		if (nums.empty())
		{
			return;
		}
		while (k-- > 0)
		{
			int t = nums[nums.size() - 1];
			for (size_t i = nums.size()-1;i > 0;--i)
			{
				nums[i] = nums[i - 1];
			}
			nums[0] = t;
		}
	}
};

//ø’º‰∏¥‘”∂»O(k)
class Solution
{
public:
	void rotate(std::vector<int>& nums, int k)
	{
		if (nums.empty())
		{
			return;
		}
		k %= nums.size();
		std::vector<int> temp(nums.rbegin(), nums.rbegin() + k);
		for (int i = nums.size()-1; i >= k; --i)
		{
			nums[i] = nums[i - k];
		}
		int i = 0;
		for (auto it = temp.rbegin();it!=temp.rend();++it)
		{
			nums[i++] = *it;
		}
	}
};

int main()
{
	std::vector<int> nums = { 1,2,3,4,5,6,7 };
	Solution s;
	s.rotate(nums, 56);
	for (auto num:nums)
	{
		std::cout << num;
	}
	std::cout << std::endl;
	system("pause");
	return 0;
}