// 86. Partition List.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。

#include "pch.h"
#include <iostream>
#include <vector>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* partition(ListNode* head, int x) {
	ListNode  list(0);
	ListNode *p1,*p2,*p;
	list.next = head;
	head = &list;
	while (head->next != NULL && head->next->val < x)
		head = head->next;
	p1 = head; // p1->val  小于 x
	head = head->next;
	if (head == NULL)  //此时链表已经遍历完毕？
		return list.next;
	p2 = head; // p2->val  大于等于x
	p = head->next;
	while (p != NULL) {
		if (p->val < x) {
			p1->next = p;
			p1 = p1->next;
		}
		else {
			p2->next = p;
			p2 = p2->next;
		}
		p = p->next;
	}
	p2->next = NULL;
	p1->next = head;
	return list.next;
}

int main()
{
	vector<int> v({ 1,4,3,2,5,2 });
	ListNode list(0);
	ListNode *p = &list;
	//for (int c : v) {
	//	p->next = new ListNode(c);
	//	p = p->next;
	//}

	list.next = partition(list.next,5);
	p = list.next;
	while (p != NULL) {
		cout << p->val << " ";
		p = p->next;
	}
	std::cout << "Hello World!\n";
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
