// 51. N-Queens.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<vector<string>> solveNQueens(int n) {
	vector<vector<string>> result_map;
	vector<int> stack(n, 0);//位置栈，存储坐标为纵向坐
	int ps = 0;
	vector<int> map1(2 * n, 0); //正斜向查重用
	vector<int> map2(2 * n, 0); //反斜向查重用
	vector<int> map(n, 0);		//列向查重
	while (stack[0] < n) {

		if (map[stack[ps]] == 0) { //列向查重
			int t1 = ps - stack[ps] + n;//斜向查重
			int t2 = stack[ps] + ps;
			if (map1[t1] == 0 && map2[t2] == 0) { //斜向查重通过
				map[stack[ps]] = 1;
				map1[t1] = 1;
				map2[t2] = 1;

				if (++ps == n) {
					result_map.push_back(vector<string>(n, string(n, '*')));//添加一个空棋盘
					int size = result_map.size() - 1;
					for (int i = 0; i < n; i++)
						result_map[size][i][stack[i]] = 'Q';
					map1[t1] = 0;
					map2[t2] = 0;
					map[stack[--ps]] = 0;
				}
				else {
					stack[ps] = 0;
					continue;
				}
			} //end of 斜向查重通过
		} //end of 列向查重
		while (++stack[ps] >= n && ps > 0){
			ps--;
			map[stack[ps]] = 0;
			map1[ps - stack[ps] + n] = 0;
			map2[stack[ps] + ps] = 0;
		}
	}
	return result_map;
}


int main()
{
	vector<vector<string>> v2;
	v2 = solveNQueens(10);
	for (vector<string> v : v2) {
		for (string c : v)
			cout << c << endl;
		cout << "------------------------" << endl;
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
