#include <iostream>
#include <vector>
#include <cassert>

class Solution
{
	bool IsMajority(int major, const std::vector<int>& nums) const
	{
		int count = 0;
		for (auto num : nums)
		{
			if (major == num)
			{
				++count;
			}
		}
		return count > nums.size() / 3;
	}
public:
	std::vector<int> majorityElement(const std::vector<int>& nums)
	{
		std::vector<int> res_list;
		if (nums.empty())
		{
			return res_list;
		}
		int major1 = -1, major2 = -1;
		int count1 = 0, count2 = 0;
		for (auto num : nums)
		{
			if (num == major1)
			{
				++count1;
			}
			else if (num == major2)
			{
				++count2;
			}
			else if (count1 == 0 && num != major2)
			{
				major1 = num;
				++count1;
			}
			else if (count2 == 0 && num != major1)
			{
				major2 = num;
				++count2;
			}
			else
			{
				--count1;
				--count2;
			}
		}
		if (IsMajority(major1,nums))
		{
			res_list.push_back(major1);
		}
		if (IsMajority(major2, nums))
		{
			res_list.push_back(major2);
		}
		return res_list;
	}
};

int main()
{
	Solution s;
	std::vector<int> nums = { 2,3,2,3,2,1,3,4,2,3 };
	std::vector<int> res_list = s.majorityElement(nums);
	for (auto res : res_list)
	{
		std::cout << res << std::endl;
	}
	system("pause");
	return 0;
}