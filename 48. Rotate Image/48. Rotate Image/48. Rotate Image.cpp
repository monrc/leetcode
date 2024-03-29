// 48. Rotate Image.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>	
using namespace std;
/*
	移动顺序为下
	  4 4 4
	1       3
	1	    3
	1	    3
	  2 2 2
 */
void rotate(vector<vector<int>>& matrix) {
	int n = matrix.size() - 1;
	int num = matrix.size() / 2;
	vector<int> temp(matrix.size(), 0);
	for (int i = 0; i < num; i++, n--) {//先旋转外圈，再内圈
		int j, k;
		temp = matrix[i];
		for (j = i, k = n; j < n; j++, k--) //移动 1
			matrix[i][k] = matrix[j][i];
		for (k = i; k < n; k++)             //移动 2
			matrix[k][i] = matrix[n][k];
		for (j = i, k = n; j < n; j++, k--) //移动 3
			matrix[n][j] = matrix[k][n];
		for (j = i; j <= n; j++)
			matrix[j][n] = temp[j];
	}
}
int main()
{
	vector<vector<int>> v2({
		{1, 2, 3},
		{4, 5, 6},
		{7, 8, 9}
		});
	rotate(v2);
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
