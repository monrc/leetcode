// 15. 3Sum.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
using namespace std;

void quick_sort(vector<int> &nums, int start ,int end)
{
	if (start >= end)
		return;
	int high = end, low = start;
	int num = nums[start];
	while (high > low) 
	{
		while (high > low && nums[high] >= num) high--;
		nums[low] = nums[high];
		while (high > low && nums[low] <= num) low++;
		nums[high] = nums[low];
	}
	nums[low] = num;
	
	quick_sort(nums, start, low - 1);
	quick_sort(nums, low + 1, end);
}

vector<vector<int>> threeSum(vector<int>& nums) 
{
	int size = nums.size();
	quick_sort(nums, 0 ,size - 1);
	vector<vector<int>> result;
	if (size < 3)
		return result;
	int i = 0, i_num = nums[i] - 1;
	int j = i + 1, j_num = nums[j] - 1;
	int i_max = size - 2;
	int j_max = size - 1;
	for (; i < i_max; i++) 
	{
		if (nums[i] == i_num) //滤除重复的数字
			continue;
		i_num = nums[i];

		for(j = i + 1; j < j_max; j++)
		{
			if (nums[j] == j_num) //滤除重复的数字
				continue;
			j_num = nums[j];

			int sum = -nums[i] - nums[j];
			int k1 = j + 1;
			int k2 = size - 1;
			int k;
			while (sum <= nums[k2] && sum >= nums[k1])     //二分法遍历
			{
	
				k = (k1 + k2) / 2;

				if (sum > nums[k])
				{
					if (k1 != k)
						k1 = k;
					else
						k1++;
				}
				else if (sum < nums[k])
				{
					if (k2 != k)
						k2 = k;
					else
						k2--;
				}
				else
				{
					result.push_back({ nums[i],nums[j],nums[k] });
					break;
				}	
			}
		}
	}
	return result;
}


int main()
{
	vector<int> nums = { -1, 0, 1, 2, -1, -4 };
	vector<vector<int>> temp;
	quick_sort(nums, 0, nums.size() - 1);

	temp = threeSum(nums);
	for (int i = 0; i < temp.size(); i++)
	{
		for (int j = 0; j < 3; j++)
			cout << temp[i][j] << "  ";
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
