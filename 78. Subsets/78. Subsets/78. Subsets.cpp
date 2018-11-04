// 78. Subsets.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
using namespace std;

//采用移动佛珠的算法，得到数组的下标  77题，佛珠算法
vector<vector<int>> subsets(vector<int>& nums) {
	vector<vector<int>> v2;
	vector<int> ps(nums.size(), 0);
	v2.push_back({});
	if (nums.size() == 0)
		return v2;
	v2.push_back(nums);
	if(nums.size() > 1)
	for (int c : nums)
		v2.push_back({ c });
	//加载2 - n-1的情况
	int i, j, max;
	for (int k = 2; k < nums.size(); k++) {
		max = nums.size() - k;
		i = nums.size() - 1;
		
		for (j = 0; j < k; j++)
			ps[j] = j;
		j--;

		v2.push_back(vector<int>(k, 0));
		int temp = v2.size() - 1, m;
		for (m = 0; m < k; m++)
			v2[temp][m] = nums[ps[m]];

		while (ps[0] < max) {
			if (ps[j] == i) {//移动至尾部？
				while (j > 0 && ps[--j] == --i);//找到可以移动的元素
				ps[j]++;
				while (++j < k)
					ps[j] = 1 + ps[j - 1];
				i = nums.size()-1;
				j--;
			}
			else
				ps[j]++;
			v2.push_back(vector<int>(k,0));
			temp = v2.size() - 1;
			for (m = 0; m < k; m++)
				v2[temp][m] = nums[ps[m]];
		}
	}
	return v2;
}
int main()
{
	vector<vector<int>> v2;
	vector<int> v1({ 1,2,3,4});
	v2 = subsets(v1);
	for (vector<int> v : v2) {
		for (int c : v)
			cout << c << " ";
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
