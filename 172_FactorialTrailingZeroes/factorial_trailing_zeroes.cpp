#include <iostream>
#include <vector>
#include <cassert>

class Solution 
{
public:
	int trailingZeroes(int n) 
	{
		if (n<5)
		{
			return 0;
		}
		int count = 0;
		int k = n / 5;
		while (k > 0)
		{
			count += k;
			k /= 5;
		}
		return count;
	}
};

int main()
{
	Solution s;
	int n = 0;
	while (n++<1000)
	{
		std::cout << s.trailingZeroes(n) << std::endl;
	}
	system("pause");
	return 0;
}