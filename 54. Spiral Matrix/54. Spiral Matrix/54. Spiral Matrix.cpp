// 54. Spiral Matrix.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;


//加载顺序如下 1 -> 4  顺时针
/*
	  1 1 1 
	4	    2
	4		2
	4		2
	  3 3 3 
*/
vector<int> spiralOrder(vector<vector<int>>& matrix) {
	vector<int> result;
	if (matrix.empty() == true)
		return result;
	int row = matrix.size() - 1; //行
	int column = matrix[0].size() - 1;//列
	int m = 0, n = 0; //m 行    n 列
	int i;
	while (m < row && n < column) {
		for (i = n; i < column; i++)          //1
			result.push_back(matrix[m][i]);
		for (i = m ; i < row; i++)
			result.push_back(matrix[i][column]); //2
		for (i = column; i > n; i--)
			result.push_back(matrix[row][i]); //3
		for (i = row; i > m; i--) 
			result.push_back(matrix[i][n]); //4
		m++; n++;
		row--; column--;
	}
	if (m < row && n == column)
		while (m <= row)
			result.push_back(matrix[m++][n]);
	else if(n <= column && m == row)
		while (n <= column)
			result.push_back(matrix[m][n++]);
	return result;
}


int main()
{
	vector<vector<int>> v2({
		{2,5,8},
		{4,0,-1}
		//{1, 2, 3, 4 },
		//{5, 6, 7, 8 },
		//{9, 10,11,12},
		//{13,14,15,16}
	});
	vector<int> v = spiralOrder(v2);
	for (int c : v)
		cout << c << " ";
	cout << endl;
	cout << v.size() << endl;
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
