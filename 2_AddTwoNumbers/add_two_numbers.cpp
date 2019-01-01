#include <iostream>


struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
	{
		bool is_carry = false;
		ListNode* head = NULL;
		ListNode* last_node = NULL;
		while ((l1 != NULL || l2 != NULL) || is_carry)
		{
			int val1 = 0;
			if (l1 != NULL)
			{
				val1 = l1->val;
				l1 = l1->next;
			}
			int val2 = 0;
			if (l2 != NULL)
			{
				val2 = l2->val;
				l2 = l2->next;
			}
			int extra_val = is_carry ? 1 : 0;
			int val = val1 + val2 + extra_val;
			if (val >= 10)
			{
				val -= 10;
			}
			ListNode* sum = new ListNode(val);
			if (head == NULL)
			{
				head = sum;
			}
			if (last_node != NULL)
			{
				last_node->next = sum;
			}
			last_node = sum;
			is_carry = (val1 + val2 + extra_val >= 10);
		}
		return head;
	}
};

int main()
{
	Solution s;
	ListNode* l10 = new ListNode(1);
	//ListNode* l11 = new ListNode(4);
	//ListNode* l12 = new ListNode(3);
	//l10->next = l11;
	//l11->next = l12;

	ListNode* l20 = new ListNode(9);
	ListNode* l21 = new ListNode(9);
	//ListNode* l22 = new ListNode(4);
	l20->next = l21;
	//l21->next = l22;

	ListNode* sum = s.addTwoNumbers(l10, l20);
	while (sum != NULL)
	{
		std::cout << sum->val << "->";
		sum = sum->next;
	}
	std::cout << std::endl;
	system("pause");
	return 0;
}