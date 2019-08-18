#include <iostream>
#include <vector>
#include <string>
#include <cassert>

class Solution
{
public:
	std::vector<std::string> generateParenthesis(int n)
	{
		std::vector<std::string> parenthesis_list;
		GenerateImpl(n, n, 0, "", parenthesis_list);
		return parenthesis_list;
	}
private:
	void GenerateImpl(int l,int r,int cur,std::string str,std::vector<std::string>& parenthesis_list)
	{
		if (l == 0 && r == 0)
		{
			parenthesis_list.push_back(str);
			return;
		}
		if (cur == 0)
		{
			str += "(";
			GenerateImpl(l-1, r, cur+1, str, parenthesis_list);
		}
		else
		{
			assert(cur > 0);
			if (l==0)
			{
				assert(r > 0);
				for (int j = 0;j<r;++j)
				{
					str += ")";
				}
				r = 0;
				cur = 0;
				GenerateImpl(l, r, cur, str, parenthesis_list);
			}
			else
			{
				assert(r != 0);
				GenerateImpl(l - 1, r, cur + 1, str+"(", parenthesis_list);
				GenerateImpl(l, r-1, cur - 1, str+")", parenthesis_list);
			}
		}
	}
};

void PrintPatrenthesis(const std::vector<std::string>& parenthesis_list)
{
	for (size_t i =0;i!=parenthesis_list.size();++i)
	{
		std::cout << parenthesis_list[i] << std::endl;
	}
}

int main()
{
	Solution s;
	std::cout << "count:" << 2 << std::endl;
	PrintPatrenthesis(s.generateParenthesis(2));
	std::cout << "count:" << 3 << std::endl;
	PrintPatrenthesis(s.generateParenthesis(3));
	std::cout << "count:" << 4 << std::endl;
	PrintPatrenthesis(s.generateParenthesis(4));
	std::cout << "count:" << 5 << std::endl;
	PrintPatrenthesis(s.generateParenthesis(5));
	std::cout << "count:" << 6 << std::endl;
	PrintPatrenthesis(s.generateParenthesis(6));
	std::cout << "count:" << 22 << std::endl;
	PrintPatrenthesis(s.generateParenthesis(22));
	system("pause");
	return 0;
}