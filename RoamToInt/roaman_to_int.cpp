#include <iostream>
#include <string>
#include <map>

class Solution {
	std::map<char, int> symbol_table_;
public:
	Solution()
	{
		symbol_table_['I']= 1   ;
		symbol_table_['V']= 5   ;
		symbol_table_['X']= 10  ;
		symbol_table_['L']= 50  ;
		symbol_table_['C']= 100 ;
		symbol_table_['D']= 500 ;
		symbol_table_['M'] = 1000;
	}
	int romanToInt(std::string s) 
	{
		int res = 0;
		for (size_t i = 0;i!=s.size();/*++i*/)
		{
			if (i+1<s.size())
			{
				if (s[i] == 'I' && s[i+1] == 'V')
				{
					res += 4;
					i += 2;
					continue;
				}
				else if(s[i] == 'I' && s[i + 1] == 'X')
				{
					res += 9;
					i += 2;
					continue;
				}
				else if (s[i] == 'X' && s[i + 1] == 'L')
				{
					res += 40;
					i += 2;
					continue;
				}
				else if (s[i] == 'X' && s[i + 1] == 'C')
				{
					res += 90;
					i += 2;
					continue;
				}
				else if (s[i] == 'C' && s[i + 1] == 'D')
				{
					res += 400;
					i += 2;
					continue;
				}
				else if (s[i] == 'C' && s[i + 1] == 'M')
				{
					res += 900;
					i += 2;
					continue;
				}
			}
			auto it = symbol_table_.find(s[i]);
			if (it!=symbol_table_.end())
			{
				res += it->second;
				++i;
			}
			else
			{
				return 0;
			}
		}
		return res;
	}
};

int main()
{
	std::string str = "III";
	Solution s;
	std::cout << s.romanToInt(str) << std::endl;
	str = "IV";
	std::cout << s.romanToInt(str) << std::endl;
	str = "IX";
	std::cout << s.romanToInt(str) << std::endl;
	str = "LVIII";
	std::cout << s.romanToInt(str) << std::endl;
	str = "MCMXCIV";
	std::cout << s.romanToInt(str) << std::endl;
	system("pause");
	return 0;
}
