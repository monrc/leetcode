// 60. Permutation Sequence.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void delet_element(vector<char> &v, int ps, int end) {
	while (ps++ < end)
		v[ps - 1] = v[ps];
}

string getPermutation(int n, int k) {
	vector<int> cmp(n,0);
	vector<char> nums(n, '1');
	int i,temp = 1,temp2;
	string s;
	k--;
	for (i = 1; i < n; i++) {//对应 cmp[i]  的值  i!
		nums[i] = i + '1';
		temp *= i;
		cmp[i] = temp;
	}
	while (i-- > 1) {
		temp = k / cmp[i];
		while (temp < nums.size() && nums[temp] == ' ')
			temp++;
		s.push_back(nums[temp]);
		delet_element(nums,temp, i);
		k %= cmp[i];
	}
	s.push_back(nums[0]);
	return s;
}

int main()
{
	cout << getPermutation(3, 2) << endl;
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
