#pragma once
#include <iostream>
#include <vector>
#include <cassert>
#include <set>
#include <algorithm>

class Solution 
{
public:
	bool containsDuplicate(std::vector<int>& nums) 
	{
		std::set<int> temp_list(nums.begin(), nums.end());
		return temp_list.size() != nums.size();
	}
};


int main()
{
	Solution s;
	std::vector<int> nums = { 3,1,2,3,1,4 };
	bool res = s.containsDuplicate(nums);

	system("pause");
	return 0;
}



