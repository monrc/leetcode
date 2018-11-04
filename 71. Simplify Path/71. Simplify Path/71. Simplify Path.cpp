// 71. Simplify Path.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

//path = "/home/", = > "/home"
//path = "/a/./b/../../c/", = > "/c"
//path = "/a/../../b/../c//.//", = > "/c"
//path = "/a//b////c/d//././/..", = > "/a/b/c"

string simplifyPath(string path) {
	vector<int> ps(path.size(), 0);
	int ps_ps = 4;
	int path_ps1 = 0;
	int fg1 = 1, fg2 = 0; //       /的个数   .的个数
	for (char c : path) {
		if (c == '/') {
			switch (fg2) {
			case 0:
				if (path[path_ps1] == '/')
					continue;
				path[++path_ps1] = '/';
				ps[++ps_ps] = path_ps1;		//存储/的位置
			//	fg1 = 1;
				break;
			case 2:
				if (fg1 == 1)
					path_ps1 = ps[ps_ps - 1];
				else
					path_ps1 = ps[ps_ps];
				ps_ps--;
				fg1 = 0;
				break;
			default:
				break;
			}
			fg2 = 0;
		}
		else if (c == '.')
			fg2++;
		else
			path[++path_ps1] = c;
	}
	if (path_ps1 == 0 && fg2 != 3)
		return "/";
	path_ps1 = ps[ps_ps] + fg2;
	path.resize(path[path_ps1] == '/' ? path_ps1 : path_ps1 + 1);
	return path;
}


int main()
{
	string s(
		//"/a/../../b/../c//.//"
		//"/home/"
		//"/a/./b/../../c/"
		//"/a//b////c/d//././/.."
		//"/a/./b///../c/../././../d/..//../e/./f/./g/././//.//h///././/..///"
		//"/.././tqCEe/..///L/../../././//../../../JGF/../ZUFaY/.///wMzVK//"
		"/..."

	);
	cout << simplifyPath(s) << endl;
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
