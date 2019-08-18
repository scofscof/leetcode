#include <iostream>
#include <vector>
#include <unordered_map>
#include <cassert>
/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
//遍历两遍，先计算链表的数量，再正序计数，删除对应的节点
class Solution 
{
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) 
	{
		ListNode* dummy_head = head;
		int count = 0;
		while (head != NULL)
		{
			++count;
			head = head->next;
		}
		if (count == n)
		{
			ListNode* next = dummy_head->next;
			delete dummy_head;
			return next;
		}
		int index = 0;
		head = dummy_head;
		while (index < count-n-1)
		{
			head = head->next;
			++index;
		}
		ListNode* next = NULL;
		if (head->next != NULL)
		{
			next = head->next->next;
		}
		delete head->next;
		head->next = next;
		return dummy_head;
	}
};
//存放在一个hash map中
class Solution2
{
public:
	ListNode* removeNthFromEnd(ListNode* head, int n)
	{
		std::unordered_map<int, ListNode*> node_map;
		ListNode* dummy_head = head;
		int index = 0;
		while (head != NULL)
		{
			node_map[index++] = head;
			head = head->next;
		}
		int count = node_map.size();
		if (count == n)
		{
			ListNode* next = dummy_head->next;
			delete dummy_head;
			return next;
		}
		auto itn = node_map.find(count - n);
		auto it_pren = node_map.find(count - n - 1);
		assert(itn != node_map.end());
		assert(it_pren != node_map.end());
		ListNode* cur_node = itn->second;
		it_pren->second->next = cur_node->next;
		delete cur_node;
		return dummy_head;
	}
};

///参考了官方的答案，快慢指针。
class Solution3
{
public:
	ListNode* removeNthFromEnd(ListNode* head, int n)
	{
		ListNode dummy(0);//这个哑结点用的好。简化了删除第0个节点的情形
		dummy.next = head;
		ListNode* fast = &dummy;
		ListNode* slow = &dummy;
		int index = 0;
		while (index <= n)
		{
			fast = fast->next;
			++index;
		}
		while (fast != NULL)
		{
			fast = fast->next;
			slow = slow->next;
		}
		//没有delete 当前删除的节点，因为未必在堆上分配空间
		slow->next = slow->next->next;
		return dummy.next;
	}
};

ListNode* GenList(const std::vector<int>& val_list)
{
	ListNode dummy(0);
	ListNode* head = &dummy;
	for (size_t i = 0;i!=val_list.size();++i)
	{
		ListNode* n = new ListNode(val_list[i]);
		head->next = n;
		head = head->next;
	}
	return dummy.next;
}

void PrintList(ListNode* n)
{
	ListNode* head = n;
	while (head != NULL)
	{
		std::cout << head->val <<"->";
		head = head->next;
	}
	std::cout << std::endl;
}

int main()
{
	Solution2 s;
	std::vector<int> val_list = { 1};
	ListNode* n = GenList(val_list);
	std::cout << "before delete " << std::endl;
	PrintList(n);
	n = s.removeNthFromEnd(n, 1);
	std::cout << "after delete " << std::endl;
	PrintList(n);
	system("pause");
	return 0;
}
