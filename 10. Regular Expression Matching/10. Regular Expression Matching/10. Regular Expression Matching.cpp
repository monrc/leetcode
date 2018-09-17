// 10. Regular Expression Matching.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isMatch(string s, string p) 
{
	char *s_point = &s[0];
	char *p_point = &p[0];

	vector<char *> mark;
	for (char c : p)
		if (c == '*')
			mark.push_back(&c - 1);
	int num = s.size() - p.size() + mark.size();   //需要填充的个数
	if (num < 0)
		return false;

	if (mark.empty() == true)             //无*情况下的判断
	{
		while (s_point != NULL)
			if (*p_point++ != *s_point++)
			if(*(p_point -  1) != '.')
				return false;
		return true;
	}                              
	//---------以下情况包含#字符-----------------------------------
	while (p_point < mark[0])             //第一个*之前的判断
		if (*p_point++ != *s_point++)
		if (*(p_point - 1) != '.')
			return false;

	char *temp = *(mark.end() - 1) + 2;  //最后一个*之后的判断
	char *p_point_temp = &p[p.size() - 1];
	char *s_point_temp = &s[s.size() - 1];
	while (p_point_temp >= temp)             
		if (*p_point_temp-- != *s_point_temp--)
			if (*(p_point_temp + 1) != '.')
				return false;


	char *temp1 = s_point;
	char *temp2 = p_point;
	vector<int> vec_num(1,0);//判断中间的可伸缩片段
	vector<char *>vec_s;
	vector<char *>vec_p;
	int flag = 1;
	vec_s.push_back(s_point);
	vec_p.push_back(p_point);
	int temp = num;
	int deep = 0;
	while (vec_s.empty() != true)
	{
		if (*s_point != *p_point)
		{
			if (*p_point == '.')
			{
				while(mark[deep + 1] - p_point > 0)

			}
			else
				continue;
		}
		else
		{
			s_point  = vec_s.pop_back();

			deep--;
		}
	}
	return false;
}

int main()
{
	string s("ba");
	char *p = &s[0];
	cout << (int)p << endl;
	char *p2 = &s[1];
	cout << (int)p;
	if(p2 > p)
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
