#include <iostream>
#include <cassert>
#include <vector>

//////////////////////////////////////////////////////////////////////////
/*
给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。

如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。

您可以假设除了数字 0 之外，这两个数都不会以 0 开头。

示例：

输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/add-two-numbers
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
//////////////////////////////////////////////////////////////////////////
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
/*!
 * @brief 两数之和。可以方便的计算两个大数的和。循环遍历即可，需要注意是否进位。
 *
 * @author subai
 * @date 2019/1/6
 */
class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
	{
		bool is_carry = false;
		ListNode* head = NULL;
		ListNode* l = NULL;
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
			if (l != NULL)
			{
				l->next = sum;
			}
			l = sum;
			is_carry = (val1 + val2 + extra_val >= 10);
		}
		return head;
	}
};

ListNode* BuildList(const std::vector<int>& elements)
{
	if (elements.empty())
	{
		return NULL;
	}
	ListNode* head = new ListNode(0);
	ListNode* l = head;
	for (size_t i = 0;i!=elements.size();++i)
	{
		l->val = elements[i];
		if (i != elements.size()-1)
		{
			l->next = new ListNode(0);
			l = l->next;
		}
	}
	return head;
}

void PrintList(ListNode* l)
{
	while (l != NULL)
	{
		std::cout << l->val << "->";
		l = l->next;
	}
	std::cout << std::endl;
}

int main()
{
	Solution s;
	std::vector<int> element1 = { 3,8,6 };
	std::vector<int> element2 = { 4,4,3,4 };
	std::vector<int> element3 = { 3,8};
	ListNode* l1 = BuildList(element1);
	ListNode* l2 = BuildList(element2);
	ListNode* l3 = BuildList(element3);
	
	PrintList(l1);
	PrintList(l2);
	std::cout << "sum is:";
	PrintList(s.addTwoNumbers(l1, l2));
	PrintList(l2);
	PrintList(l3);
	std::cout << "sum is:";
	PrintList(s.addTwoNumbers(l2, l3));
	PrintList(l1);
	PrintList(l3);
	std::cout << "sum is:";
	PrintList(s.addTwoNumbers(l1, l3));
	
	std::cout << std::endl;
	system("pause");
	return 0;
}