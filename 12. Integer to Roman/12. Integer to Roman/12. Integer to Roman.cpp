// 12. Integer to Roman.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
using namespace std;
const int num_tab[13] = { 1000,900,500,400,100,90,50,40,10,9,5,4,1 };
const string str[13] = { "M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I" };
string intToRoman(int num)
{
	int i, j, k;
	string s;
	for (i = 0; i < 13; i++)
	{
		k = num / num_tab[i];
		for (j = 0; j < k; j++)
			s += str[i];
		num = num % num_tab[i];
	}
	return s;
}

int main()
{
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
