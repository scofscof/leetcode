#include <iostream>
#include <vector>
#include <algorithm>
//Definition for singly - linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head)
	{
		if (head == nullptr)
		{
			return nullptr;
		}
		ListNode* l = new ListNode(head->val);
		ListNode* res = l;
		while (head->next != nullptr)
		{
			head = head->next;
			if (head->val != res->val)
			{
				res->next = new ListNode(head->val);
				res = res->next;
			}
		}
		return l;
	}
};

class Solution2 {
public:
	void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n)
	{
		nums1.insert(nums1.end(), nums2.begin(), nums2.end());
		std::sort(nums1.begin(), nums1.end());
	}
};

int main()
{
	Solution s;

	ListNode l1(1);
	ListNode l2(1);
	ListNode l3(2);
	ListNode l4(3);
	ListNode l5(3);
	ListNode l6(4);
	l1.next = &l2;
	l2.next = &l3;
	l3.next = &l4;
	l4.next = &l5;
	l5.next = &l6;

	ListNode* l = s.deleteDuplicates(&l1);


	system("pause");
	return 0;
}