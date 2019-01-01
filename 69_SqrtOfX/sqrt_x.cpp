#include <iostream>

class Solution {
public:
	int sqrtBinary(int x, int left, int right)
	{
		int mid = (left + right) / 2;
		if (mid == 0)
		{
			return sqrtBinary(x, 0, right);
		}
		else if (mid > x/mid)
		{
			return sqrtBinary(x, left, mid);
		}
		else if(mid*mid == x)
		{
			return mid;
		}
		else
		{
			if (mid+1 > x/(mid+1))
			{
				return mid;
			}
			else if((mid + 1)*(mid + 1) == x)
			{
				return mid + 1;
			}
			else
			{
				return sqrtBinary(x, mid + 1, right);
			}
		}
	}
	int mySqrt(int x) 
	{
		if (x < 0)
		{
			return -1;
		}
		if (x <= 1)
		{
			return x;
		}
		return sqrtBinary(x, 0, x);
	}
};

int main()
{
	Solution s;
	const int i = 2147395599;
	//for (int i = 0;i!= 300;++i)
	{
		int res = s.mySqrt(i);
		std::cout << i << "的平方根是:" << res << std::endl;
	}

	system("pause");
	return 0;
}


