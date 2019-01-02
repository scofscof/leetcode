#include <iostream>
#include <vector>
#include <cassert>

class Solution 
{
public:
	uint32_t reverseBits(uint32_t n) 
	{
		return ((n & 0x1) << 31) |
			((n & 0x2) << 29) |
			((n & 0x4) << 27) |
			((n & 0x8) << 25) |
			((n & 0x10) << 23) |
			((n & 0x20) << 21) |
			((n & 0x40) << 19) |
			((n & 0x80) << 17) |
			((n & 0x100) << 15) |
			((n & 0x200) << 13) |
			((n & 0x400) << 11) |
			((n & 0x800) << 9) |
			((n & 0x1000) << 7) |
			((n & 0x2000) << 5) |
			((n & 0x4000) << 3) |
			((n & 0x8000) << 1) |
			((n & 0x10000) >> 1) |
			((n & 0x20000) >> 3) |
			((n & 0x40000) >> 5) |
			((n & 0x80000) >> 7) |
			((n & 0x100000) >> 9) |
			((n & 0x200000) >> 11) |
			((n & 0x400000) >> 13) |
			((n & 0x800000) >> 15) |
			((n & 0x1000000) >> 17) |
			((n & 0x2000000) >> 19) |
			((n & 0x4000000) >> 21) |
			((n & 0x8000000) >> 23) |
			((n & 0x10000000) >> 25) |
			((n & 0x20000000) >> 27) |
			((n & 0x40000000) >> 29) |
			((n & 0x80000000) >> 31) ;
	}
};

int main()
{
	std::vector<int> nums = { 1000,20000,30000,4000,005000,60000,7000 };
	Solution s;
	
	for (auto num : nums)
	{
		std::cout << s.reverseBits(num) << std::endl;
	}
	std::cout << std::endl;
	system("pause");
	return 0;
}