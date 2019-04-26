#define _CRT_SECURE_NO_WARNINGS 1
#include <math.h>
struct ListNode
{
	int val;
	struct ListNode* next;

};
//��д���룬�Ը���ֵxΪ��׼������ָ�������֣�����С��x�Ľ�����ڴ��ڻ����x�Ľ��֮ǰ
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

// ��һ������������У������ظ��Ľ�㣬��ɾ�����������ظ��Ľ�㣬�ظ��Ľ�㲻��������������ͷָ�롣

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
// ����Ļ��Ľṹ
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

// �������������ҳ����ǵĵ�һ���������
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

//����һ�������ж��������Ƿ��л�
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

//����һ��������������ʼ�뻷�ĵ�һ���ڵ㣬��������޻����򷵻�?NULL
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