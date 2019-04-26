#define _CRT_SECURE_NO_WARNINGS 1
#include <math.h>
struct ListNode
{
	int val;
	struct ListNode* next;

};
//编写代码，以给定值x为基准将链表分割成两部分，所有小于x的结点排在大于或等于x的结点之前
 ListNode* partition( ListNode* pHead, int x) {
	// write code here
	if (!pHead)
	{
		return pHead;
	}
    ListNode* p = new ListNode();
	ListNode* q = new ListNode();
	ListNode* ph = p;
	ListNode* qh = q;
	while (pHead)
	{
		if (pHead->val < x)
		{
			p->next = pHead;
			p = p->next;
		}
		else
		{
			q->next = pHead;
			q = q->next;
		}
		pHead = pHead->next;
	}
	q->next = nullptr;
	qh = qh->next;
	p->next = qh;
	return ph->next;
}

// 在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，返回链表头指针。

 ListNode* deleteDuplication(ListNode* pHead)
 {
	 ListNode* newhead = new ListNode();
	 newhead->next = pHead;
	 ListNode* prev = newhead;
	 ListNode* cur = pHead;
	 ListNode* next;
	 while (cur&&cur->next)
	 {
		 next = cur->next;
		 if (cur->val == next->val)
		 {
			 while (next != nullptr && cur->val == next->val)
			 {
				 next = next->next;
			 }
			 prev->next = next;
			 cur = next;

		 }
		 else
		 {
			 prev = cur;
			 cur = cur->next;
		 }
	 }
	 return newhead->next;
 }
// 链表的回文结构
 bool chkPalindrome(ListNode* A) {
	 // write code here
	 ListNode* fast = A;
	 ListNode* slow = A;
	 while (fast != nullptr && fast->next != nullptr)
	 {
		 fast = fast->next->next;
		 slow = slow->next;
	 }
	 ListNode* mid = slow;
	 ListNode* midnext = slow->next;
	 slow->next = nullptr;
	 ListNode* prev = nullptr;
	 ListNode* next = nullptr;
	 while (midnext)
	 {
		 next = midnext->next;
		 midnext->next = prev;
		 prev = midnext;
		 midnext = next;
	 }
	 while (A != nullptr && prev != nullptr)
	 {
		 if (A->val != prev->val)
		 {
			 return false;
		 }
		 A = A->next;
		 prev = prev->next;
	 }
	 return true;
 }

// 输入两个链表，找出它们的第一个公共结点
 struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
	 struct ListNode* fast = headA;
	 struct ListNode* slow = headB;
	 struct ListNode* tmp = nullptr;
	 if (headA == nullptr && headB == nullptr)
		 return nullptr;
	 int count1 = 0;
	 int count2 = 0;
	 while (fast)
	 {
		 fast = fast->next;
		 count1++;
	 }
	 while (slow)
	 {
		 slow = slow->next;
		 count2++;
	 }
	 int step = abs(count1 - count2);
	 if (count1 - count2>0)
	 {
		 fast = headA;
		 slow = headB;
	 }
	 else
	 {
		 fast = headB;
		 slow = headA;
	 }
	 while (step--)
	 {
		 fast = fast->next;
	 }
	 while (fast && slow)
	 {
		 if (fast == slow)
		 {
			 tmp = fast;
			 break;
		 }
		 fast = fast->next;
		 slow = slow->next;
	 }
	 return tmp;
 }

//给定一个链表，判断链表中是否有环
bool hasCycle(struct ListNode *head) {
	struct ListNode* fast = head;
	struct ListNode* slow = head;
	while (fast && fast->next && slow)
	{
		fast = fast->next->next;
		slow = slow->next;
		if (fast == slow)
			return true;
	}
	return false;

}

//给定一个链表，返回链表开始入环的第一个节点，如果链表无环，则返回?NULL
struct ListNode *detectCycle(struct ListNode *head) {
	struct ListNode* fast = head;
	struct ListNode* slow = head;
	bool hasCycle = false;
	while (fast && fast->next && slow)
	{
		fast = fast->next->next;
		slow = slow->next;
		if (fast == slow)

		{
			hasCycle = true;
			break;
		}
	}
	if (hasCycle)
	{
		struct ListNode* node = head;
		while (slow != node)
		{
			slow = slow->next;
			node = node->next;
		}
		return node;

	}
	else
		return nullptr;


}