#pragma once
#include <vector>
#include <algorithm>
#include <unordered_map>

//////////////////////////////////////////////////////////////////////////
/*
两数之和：
给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。

你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。

示例:

给定 nums = [2, 7, 11, 15], target = 9

因为 nums[0] + nums[1] = 2 + 7 = 9
所以返回 [0, 1]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/two-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
//////////////////////////////////////////////////////////////////////////
/*!
 * @brief 暴力法，直接顺序遍历遍历目标数组，然后对于每一个值num1，查找数组中是否存在另一个值num2，使得num1+num2==target
 *
 * @author subai
 * @date 2019/1/6
 */
class Solution {
public:
	std::vector<int> twoSum(std::vector<int>& nums, int target) 
	{
		std::vector<int> res(2,-1);
		for (size_t i = 0;i!=nums.size();++i)
		{
			int num1 = nums[i];
			for (size_t j = i+1;j!=nums.size();++j)
			{
				int num2 = nums[j];
				if (num1 + num2 == target)
				{
					res[0] = static_cast<int>(i);
					res[1] = static_cast<int>(j);
				}
			}
		}
		return res;
	}
};
/*!
 * @brief 哈希表一遍遍历法。
 遍历数组，将数组中的值以及所在的位置放在hash表中，在添加到hash表之前，先查看表中是否存在target-num[i]的值
 *
 * @author subai
 * @date 2019/1/6
 */
class Solution2 {
public:
	std::vector<int> twoSum(std::vector<int>& nums, int target)
	{
		std::vector<int> res(2, -1);
		std::unordered_map<int, size_t> temp_map;
		for (size_t i = 0; i != nums.size(); ++i)
		{
			auto it = temp_map.find(target - nums[i]);
			if (it!=temp_map.end())
			{
				res[0] = static_cast<int>(it->second);
				res[1] = static_cast<int>(i);
				break;
			}
			temp_map.insert(std::make_pair(nums[i], i));
		}
		return res;
	}
};
