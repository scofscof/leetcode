#include <iostream>
#include <vector>
#include <algorithm>

//////////////////////////////////////////////////////////////////////////
/*给定 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。
在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, ai) 和(i, 0)。
找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。

说明：你不能倾斜容器，且 n 的值至少为 2。

来源：力扣（LeetCode）
链接：https ://leetcode-cn.com/problems/container-with-most-water
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
//////////////////////////////////////////////////////////////////////////
/*!
 * @brief 从两边开始移动线,最短的线决定盛水的量，在移动时，只需移动最短的线即可得到最优解，原因如下：
 假如两边的线的位置分别为begin和end，对应的值分别为begin_val和end_val,不妨设begin_val<end_val（反之同理），
 此时的盛水量为(end-begin)*begin_val.这是只需向右移动begin即可，因为，如果向左移动end，此时的盛水量一定比(end-begin)*begin_val小。
 不妨假设将end左移到mid位置(mid<end ,mid>begin),此时有两种情况，
 1、mid处的值mid_val小于begin_val,则盛水量为(mid-begin)*mid_val,显然小于(end-begin)*begin_val。(mid比end小，mid_val比end_val小)
 2、mid处的值mid_val大于begin_val,则盛水量为(mid-begin)*begin_val,显然小于(end-begin)*begin_val。(mid比end小)
 *
 * @author subai
 * @date 2019/8/17
 */
class Solution
{
public:
	int maxArea(const std::vector<int>& height)
	{
		int max_area = 0;
		int begin = 0;
		int end = height.size() - 1;
		while (begin < end)
		{
			int begin_val = height[begin];
			int end_val = height[end];
			int area = 0;
			if (begin_val > end_val)
			{
				area = (end - begin)*end_val;
				--end;
			}
			else
			{
				area = (end - begin)*begin_val;
				++begin;
			}
			if (area > max_area)
			{
				max_area = area;
			}
		}
		return max_area;
	}
};

/*!
 * @brief 练习一下递归
 *
 * @author subai
 * @date 2019/8/17
 */
class Solution2
{
public:
	int maxArea(const std::vector<int>& height) 
	{
		int max_area = 0;
		CalcArea(0, height.size() - 1, height, max_area);
		return max_area;
	}
private:
	void CalcArea(int begin, int end, const std::vector<int>& height,int& max_area)
	{
		if (begin >= height.size() 
			|| begin < 0
			||end >= height.size()
			|| end < 0)
		{
			return;
		}
		if (begin >= end)
		{
			return;
		}
		int begin_val = height[begin];
		int end_val = height[end];
		int area = 0;
		if (begin_val > end_val)
		{
			area = (end - begin)*end_val;
			--end;
		}
		else
		{
			area = (end - begin)*begin_val;
			++begin;
		}
		if (area > max_area)
		{
			max_area = area;
		}
		CalcArea(begin, end, height, max_area);
	}
};

int main()
{
	Solution s;
	std::vector<int> height = { 1,8,6,2,5,4,8,3,7 };
	int res = s.maxArea(height);
	system("pause");
	return 0;
}

