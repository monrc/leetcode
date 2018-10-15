// 61. Rotate List.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
using namespace std;

//Definition for singly - linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* rotateRight(ListNode* head, int k) {
	if (head == NULL || head->next == NULL)
		return head;

	ListNode *p = head;
	ListNode *p2 = head;
	int size = 1;
	while (p->next != NULL) {//查看链表的长度
		size++;
		p = p->next;
	}
	k = size - k % size;
	while (k-- > 1)
		p2 = p2->next;

	p->next = head;
	head = p2->next;
	p2->next = NULL;
	return head;
}
int main()
{
	ListNode head(0);
	ListNode *p = &head;
	for (int i = 1; i <= 3; i++) {
		p->next = new ListNode(i);
		p = p->next;
	}

	p = rotateRight(head.next, 4);

	//p = head.next;
	while (p) {
		cout << p->val << " ";
		p = p->next;
	}

	cout << endl;
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
