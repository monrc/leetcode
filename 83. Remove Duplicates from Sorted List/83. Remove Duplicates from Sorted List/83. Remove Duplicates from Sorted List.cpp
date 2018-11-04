// 83. Remove Duplicates from Sorted List.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

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


ListNode* deleteDuplicates(ListNode* head) {
	if (head == NULL)
		return head;
	ListNode *p1 = head, *p2 = head->next;
	ListNode *p;
	while (p2 != NULL) {
		while (p2->val == p1->val) {
			p = p2;
			p2 = p2->next;
			delete p;
			if (p2 == NULL) {
				p1->next = NULL;
				return head;
			}
		}
		p1->next = p2;
		p1 = p1->next;
		p2 = p2->next;
	}
	return head;
}


int main()
{
	vector<int> v({ 1,1,2,3,3 });
	ListNode list(0), *p = &list;
	for (int c : v) {
		p->next = new ListNode(c);
		p = p->next;
	}
	list.next = deleteDuplicates(list.next);
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
