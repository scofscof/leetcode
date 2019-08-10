#include <string>
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <array>
//////////////////////////////////////////////////////////////////////////
/*
给定一个字符串s，找到s中最长的回文子串。你可以假设s的最大长度为1000。

示例1：

输入:"babad"
输出:"bab"
注意:"aba"也是一个有效答案。
示例2：

输入:"cbbd"
输出:"bb"

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-palindromic-substring
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
//////////////////////////////////////////////////////////////////////////
/*!
 * @brief 暴力法。 leetcode会超时
 *
 * @author subai
 * @date 2019/8/10
 */
class Solution {
public:
	std::string longestPalindrome(const std::string& s) 
	{
		std::string ans;
		if (s.empty())
		{
			return ans;
		}
		std::string str;
		for (size_t i = 0;i!=s.size();++i)
		{
			for (size_t j = i;j!=s.size();++j)
			{
				str.assign(s.begin() + i, s.begin() + j+1);
				if (IsPalindrome(str) && str.size()  > ans.size())
				{
					ans = str;
				}
			}
		}
		return ans;
	}
private:
	bool IsPalindrome(const std::string& str) const
	{
		if (str.empty())
		{
			return false;
		}
		size_t count = str.size();
		for (size_t i = 0;i<=count/2;++i)
		{
			if (str[i] != str[str.size()-1-i])
			{
				return false;
			}
		}
		return true;
	}
};

int main()
{
	Solution s;
	std::string str = s.longestPalindrome("a");
	std::string str2 = s.longestPalindrome("abba");
	std::string str3 = s.longestPalindrome("caba");
	system("pause");
	return 0;
}