// 81. Search in Rotated Sorted Array II.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
using namespace std;
//2,5,6,0,0,1,2 
//记转折点为  p 
bool search(vector<int>& nums, int target) {
	int k1 = 0, k2 = nums.size() - 1;
	int k;
	if (k2 < 0 || (target < nums[k1] && target > nums[k2]))
		return false;
	//if(nums[k1] >= nums[k2])      //区间数组并不有序
	while (k1 <= k2) {          //查找可能包含目标的有序区间
		k = (k1 + k2) >> 1;
		if (target == nums[k1] || target == nums[k2] || target == nums[k])
			return true;
		if (nums[k1] == nums[k] || nums[k] == nums[k2]) {
			k1++;k2--;
		}
		else if ((nums[k] < target && (target < nums[k2]|| nums[k1] < nums [k]))
				|| (target < nums[k]  && nums[k1] < nums[k] && target < nums[k1]))
			k1 = k + 1;
		else
			k2 = k - 1;
	}
	//while (k1 <= k2) {
	//	k = (k1 + k2) >> 1;
	//	if (nums[k] < target)
	//		k1 = k + 1;
	//	else if (nums[k] > target)
	//		k2 = k - 1;
	//	else
	//		return true;
	//}
	return false;
}

int main()
{
	vector<int> v({ 10,10,10,-10,-10,-10,-10,-9,-9,-9,-9,-9,-9,
	-9,-8,-8,-8,-8,-8,-8,-8,-8,-7,-7,-7,-7,-6,-6,-6,-5,-5,-5,-4,-4,
		-4,-4,-3,-3,-2,-2,-2,-2,-2,-2,-2,-2,-1,-1,-1,-1,-1,0,0,0,0,0,
		0,0,1,1,1,1,2,2,2,2,2,2,2,3,3,3,4,4,4,5,5,5,5,6,6,6,7,7,7,7,7,
		8,8,8,8,9,9,9,9,9,9,9,10,10
});
//	vector<int> v({ 4, 5, 6, 7, 0, 1, 2 });

	cout << search(v, -6) << endl;

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
