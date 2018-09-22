// 16. 3Sum Closest.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>	
using namespace std;

void quick_sort(vector<int> &nums, int head, int end)
{
	if (head >= end)
		return;
	int data = nums[head];
	int l = head;
	int h = end;
	while (h > l)
	{
		while (h > l && nums[h] >= data) h--;
		nums[l] = nums[h];
		while (h > l && nums[l] <= data) l++;
		nums[h] = nums[l];
	}
	nums[l] = data;
	
	quick_sort(nums, head, l - 1);
	quick_sort(nums, l + 1, end);
}


int threeSumClosest(vector<int>& nums, int target) 
{
	int size = nums.size();
	int sum = nums[0] + nums[1] + nums[2];
	int sum_abs = abs(sum - target) + 1;

	quick_sort(nums, 0, size - 1);
	for (int i = 0; i < size - 2; i++)
	{
		if (nums[i] == nums[i+1] && nums[i] == nums[i+2])
		{
			if (abs(3 * nums[i] - target) < sum_abs)
			{
				sum = 3 * nums[i];
				sum_abs = abs(sum - target);
			}
			i++;
			continue;
		}
		for (int j = i + 1; j < size - 1; j++)
		{
			int k1 = j + 1;
			int k2 = size - 1;
			int two_num = nums[i] + nums[j];
			if (two_num + nums[k1] >= target + sum_abs
				|| two_num + nums[k2] <= target - sum_abs)
				continue;
			while (k1 + 1 < k2)
			{
				int k = (k1 + k2) / 2; 
				if (two_num + nums[k] < target)
					k1 = k;
				else if (two_num + nums[k] > target)
					k2 = k;
				else
					return target;
			}
			k1 = two_num + nums[k1];
			k2 = two_num + nums[k2];
			two_num = abs(k1 - target) < abs(k2 - target) ? k1 : k2;
			if (abs(two_num - target) < sum_abs)
			{
				sum_abs = abs(two_num - target);
				sum = two_num;
			}
		}
	}
	return sum;
}
int main()
{
	vector<int> vec = { -4, -7, -2, 2, 5, -2, 1, 9, 3, 9, 4, 9, -9, -3, 7, 4, 1, 0, 8, 5, -7, -7 };
	quick_sort(vec, 0, vec.size() - 1);
	for (int c : vec)
		cout << c << " ";
	cout << endl;


	cout << threeSumClosest(vec, 29);
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
