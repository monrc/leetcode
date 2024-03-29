// 65. Valid Number.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;


bool isNumber(string s) {
	//0 +-  1 e   2 . 3 数字
	vector<bool> flag(4, 0);
	int i = -1;
	int temp = 0;
	while (++i < s.size() && s[i] == ' ');
	i--;
	while (++i < s.size()) {
		if (s[i] >= '0' && s[i] <= '9') {
			temp = 1;
			flag[3] = 1;
			continue;
		}

		else if (s[i] == '+' || s[i] == '-') {
			if (flag[0] == 0 && flag[3] == 0 && i+1 < s.size() && ((s[i+1] >= '0' && s[i+1] <= '9') || s[i+1] == '.'))
				flag[0] = 1;
			else
				return false;
		}
		else if (s[i] == 'e') {
			if (flag[1] == 0 && i > 0 && ((s[i - 1] >= '0' && s[i - 1] <= '9') || s[i - 1] == '.')
				&& i + 1 < s.size() && ((s[i + 1] >= '0' && s[i + 1] <= '9') || s[i + 1] == '+' || s[i + 1] == '-')) {
				flag[1] = 1;
				flag[0] = 0;
				flag[3] = 0;
			}
			else
				return false;
		}
		else if (s[i] == '.') {
			if (flag[2] == 0 && flag[1] == 0) {
				if ((i == 0  && (i + 1 == s.size() || s[i+1] == 'e'))
					//||(i > 0 && (/*s[i - 1] == '+' || */s[i - 1] == '-'))
					|| (i + 1 < s.size() && (s[i + 1] == '+' || s[i + 1] == '-')))
					return false;
				flag[2] = 1;
			}	
			else
				return false;
		}
		else if (s[i] == ' ')
			break;
		else
			return false;
	}
	if (temp == 1) {
		while (i < s.size())
			if (s[i++] != ' ')
				return false;
	}
	else
		return false;

	return s.empty() ? false : true;
}

int main()
{
	cout << isNumber(  "-.3e6"   ) << endl;
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
