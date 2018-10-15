// 56. Merge Intervals.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
using namespace std;

// Definition for an interval.
struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

void quick_sort(vector<int> &hash, vector<Interval> &data, int l, int h) {
	if (h <= l)
		return;
	int i = l;
	int j = h;
	int temp = hash[l];
	while (i < j) {
		while (i < j && data[hash[j]].start >= data[temp].start)  j--;
		hash[i] = hash[j];
		while (i < j && data[hash[i]].start <= data[temp].start)  i++;
		hash[j] = hash[i];
	}
	hash[i] = temp;
	quick_sort(hash, data, l, i - 1);
	quick_sort(hash, data, i + 1, h);
}


void quick_sort2(vector<Interval> &data, int l, int h) {
	if (l >= h)
		return;
	int i = l, j = h;
	Interval temp(data[l].start, data[l].end);
	while (i < j) {
		while (i < j && data[j].start >= temp.start ) 
			j--;
		data[i].start = data[j].start;
		data[i].end = data[j].end;
		while (i < j && data[i].start <= temp.start) 
			i++;
		data[j].start = data[i].start;
		data[j].end = data[i].end;
	}
	data[i].end = temp.end;
	data[i].start = temp.start;
	quick_sort2(data, l, i - 1);
	quick_sort2(data, i + 1, h);
}


vector<Interval> merge(vector<Interval>& intervals) {
	vector<Interval> result;
	if (intervals.empty() == true)
		return result;

	quick_sort2(intervals, 0, intervals.size() - 1);

	Interval temp(intervals[0].start, intervals[0].end);
	int i = 0;
	while ( i < intervals.size()) {
		int j = i;
		while (j < intervals.size() && intervals[j].start <= temp.end) {
			temp.end = temp.end > intervals[j].end ? temp.end : intervals[j].end;
			j++;
		}
		result.push_back(temp);
		//temp = intervals[i];
		j == i ? i++ : i = j;//更新
		if (i < intervals.size())
			temp = intervals[i];
	}
	return result;
}

int main()
{
	vector<Interval> v({
		Interval(1,4),
		Interval(0,4),
		//Interval(8,10),
		//Interval(15,18),
	});
	v = merge(v);
	for (Interval c : v)
		cout << '[' << c.start << ',' << c.end << ']' << "  ";
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
