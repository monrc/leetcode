// 88. Merge Sorted Array.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
using namespace std;


void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
	int i = m + n - 1;
	m--;
	n--;
	while (n >= 0 && m >= 0) {
		if (nums1[m] <= nums2[n])
			nums1[i--] = nums2[n--];
		else
			nums1[i--] = nums1[m--];
	}
	while (n >= 0)
		nums1[i--] = nums2[n--];
}

int main()
{
	vector<int> v1({ 1,2,3 });
	vector<int> v2({ 2,5,6 });
	v1.resize(v1.size() + v2.size());
	merge(v1, v1.size() - v2.size(), v2, v2.size());
	for (int c : v1)
		cout << c << " ";
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
