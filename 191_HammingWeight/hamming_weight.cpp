#include <iostream>
#include <vector>
#include <cassert>

class Solution
{
public:
	int hammingWeight(uint32_t n)
	{
		int weight = 0;
		for (int i = 0;i!=32;++i)
		{
			if ((n>>i)&1)
			{
				++weight;
			}
		}
		return weight;
	}
};
int main()
{
	Solution s;
	for (int i = 1;i!=100;++i)
	{
		std::cout << i << ":" << s.hammingWeight(i)<<std::endl;
	}
	system("pause");
	return 0;
}