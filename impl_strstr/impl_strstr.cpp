#include <iostream>
#include <string>

class Solution {
public:
	int strStr(std::string haystack, std::string needle) 
	{
		size_t i = 0;
		size_t j = 0;
		while (1)
		{
			if (j == needle.size())
			{
				return i - j;
			}
			if (i == haystack.size())
			{
				break;
			}
			if (haystack[i] == needle[j])
			{
				i++;
				j++;
			}
			else
			{
				i = i - j + 1;
				j = 0;
			}
		}
		return -1;
	}
};

int main()
{
	Solution s;
	std::string a = "aaaaab";
	std::string b = "ab";
	std::cout << s.strStr(a, b) << std::endl;
	const char* sss = strstr(a.c_str(),b.c_str());
	int k = a.c_str() - sss;
	system("pause");
	return 1;
}