#pragma once
#include <iostream>
#include <vector>
#include <cassert>
#include <set>
#include <algorithm>

class Solution2 
{
public:
	int maxProfit(std::vector<int>& prices)
	{
		int max_profit = 0;
		for (size_t i = 0; i != prices.size(); i++)
		{
			//int buy_prices = prices[i];
			for (size_t j = i+1; j < prices.size(); j++)
			{
				//int sell_prices = prices[j];
				int profit = prices[j] - prices[i];
				if (profit > max_profit)
				{
					max_profit = profit;
				}
			}
		}
		return max_profit;
	}
};

class Solution
{
public:
	int maxProfit(std::vector<int>& prices)
	{
		int max_profit = 0;
		for (size_t i = 0; i != prices.size(); i++)
		{
			for (size_t j = i + 1; j < prices.size(); j++)
			{
				int profit = prices[j] - prices[i];
				if (profit > max_profit)
				{
					max_profit = profit;
				}
			}
		}
		return max_profit;
	}
};

int main()
{
	Solution s;
	std::vector<int> nums = { 7,1,5,3,6,4 };
	int res = s.maxProfit(nums);

	system("pause");
	return 0;
}



