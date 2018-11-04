// 77. Combinations.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
using namespace std;


//思路：1。把1-n个数字想象成一串佛珠，每次只移动最后一个可以移动的元素。
//		2。当尾部佛珠完成移动时,将尾部之前的佛珠向后移动一位，后面的佛珠前移复位
//		重复1，2。当第一个元素移动至n-k位置时，运算完成

vector<vector<int>> combine(int n, int k) {
	vector<int> v1(k, 0);
	vector<vector<int>> v2;
	if (k == 0)
		return v2;

	int i;
	int j = k - 1, max = n - k + 1;

	for (i = 0; i < k; i++) //存储成员
		v1[i] = i + 1;
	v2.push_back(v1);

	i = n;
	while (v1[0] < max) {
		if (v1[j] == i) {//移动至尾部？
			while (j > 0 && v1[--j] == --i);//找到可以移动的元素
			v1[j]++;
			while (++j < k)
				v1[j] = 1 + v1[j - 1];
			i = n;
			j--;
		}
		else
			v1[j]++;
		v2.push_back(v1);
	}
	return v2;
}

int main()
{
	vector<vector<int>> v2;
	v2 = combine(5, 3);
	for (vector<int> v1 : v2) {
		for (int c : v1)
			cout << c << " ";
		cout << endl;
	}
    std::cout << "Hello World!\n"; 
}


//Output:
//[[1, 2, 3], 
//[1, 2, 4], 
//[1, 2, 5], 
//1,3,4
//
// 
//[1, 3, 5],
//[1, 4, 5], 
//[2, 3, 4], 
//[2, 3, 5],
//[2, 4, 5],
//[3, 4, 5]]
//Expect
//[[1, 2, 3], 
//[1, 2, 4], 
//[1, 2, 5], 
//[1, 3, 4], 
//[1, 3, 5], 
//[1, 4, 5],
//[2, 3, 4], 
//[2, 3, 5],
//[2, 4, 5], 
//[3, 4, 5]]

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
