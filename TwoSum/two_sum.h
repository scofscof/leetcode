#pragma once
#include <vector>
#include <algorithm>

class Solution {
public:
	std::vector<int> twoSum(std::vector<int>& nums, int target) 
	{
		std::vector<int> res(2,0);
		for (size_t i = 0;i!=nums.size();++i)
		{
			int num1 = nums[i];
			for (size_t j = i+1;j!=nums.size();++j)
			{
				int num2 = nums[j];
				if (num1 + num2 == target)
				{
					res[0] = i;
					res[1] = j;
				}
			}
		}
		return res;
	}
};
