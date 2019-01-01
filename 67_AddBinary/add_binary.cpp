#include <iostream>
#include <string>

class Solution {
public:
	std::string addBinary(const std::string& a, const std::string& b) {
		std::string str;
		int carry = 0;
		int index_a = (int)a.size() - 1;
		int index_b = (int)b.size() - 1;
		while (1)
		{
			int sum = carry;

			if (index_a >= 0)
			{
				sum += (a[index_a] == '1' ? 1 : 0);
				--index_a;
			}
			if (index_b >= 0)
			{
				sum += (b[index_b] == '1' ? 1 : 0);
				--index_b;
			}
			if (sum > 1)
			{
				carry = 1;
				sum -= 2;
			}
			else
			{
				carry = 0;
			}
			char c = sum != 0 ? '1' : '0';
			str = c + str;
			if (index_a < 0 && index_b < 0)
			{
				if (carry == 1)
				{
					str = '1' + str;
				}
				break;
			}
		}
		return str;

	}
};

int main()
{
	std::string a("1");
	std::string b("11");
	Solution s;
	std::cout << s.addBinary(a,b) << std::endl;
	system("pause");
	return 0;
}