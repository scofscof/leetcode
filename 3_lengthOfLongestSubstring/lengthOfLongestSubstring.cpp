#include <string>
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <array>
//////////////////////////////////////////////////////////////////////////
/*
给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。

示例 1:

输入: "abcabcbb"
输出: 3
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
示例 2:

输入: "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
示例 3:

输入: "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。

	
*/
//////////////////////////////////////////////////////////////////////////
/*!
 * @brief 自己的解法。也想到了滑动窗口和has map，无奈没用对。n方的复杂度。
 *
 * @author subai
 * @date 2019/8/10
 */
class Solution 
{
public:
	int lengthOfLongestSubstring(const std::string& s) 
	{
		if (s.empty())
		{
			return 0;
		}
		int max_count = 0;
		int current_count = 0;
		std::unordered_map<char,size_t> char_list;
		for (size_t i = 0;i!=s.size();++i)
		{
			auto it = char_list.find(s[i]);
			if ( it != char_list.end())
			{
				//这里其实不必退回去，因为当前的it->second到i之间已经明确了没有重复元素，如果有，那么if语句肯定在之前就进了
				i = it->second;
				char_list.clear();
				if (max_count < current_count)
				{
					max_count = current_count;
				}
				current_count = 0;
			}
			current_count++;
			char_list.insert(std::make_pair(s[i],i+1));
		}
		if (max_count < current_count)
		{
			max_count = current_count;
		}
		return max_count;
	}
};

/*!
 * @brief 滑动窗口 
 滑动问题包含一个滑动窗口，它是一个运行在一个大数组上的子列表，该数组是一个底层元素集合。
 假设有数组 [a b c d e f g h ]，一个大小为 3 的 滑动窗口 在其上滑动，则有：
 [a b c]
	[b c d]
		[c d e]
			[d e f]
				[e f g]
					[f g h]
 一般情况下就是使用这个窗口在数组的 合法区间 内进行滑动，同时 动态地 记录一些有用的数据，很多情况下，能够极大地提高算法地效率
 *
 * @author subai
 * @date 2019/8/10
 */
class Solution2
{
public:
	int lengthOfLongestSubstring(const std::string& s)
	{
		if (s.empty())
		{
			return 0;
		}
		int max_count = 0;
		std::unordered_map<char, size_t> char_list;
		for (size_t j = 0, i = 0; j != s.size(); ++j)
		{
			auto it = char_list.find(s[j]);
			if (it != char_list.end())
			{
				//这里取max是为了防止往回找，
				//比如fsdsfa,当执行到第二个s时,i=2；但是如果不比较大小，执行到第二个f时，i=1；显然是错误的
				i = std::max(i, it->second);
			}
			max_count = std::max(max_count, int(j - i + 1));
			char_list[s[j]] = j + 1;
		}
		return max_count;
	}
};
/*!
 * @brief 同样使用滑动窗口。只考虑ascii码和扩展的ascii码，因此使用长度为256的数组替代hash map
 *
 * @author subai
 * @date 2019/8/10
 */
class Solution3
{
public:
	int lengthOfLongestSubstring(const std::string& s)
	{
		if (s.empty())
		{
			return 0;
		}
		std::array<int, 256> dict;
		dict.fill(-1);
		int max_count = 0;
		int l = 0;
		for (size_t r = 0; r != s.size(); ++r)
		{
			if (dict[s[r]] > l)
			{
				l = dict[s[r]];
			}
			dict[s[r]] = static_cast<int>(r+1);
			max_count = std::max(int(r+1 - l),max_count);
		}
	
		return max_count;
	}
};

int main()
{
	Solution3 s;
	std::string str1 = "abcabcbb";
	std::cout << s.lengthOfLongestSubstring(str1) << std::endl;
	std::string str2 = "bbbbb";
	std::cout << s.lengthOfLongestSubstring(str2) << std::endl;
	std::string str3 = "dsafsadvdasfvas";
	std::cout << s.lengthOfLongestSubstring(str3) << std::endl;
	std::string str4 = "dvdf";
	std::cout << s.lengthOfLongestSubstring(str4) << std::endl;
	system("pause");
	return 0;
}