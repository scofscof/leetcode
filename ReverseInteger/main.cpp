#include <iostream>
#include <vector>

class Solution {
public:
	const std::vector<int> c_max_num_list_{ 2,1,4,7,4,8,3,6,4,7 };
	const std::vector<int> c_min_num_list_{ -2,-1,-4,-7,-4,-8,-3,-6,-4,-8 };
	bool IsInLimit(const std::vector<int>& num_list,bool sign) const
	{
		if (num_list.size() < 10)
		{
			return true;
		}
		if (sign)
		{
			for (size_t i = 0; i != c_max_num_list_.size(); ++i)
			{
				if (num_list[i] > c_max_num_list_[i])
				{
					return false;
				}
				if (num_list[i] < c_max_num_list_[i])
				{
					return true;
				}
			}
		}
		else
		{
			for (size_t i = 0; i != c_min_num_list_.size(); ++i)
			{
				if (num_list[i] < c_min_num_list_[i])
				{
					return false;
				}
				if (num_list[i] > c_min_num_list_[i])
				{
					return true;
				}
			}
		}
		return true;
	}
	int reverse(int x) 
	{
		bool sign = x > 0;
		std::vector<int> num_list;
		num_list.reserve(10);
		while (x != 0)
		{
			num_list.push_back(x % 10);
			x /= 10;
		}
		if (!IsInLimit(num_list, sign))
		{
			return 0;
		}
		int res = 0;
		for (auto it = num_list.begin();it!=num_list.end();++it)
		{
			res = res*10 + *it;
		}
		return res;
	}
};

int main()
{
	int x = 123;
	Solution s;
	std::cout << s.reverse(x) << std::endl;
	x = -123;
	std::cout << s.reverse(x) << std::endl;
	x = 120;
	std::cout << s.reverse(x) << std::endl;
	x = 2147483647;
	std::cout << s.reverse(x) << std::endl;
	system("pause");
	return 0;
}