#pragma once
#include <iostream>
#include <vector>
#include <cassert>
#include <set>
#include <algorithm>

class Solution
{
public:
	std::vector<int> findDisappearedNumbers(std::vector<int>& nums)
	{
		/*std::vector<int> temp(nums.size()+1, 0);
		for (auto num : nums)
		{
			temp[num] = 1;
		}
		std::vector<int> res_list;
		res_list.reserve(temp.size());
		for (size_t i = 0; i < temp.size(); i++)
		{
			if (temp[i] == 0 && i!=0)
			{
				res_list.push_back(i);
			}
		}
		return res_list;*/
		for (int i = 0; i < nums.size(); ++i) {
			nums[abs(nums[i]) - 1] = -abs(nums[abs(nums[i]) - 1]);
		}
		std::vector<int> ans;
		for (int i = 0; i < nums.size(); ++i) {
			if (nums[i] > 0) {
				ans.push_back(i + 1);
			}
		}
		return ans;
	}
};


int main()
{
	Solution s;
	std::vector<int> nums = { 4,3,2,7,8,2,3,1 };
	std::vector<int> res = s.findDisappearedNumbers(nums);

	system("pause");
	return 0;
}



