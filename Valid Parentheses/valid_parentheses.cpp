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
		std::string left_parentheses;//���������ŵ��б�
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
					//û����֮��Ӧ��������
					return false;
				}
				char c2 = left_parentheses[left_parentheses.size() - 1];
				if (!IsMatch(c2,c))
				{
					return false;
				}
				left_parentheses.resize(left_parentheses.size() - 1);
			}
			else//������������֮��������ַ���ֱ���ж�Ϊ��Ч 
			{
				return false;
			}
		}
		return left_parentheses.empty();//���ս�������ŵ��б�Ϊ�գ�����������ȫƥ�䡣
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