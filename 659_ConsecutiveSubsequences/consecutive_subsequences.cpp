#include <iostream>
#include <vector>
#include <algorithm>
class Solution {
public:
	bool isPossible(std::vector<int>& nums) 
	{

	}
};

int partition(int arr[], int p, int r)
{
	int i = p - 1;
	int x = arr[r];
	for (int j = p;j<=r;++j)
	{
		if (arr[j] <= x)
		{
			++i;
			std::swap(arr[i], arr[j]);
		}
	}
	return i;
}
void quickSort(int arr[],int p,int r)
{
	if (p<r)
	{
		int q = partition(arr, p, r);
		quickSort(arr, p, q - 1);
		quickSort(arr, q + 1, r);
	}
}

void insertSort(int a[],int n)
{
	for (int i = 1;i<n;++i)
	{
		int key = a[i];
		int j = i - 1;
		while (j >= 0 && a[j] > key)
		{
			a[j + 1] = a[j];
			j = j - 1;
		}
		a[j + 1] = key;
	}
}

int binarySearch(int a[],int p, int r,int k)
{
	if (p > r)
	{
		return -1;
	}
	int m = (p + r) / 2;
	if (a[m] == k)
	{
		return m;
	}
	else if(a[m] > k)
	{
		return binarySearch(a, p, m - 1, k);
	}
	else
	{
		return binarySearch(a, m+1, r, k);
	}
}

int main()
{ 
	int arr[] = { 3,13,23,12,14,25,6,37,13 };
	int count = sizeof(arr) / sizeof(arr[0]);
	quickSort(arr,0, count -1);
	int x = binarySearch(arr, 0, count - 1, 44);
	int y = binarySearch(arr, 0, count - 1, 13);
	int z = binarySearch(arr, 0, count - 1, 3);
	int w = binarySearch(arr, 0, count - 1, 37);
	
	for (int i = 0; i != count; ++i)
	{
		std::cout << arr[i] << " ";
	}
	system("pause");
	return 0;
}