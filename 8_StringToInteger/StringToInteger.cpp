#include <string>
#include <iostream>
#include <cassert>
//////////////////////////////////////////////////////////////////////////
/*
请你来实现一个 atoi 函数，使其能将字符串转换成整数。

首先，该函数会根据需要丢弃无用的开头空格字符，直到寻找到第一个非空格的字符为止。

当我们寻找到的第一个非空字符为正或者负号时，则将该符号与之后面尽可能多的连续数字组合起来，作为该整数的正负号；假如第一个非空字符是数字，则直接将其与之后连续的数字字符组合起来，形成整数。

该字符串除了有效的整数部分之后也可能会存在多余的字符，这些字符可以被忽略，它们对于函数不应该造成影响。

注意：假如该字符串中的第一个非空格字符不是一个有效整数字符、字符串为空或字符串仅包含空白字符时，则你的函数不需要进行转换。

在任何情况下，若函数不能进行有效的转换时，请返回 0。

说明：

假设我们的环境只能存储 32 位大小的有符号整数，那么其数值范围为 [−231,  231 − 1]。如果数值超过这个范围，qing返回  INT_MAX (231 − 1) 或 INT_MIN (−231) 。

示例 1:

输入: "42"
输出: 42
示例 2:

输入: "   -42"
输出: -42
解释: 第一个非空白字符为 '-', 它是一个负号。
     我们尽可能将负号与后面所有连续出现的数字组合起来，最后得到 -42 。
	 示例 3:

	 输入: "4193 with words"
	 输出: 4193
	 解释: 转换截止于数字 '3' ，因为它的下一个字符不为数字。
	 示例 4:

	 输入: "words and 987"
	 输出: 0
	 解释: 第一个非空字符是 'w', 但它不是数字或正、负号。
	 因此无法执行有效的转换。
	 示例 5:

	 输入: "-91283472332"
	 输出: -2147483648
	 解释: 数字 "-91283472332" 超过 32 位有符号整数范围。
	      因此返回 INT_MIN (−231) 。

		  来源：力扣（LeetCode）
		  链接：https://leetcode-cn.com/problems/string-to-integer-atoi
		  著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
//////////////////////////////////////////////////////////////////////////
/*!
* @brief 各种if.....
*
* @author subai
* @date 2019/8/10
*/
class Solution {
public:
	int myAtoi(const std::string& str)
	{
		if (str.empty())
		{
			return 0;
		}
		//2147483647
		//-2147483648
		static const int int_max_divide_10 = 214748364;
		int num = 0;
		size_t i = 0;
		while (i<str.size())
		{
			if (!IsSpace(str[i]))
			{
				break;
			}
			++i;
		}
		bool is_negtive = IsNegative(str[i]);
		bool is_positive = isPositive(str[i]);
		if (is_negtive || is_positive)
		{
			++i;
		}
		bool is_number = false;
		while (i < str.size())
		{
			if (IsNumber(str[i]))
			{
				if (num > int_max_divide_10)
				{
					return is_negtive ? INT_MIN : INT_MAX;
				}
				if (num == int_max_divide_10)
				{
					if (is_negtive && str[i] >= '8')
					{
						return INT_MIN;
					}
					else if (!is_negtive && str[i] >= '7')
					{
						return INT_MAX;
					}
				}
				num *= 10;
				num += ToInt(str[i]);
			}
			else
			{
				break;
			}
			++i;
		}
		return is_negtive ? -num:num;
	}
private:
	bool IsSpace(char c) const
	{
		return c == ' ';
	}
	bool IsNumber(char c) const
	{
		return c >= '0' && c <= '9';
	}
	bool IsNegative(char c) const
	{
		return c == '-';
	}
	bool isPositive(char c) const
	{
		return c == '+';
	}
	int ToInt(char c)
	{
		switch (c)
		{
		case '0':
			return 0;
		case '1':
			return 1;
		case '2':
			return 2;
		case '3':
			return 3;
		case '4':
			return 4;
		case '5':
			return 5;
		case '6':
			return 6;
		case '7':
			return 7;
		case '8':
			return 8;
		case '9':
			return 9;
		default:
			break;
		}
		//assert(0);
		return -1;
	}
};

int main()
{
	Solution s;
	std::cout <<s.myAtoi("42") <<std::endl;
	std::cout << s.myAtoi("-42") << std::endl;
	std::cout << s.myAtoi("4193 width word") << std::endl;
	std::cout << s.myAtoi("word and 987") << std::endl;
	std::cout << s.myAtoi("2147483646") << std::endl;
	std::cout << s.myAtoi("2147483647") << std::endl;
	std::cout << s.myAtoi("2147483648") << std::endl;
	std::cout << s.myAtoi("-2147483647") << std::endl;
	std::cout << s.myAtoi("-2147483648") << std::endl;
	std::cout << s.myAtoi("-2147483649") << std::endl;
	system("pause");
	return 0;
}