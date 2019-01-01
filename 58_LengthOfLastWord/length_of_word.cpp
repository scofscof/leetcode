#include <string>
#include <iostream>

class Solution {
public:
	int lengthOfLastWord(const std::string& s) {
		int len = 0;
		if (!s.empty())
		{
			for (int i = (int)s.size() - 1; i >= 0; --i)
			{
				if (s[i] == ' ' && len != 0)
				{
					break;
				}
				if (isalpha(s[i]))
				{
					++len;
				}
			}
		}

		return len;
	}
};

int main()
{
	std::string str("Hello World");
	Solution s;
	std::cout << s.lengthOfLastWord(str) << std::endl;
	system("pause");
	return 0;
}