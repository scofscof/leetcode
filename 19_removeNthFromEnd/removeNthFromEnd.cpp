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
//�������飬�ȼ�������������������������ɾ����Ӧ�Ľڵ�
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
//�����һ��hash map��
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

///�ο��˹ٷ��Ĵ𰸣�����ָ�롣
class Solution3
{
public:
	ListNode* removeNthFromEnd(ListNode* head, int n)
	{
		ListNode dummy(0);//����ƽ���õĺá�����ɾ����0���ڵ������
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
		//û��delete ��ǰɾ���Ľڵ㣬��Ϊδ���ڶ��Ϸ���ռ�
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
