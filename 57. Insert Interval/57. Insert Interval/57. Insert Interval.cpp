// 57. Insert Interval.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
using namespace std;


//Definition for an interval.
struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

int find(vector<Interval> & data, int target) {
	int i = 0, j = data.size() - 1;
	if (j < 0)
		return 0;
	int k;
	while (i <= j) {
		k = (i + j) >> 1;
		if (data[k].start > target)
			j = k - 1;
		else if (data[k].start < target)
			i = k + 1;
		else 	
			return k;
	}
	return data[k].start < target ? k + 1 : k;
}
int max(int &a, int &b) {
	return a >= b ? a : b;
}

vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
	vector<Interval> v;
	int ps = find(intervals, newInterval.start);
	int i, j;
	for (i = 0; i < ps; i++)
		v.push_back(intervals[i]);

	if (i == 0)
		v.push_back(newInterval);
	else {
		i--;
		if (v[i].end >= newInterval.start)
			v[i].end = max(v[i].end, newInterval.end);
		else{
			v.push_back(newInterval);
			i++;
		}
	}
	while (ps < intervals.size()) {
		if (v[i].end >= intervals[ps].start)
			v[i].end = max(v[i].end, intervals[ps].end);
		else
			break;
		ps++;
	}
	while (ps < intervals.size())
		v.push_back(intervals[ps++]);
	return v;
}
int main()
{
	int i = 0;
	vector<Interval> v({
		Interval(1, 5),
		//Interval(3, 5),
		//Interval(6, 7),
		//Interval(8, 10),
		//Interval(12, 16),
		//Interval(),
		});
	v = insert(v, Interval(2,7));
	for (Interval c : v)
		cout << '[' << c.start << ',' << c.end << ']' << "  ";
	cout << endl;
	cout << (i >> 1) << endl;
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
