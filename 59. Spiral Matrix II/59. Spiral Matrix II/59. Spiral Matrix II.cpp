// 59. Spiral Matrix II.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
using namespace std;

int pow2(int n) {
	int num = 1;
	int temp = 2;
	while (n > 0){
		if (n & 1)
			num *= temp;
		n >>= 1;
		temp *= temp;
	}
	return num;
}

vector<vector<int>> generateMatrix(int n) {
	vector <vector<int>> v2(n, vector<int>(n, 0));
	int num = n * n;
	int row_min = 0, row_max = n - 1;
	n = 1;
	while (n < num) {
		int k;
		for (k = row_min; k < row_max; k++)  //最上面一行
			v2[row_min][k] = n++;
		for (k = row_min; k < row_max; k++)
			v2[k][row_max] = n++;
		for (k = row_max; k > row_min; k--)
			v2[row_max][k] = n++;
		for (k = row_max; k > row_min; k--)
			v2[k][row_min] = n++;
		row_min++;
		row_max--;
	}
	if (num & 1)
		v2[row_max][row_max] = n;
	return v2;
}

int main()
{
	vector<vector<int>> v2;
	v2 = generateMatrix(2);
	for (vector<int> v1 : v2) {
		for (int c : v1)
			cout << c << " ";
		cout << endl;
	}
    //std::cout << "Hello World!\n"; 
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
