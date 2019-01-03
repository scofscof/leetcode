#pragma once
#include <iostream>
#include <vector>
#include <cassert>
#include <set>
#include <algorithm>
#include <string>

class Solution2 
{
public:
	int numJewelsInStones(std::string J, std::string S) 
	{
		int count = 0;
		for (auto j : J)
		{
			for (auto s : S)
			{
				if (j == s)
				{
					count++;
				}
			}
		}
		return count;
	}
};

class Solution
{
public:
	int numJewelsInStones(std::string J, std::string S)
	{
		char index['z' + 1] = { 0 };
		for (auto j : J)
		{
			index[j] = 1;
		}
		int count = 0;
		for (auto s : S)
		{
			count += index[s];
		}
		return count;
	}
};


int main()
{
	Solution s;
	std::string J = "aA", S = "aAAbbbb";
	int res = s.numJewelsInStones(J,S);

	system("pause");
	return 0;
}



