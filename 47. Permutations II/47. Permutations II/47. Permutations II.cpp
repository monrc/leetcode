// 47. Permutations II.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
using namespace std;

void myswap(int *p1, int *p2) {
	int temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}

void permute(vector<vector<int>> &datas, vector<int> &nums, int n) {
	if (n == nums.size() - 1)
		datas.push_back(nums);
	else {
		for (int i = n; i < nums.size(); i++) {
			if (i != n && nums[i] == nums[n])
				continue;
			//查重
			int k = n;
			for (; k < i; k++)
				if (nums[k] == nums[i])
					break;
			if (k != i)
				continue;

			myswap(&nums[i], &nums[n]);
			permute(datas, nums, n + 1);
			myswap(&nums[i], &nums[n]);
		}
	}
}

vector<vector<int>> permuteUnique(vector<int>& nums) {
	vector<vector<int>> vec2;
	permute(vec2, nums, 0);
	return vec2;
}

int main()
{
	vector<int> v1({ 1,2,3,4 });
	vector<vector<int>> v2;
	v2 = permuteUnique(v1);
	for (vector<int> v : v2) {
		for (int i : v)
			cout << i << " ";
		cout << endl;
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
