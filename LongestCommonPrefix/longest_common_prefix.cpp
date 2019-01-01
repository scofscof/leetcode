#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
	std::string longestCommonPrefix(std::vector<std::string>& strs) 
	{
		std::string common_prefix;
		if (strs.empty())
		{
			return common_prefix;
		}
		size_t k = 0;
		char flag;
		while (1)
		{
			for (size_t i = 0; i != strs.size(); ++i)
			{
				const std::string& str = strs[i];
				if (k >= str.size())
				{
					return common_prefix;
				}
				if (i == 0)
				{
					flag = str[k];
				}
				else
				{
					if (str[k] != flag)
					{
						return common_prefix;
					}
				}
				if (i == strs.size()-1)
				{
					common_prefix += flag;
				}
			}
			k++;
		}
	}
};

int main()
{
	Solution s;
	std::vector<std::string> strs1{ "flower","flow","flight" };
	std::cout << s.longestCommonPrefix(strs1)<<std::endl;
	std::vector<std::string> strs2{ "dog","racecar","car" };
	std::cout << s.longestCommonPrefix(strs2) << std::endl;
	system("pause");
	return 0;
}