#include <iostream>
#include <vector>
#include <algorithm>
/************************************************************************/
/*����һ�����������һ��Ŀ��ֵ�����������ҵ�Ŀ��ֵ�������������������Ŀ��ֵ�������������У����������ᱻ��˳������λ�á�
����Լ������������ظ�Ԫ�ء�
	ʾ�� 1:
		����: [1, 3, 5, 6], 5
		��� : 2
	ʾ�� 2 :
		���� : [1, 3, 5, 6], 2
		��� : 1
	ʾ�� 3 :
		���� : [1, 3, 5, 6], 7
		��� : 4
	ʾ�� 4 :
		���� : [1, 3, 5, 6], 0
		��� : 0 */
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
