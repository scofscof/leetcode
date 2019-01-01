#include <iostream>
#include <vector>
#include <cassert>
#include<iomanip>

class Solution 
{
private:
	std::vector<int> generateNext(const std::vector<int>& row_list)
	{
		std::vector<int> next_row_list;
		next_row_list.reserve(row_list.size() + 1);
		if (row_list.empty())
		{
			next_row_list.push_back(1);
			return next_row_list;
		}
		next_row_list.push_back(row_list[0]);

		for (size_t i = 1;i!=row_list.size();++i)
		{
			next_row_list.push_back(row_list[i - 1] + row_list[i]);
		}

		next_row_list.push_back(row_list[row_list.size() - 1]);
		return next_row_list;
	}
public:
	std::vector<std::vector<int>> generate(int numRows) 
	{
		std::vector<std::vector<int>> res_list(numRows);
		assert(numRows >= 0);
		std::vector<int> row_list;
		for (int i = 0;i!=numRows;++i)
		{
			row_list = generateNext(row_list);
			res_list[i] = row_list;
		}
		return res_list;
	}
};

int main()
{
	const int max_digit = 8;
	while (1)
	{
		std::cout << "输入杨辉三角的行数:";
		int num = 0;
		std::cin >> num;
		if (num <= 0)
		{
			continue;
		}
		Solution s;
		std::vector<std::vector<int>> res_list = s.generate(num);
		for (size_t i = 0; i != res_list.size(); ++i)
		{
			int space_count = (num - res_list[i].size())*max_digit / 2;
			for (int j = 0; j != space_count; ++j)
			{
				std::cout << " ";
			}
			for (size_t j = 0; j != res_list[i].size(); ++j)
			{
				std::cout << std::setw(max_digit)<<res_list[i][j];
			}
			std::cout << std::endl;
		}
	}

	return 0;
}