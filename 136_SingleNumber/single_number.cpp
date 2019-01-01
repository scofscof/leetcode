#include <iostream>
#include<vector>

class Solution {
public:
	int singleNumber(std::vector<int>& nums) 
	{
		int num = 0;
		for (size_t i = 0; i != nums.size(); ++i)
		{
			num ^= nums[i];
		}
		return num;
	}
};

int main()
{
	
	system("pause");
	return 0;
}
