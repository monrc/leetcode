// 49. Group Anagrams.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
	vector<int> hash_temp(128, 0);
	vector <vector<int>> hash;
	vector<int> num;
	vector<vector<string>> result;
	int null_num = 0;
	bool exist;
	for (int k = 0; k < strs.size(); k++) { //判断字符串strs[k]
		if (strs[k].empty() == true) {
			null_num++;
			continue;
		}
		exist = false;
		int i, j;
		for (i = 0; i < hash.size(); i++) { //判断hash[i]
			int j;
			for (j = 0; j < strs[k].size(); j++) { //判断字符串strs[k] 与 hash[i]  是否匹配
				if (hash[i][strs[k][j]] > 0)
					hash[i][strs[k][j]]--;
				else           //不匹配，加载下一个匹配表
					break;
			}

			for (int z = 0; z < j; z++) //恢复匹配表
				hash[i][strs[k][z]]++;

			if (j == strs[k].size() && j == num[i]){ //匹配成功则退出，否则加载下一个匹配表
				exist = true;
				break;
			}
		}

		if (exist == true)
			result[i].push_back(strs[k]);
		else {
			num.push_back(strs[k].size());//添加新的匹配表里字符的个数
			hash.push_back(hash_temp);  //添加新的匹配表
			for (int m = 0; m < strs[k].size(); m++)
				hash[i][strs[k][m]]++;
			result.push_back({ strs[k] });
		}
	}
	if (null_num > 0)  //尾部添加空字符串
		result.push_back(vector<string>(null_num, { "" }));
	return result;
}


int main()
{
	vector<string> strs({ "eat", "tea", "tan", "ate", "nat", "bat" });
	vector<vector<string>> v2;
	v2 = groupAnagrams(strs);
	for (vector<string> v1 : v2) {
		for (string s : v1)
			cout << s << " ";
		cout << endl;
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
