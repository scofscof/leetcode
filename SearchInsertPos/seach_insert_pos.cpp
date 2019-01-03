#include <iostream>
#include <vector>
#include <algorithm>
/************************************************************************/
/*给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
你可以假设数组中无重复元素。
	示例 1:
		输入: [1, 3, 5, 6], 5
		输出 : 2
	示例 2 :
		输入 : [1, 3, 5, 6], 2
		输出 : 1
	示例 3 :
		输入 : [1, 3, 5, 6], 7
		输出 : 4
	示例 4 :
		输入 : [1, 3, 5, 6], 0
		输出 : 0 */
/************************************************************************/

class Solution1 
{
public:
	int searchInsert(std::vector<int>& nums, int target) 
	{
		auto it = std::lower_bound(nums.begin(), nums.end(), target);
		return it - nums.begin();
	}
};

class Solution2 
{
	typedef std::vector<int>::iterator IntIter;
	IntIter searchInsertImpl(IntIter begin, IntIter end, int target)
	{
		if (begin == end)
		{
			return begin;
		}
		IntIter mid = begin + (end - begin) / 2;
		if (*mid == target)
		{
			return mid;
		}
		if (*mid < target)
		{
			return searchInsertImpl(mid+1, end, target);
		}
		else
		{
			return searchInsertImpl(begin, mid, target);
		}
	}
public:
	int searchInsert(std::vector<int>& nums, int target)
	{
		return searchInsertImpl(nums.begin(), nums.end(), target) - nums.begin();
	}
};

int main()
{
	Solution2 s;
	std::vector<int> nums1 = { 1, 3, 5, 6 };
	int pos1 = s.searchInsert(nums1, 5);
	std::cout << pos1 << std::endl;

	std::vector<int> nums2 = { 1, 3, 5, 6 };
	int pos2 = s.searchInsert(nums2, 2);
	std::cout << pos2 << std::endl;

	std::vector<int> nums3 = { 1, 3, 5, 6 };
	int pos3 = s.searchInsert(nums3, 7);
	std::cout << pos3 << std::endl;

	std::vector<int> nums4 = { 1, 3, 5, 6 };
	int pos4 = s.searchInsert(nums4, 0);
	std::cout << pos4 << std::endl;
	system("pause");
	return 0;
}
