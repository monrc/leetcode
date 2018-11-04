// 79. Word Search.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <array>
#include <stack>
using namespace std;    
                      // 0,1,2,3,4
const int next_dir_table[5] = {3,0,9,4,1,};
//检测位置是否在栈中
bool check(vector<array<int, 2>> &vec, int top, int &x, int &y) {
	while (top >= 0) {
		if (vec[top][0] == x && vec[top][1] == y)
			return false;
		top--;
	}
	return true;
}
//检测位置是否在地图中
bool check_range(int &mx, int &my, int &x, int &y,int dir) {
	switch (dir) {
		case 0: x--; break;
		case 3: y++; break;
		case 4: x++; break;
		case 1: y--; break;
	}
	if(x < 0 || y < 0 || x > mx || y > my)
		return false;
	return true;
}
//查找方向：1-4      x 行   y 列
//       0          (x2 - x1)*2 + y2 - y1 + 2
//    1  x  3
//       4
bool exist(vector<vector<char>>& board, string word) {
	vector<array<int, 2>> avec(word.size(), {0,0}); //存储路径 第一个行，第二个列
	int topavec = -1, topword = 1;
	int mrow = board.size() - 1;
	int mcolumn = board[0].size() - 1;
	int row = 0, column = 0, x, y, xt, yt;
	int rute_dir = 0;
	while (1) {
		//找到board中word的第一个元素的位置
		while (board[row][column] != word[0]) {
			if (++column > mcolumn) { 
				row++;
				if (row > mrow)
					return false;
				column = 0;
			}
		}
		avec[++topavec] = { row,column }; //入栈
		x = row; xt = row;
		y = column; yt = column;
		while (topword < word.size() && topavec >= 0) {

			if (check_range(mrow, mcolumn, xt, yt, rute_dir)//值是否越界
				&& board[xt][yt] == word[topword]   //字符是否对应    
				&& check(avec, topavec, xt, yt)) {  //是否已经访问过了
				avec[++topavec] = { xt,yt };		//入栈
				x = xt;
				y = yt;
				topword++;
				rute_dir = 0; //成功之后仍然先从上面的位置开始加载
			}
			else {       //检测不通过，加载下一个
				rute_dir = next_dir_table[rute_dir];//加载下一个方向
				while (rute_dir == 0) { //当前路径已死
					xt = avec[topavec][0];
					yt = avec[topavec][1];
					if (--topavec < 0)  //此次检测失败
						break;
					x = avec[topavec][0];
					y = avec[topavec][1];
					
					rute_dir = (xt - x) * 2 + yt - y + 2;//获取之前的路径
					rute_dir = next_dir_table[rute_dir];//再次分配路径
					topword--;       //更新单词的位置
				}
				xt = x;
				yt = y;
			}
		}
		if (topword == word.size())
			return true;

		if (++column > mcolumn) {
			row++;
			if (row > mrow)
				return false;
			column = 0;
		}
		topword = 1;
	}
}


int main()
{
	vector<vector<char>> cvec({
		{'A','B','C','E' },
		{'S', 'F', 'C', 'S'},
		{'A','D','E','E'}
		});
	string s("ABCB");
	cout << exist(cvec, s) << endl;
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
