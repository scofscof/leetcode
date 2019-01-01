#include <iostream>
#include <vector>
#include <cassert>

class Solution 
{
public:
	int majorityElement(std::vector<int>& nums)
	{
		if (nums.empty())
		{
			assert(0);
			return -1;
		}
		int major,count = 0;
		for (auto num : nums)
		{
			if (count == 0)
			{
				major = num;
				++count;
			}
			else
			{
				major == num ? (++count) : (--count);
			}
		}
		count = 0;
		for (auto num : nums)
		{
			major == num ? (++count) : (--count);
		}

		return count > 0 ? major : -1;
	}
};

int main()
{
	Solution s;
	std::vector<int> nums = { 2,2,2,1,3,4,2 };
	std::cout << s.majorityElement(nums)<<std::endl;
	system("pause");
	return 0;
}