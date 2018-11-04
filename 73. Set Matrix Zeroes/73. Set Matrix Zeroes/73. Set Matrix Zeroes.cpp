// 73. Set Matrix Zeroes.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
using namespace std;
//第一行存储需要归零的列号，[0][0]表示第0列
//第一列存储需要归零的行号，flg0 表示第0行 [1][0] 表示第1行
void setZeroes(vector<vector<int>>& matrix) {
	int flg0 = 1;
	int row = matrix.size(), column = matrix[0].size();
	int i, j;
	//第一行特殊处理
	for (i = 0; i < column; i++) {
		if (matrix[0][i] == 0) {
			flg0 = 0;
			break;
		}
	}
	//扫描判断所有的元素
	for (i = 1; i < row; i++) {
		for (j = 0; j < column; j++) {
			if (matrix[i][j] == 0) {
				matrix[0][j] = 0;
				matrix[i][0] = 0;
			}
		}
	}//先进行行处理，第一行除外
	for (i = 1; i < row; i++) {
		if (matrix[i][0] == 0)
			for (j = 1; j < column; j++)
				matrix[i][j] = 0;
	}//在进行列处理
	for (i = 0; i < column; i++) {
		if (matrix[0][i] == 0)
			for (j = 1; j < row; j++)
				matrix[j][i] = 0;
	}//处理第一行
	if (flg0 == 0)
		for (i = 0; i < column; i++)
			matrix[0][i] = 0;
}



int main()
{
	vector<vector<int>> v2({
		{0,1,2,0 },
		{3, 4, 5, 2},
		{1,3,1,5}
		});
	setZeroes(v2);
	for (vector<int> v1 : v2) {
		for (int i : v1)
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
