#include <iostream>
#include <list>
#include <cassert>


struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
	{
		ListNode res(0);
		ListNode* l = &res;
		while (l1 != NULL && l2 != NULL)
		{
			if (l1->val <= l2->val)
			{
				l->next = l1;
				l1 = l1->next;
			}
			else
			{
				l->next = l2;
				l2 = l2->next;
			}
			l = l->next;
		}
		l->next = l1 != NULL ? l1 : l2;
		return res.next;
	}
};


int main()
{
	Solution s;
	ListNode* l11 = new ListNode(1);
	ListNode* l12 = new ListNode(2);
	ListNode* l13 = new ListNode(4);
	l11->next = l12;
	l12->next = l13;

	ListNode* l21 = new ListNode(3);
	ListNode* l22 = new ListNode(4);
	ListNode* l23 = new ListNode(5);
	l21->next = l22;
	l22->next = l23;

	ListNode* merged_res = s.mergeTwoLists(0, 0);

	while (merged_res != NULL)
	{
		std::cout << merged_res->val << "->";
		merged_res = merged_res->next;
	}
	std::cout << std::endl;

	system("pause");
	return 0;
}