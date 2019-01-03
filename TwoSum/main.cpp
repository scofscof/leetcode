#include <iostream>
#include <cassert>
#include "two_sum.h"

int main()
{
	std::vector<int> arr{ 7, 11, 2, 15 };
	int target = 9;
	Solution s;
	std::vector<int> res = s.twoSum(arr, target);
	assert(res.size() == 2);
	std::cout << res[0] << "," << res[1] << std::endl;
	return 0;
}