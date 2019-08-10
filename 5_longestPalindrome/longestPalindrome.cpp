#include <string>
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <array>
//////////////////////////////////////////////////////////////////////////
/*
����һ���ַ���s���ҵ�s����Ļ����Ӵ�������Լ���s����󳤶�Ϊ1000��

ʾ��1��

����:"babad"
���:"bab"
ע��:"aba"Ҳ��һ����Ч�𰸡�
ʾ��2��

����:"cbbd"
���:"bb"

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/longest-palindromic-substring
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/
//////////////////////////////////////////////////////////////////////////
/*!
 * @brief �������� leetcode�ᳬʱ
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