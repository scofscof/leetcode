#include <iostream>
#include <string>
#include <map>

class Solution {
	struct SymbolLink
	{
		char unus;
		char quinque;
		char decem;
		SymbolLink* next;
		SymbolLink()
		{
			next = nullptr;
		}
		~SymbolLink()
		{
			delete next;
			next = nullptr;
		}
	};
	SymbolLink* link_;
public:
	Solution()
	{
		link_ = new SymbolLink;

		SymbolLink* one = new SymbolLink;
		one->unus = 'I';
		one->quinque = 'V';
		one->decem = 'X';
		link_->next = one;

		SymbolLink* ten = new SymbolLink;
		ten->unus = 'X';
		ten->quinque = 'L';
		ten->decem = 'C';
		one->next = ten;

		SymbolLink* hundred = new SymbolLink;
		hundred->unus = 'C';
		hundred->quinque = 'D';
		hundred->decem = 'M';
		ten->next = hundred;

		SymbolLink* thousand = new SymbolLink;
		thousand->unus = 'M';
		thousand->quinque = 'E';
		hundred->next = thousand;
	}
	~Solution()
	{
		delete link_;
		link_ = nullptr;
	}
	std::string intToRoman(int num)
	{
		std::string res_str;
		SymbolLink* link = link_->next;
		while (num != 0)
		{
			if (link == nullptr)
			{
				break;
			}
			int remainder = num % 10;
			if (remainder >= 5)
			{
				if (remainder == 9)
				{
					res_str = link->unus + (link->decem + res_str);
				}
				else
				{
					remainder -= 5;
					while (remainder-- > 0)
					{
						res_str = link->unus + res_str;
					}
					res_str = link->quinque + res_str;
				}
			}
			else
			{
				if (remainder == 4)
				{
					res_str = link->unus + (link->quinque + res_str);
				}
				else
				{
					while (remainder-- > 0)
					{
						res_str = link->unus + res_str;
					}
				}
			}
			link = link->next;
			num /= 10;
		}
		return res_str;
	}
};

int main()
{
	int num = 3;
	Solution s;
	std::cout << s.intToRoman(num) << std::endl;
	num = 4;
	std::cout << s.intToRoman(num) << std::endl;
	num = 9;
	std::cout << s.intToRoman(num) << std::endl;
	num = 58;
	std::cout << s.intToRoman(num) << std::endl;
	num = 1994;
	std::cout << s.intToRoman(num) << std::endl;
	system("pause");
	return 0;
}
