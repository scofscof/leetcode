#include <iostream>
#include <string>
#include <list>

class Solution 
{
public:
	std::string convertToTitle(int n) 
	{
		std::string res;
		while (n > 0)
		{
			int num = n % 26;
			if (num == 0)
			{
				num = 26;
				n -= 26;
			}
			num += 64;
			res += num;
			n /= 26;
		}
		std::reverse(res.begin(), res.end());
		return res;
	}
};

int main()
{
	Solution s;
	for (int i = 1;i<=100;++i)
	{
		std::string res = s.convertToTitle(i);
		std::cout << i << "->" << res << std::endl;
	}
	system("pause");
	return 0;
}