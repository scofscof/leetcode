#include <iostream>
#include <string>

class Solution {
public:
	bool IsLeft(char c) const
	{
		return c == '(' || c == '[' || c == '{';
	}
	bool IsRight(char c) const
	{
		return c == ')' || c == ']' || c == '}';
	}
	bool IsMatch(char c1, char c2) const
	{
		return c1 == '('&&c2 == ')'
			|| c1 == '['&&c2 == ']'
			|| c1 == '{'&&c2 == '}';
	}
	bool isValid(std::string s) 
	{
		std::string left_parentheses;//保存左括号的列表
		for (auto c :s)
		{
			if (IsLeft(c))
			{
				left_parentheses += c;
			}
			else if(IsRight(c))
			{
				if (left_parentheses.empty())
				{
					//没有与之对应的左括号
					return false;
				}
				char c2 = left_parentheses[left_parentheses.size() - 1];
				if (!IsMatch(c2,c))
				{
					return false;
				}
				left_parentheses.resize(left_parentheses.size() - 1);
			}
			else//除了左右括号之外的其他字符，直接判定为无效 
			{
				return false;
			}
		}
		return left_parentheses.empty();//最终结果左括号的列表为空，表明正好完全匹配。
	}
};

int main()
{
	Solution s;
	std::string str = "()";
	std::cout << s.isValid(str) << std::endl;
	str = "()[]{}";
	std::cout << s.isValid(str) << std::endl;
	str = "(]";
	std::cout << s.isValid(str) << std::endl;
	str = "([)]";
	std::cout << s.isValid(str) << std::endl;
	str = "{[]}";
	std::cout << s.isValid(str) << std::endl;
	system("pause");
	return 0;
}