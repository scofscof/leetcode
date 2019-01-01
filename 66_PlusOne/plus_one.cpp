#include <iostream>
#include <vector>

class Solution {
public:
	std::vector<int> plusOne(const std::vector<int>& digits) 
	{
		std::vector<int> results;
		if (digits.empty())
		{
			return results;
		}
		results.reserve(digits.size() + 1);
		int carry = 0;
		int one = 1;
		for (auto it = digits.rbegin();it!=digits.rend();++it)
		{
			int sum = carry + *it + one;
			one = 0;
			if (sum >= 10)
			{
				carry = 1;
				sum -= 10;
			}
			else
			{
				carry = 0;
			}
			results.push_back(sum);
		}
		if (carry == 1)
		{
			results.push_back(carry);
		}
		std::reverse(results.begin(), results.end());
		return results;
	}
};

int main()
{
	std::vector<int> digits = { 0 };
	Solution s;
	std::vector<int> results = s.plusOne(digits);
	for (auto res : results)
	{
		std::cout << res;
	}
	std::cout << std::endl;
	system("pause");
	return 0;
}