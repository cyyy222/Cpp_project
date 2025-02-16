#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<map>

using namespace std;

int main() {
	string input;
	getline(cin, input);
	//记录字符和在字符串中出现的位置
	map<char, vector<int>> xx;
	//记录第一次出现的字符
	vector<char> cc;

	for (int i = 0;i < input.size();++i) {
		char ch = input[i];
		xx[ch].push_back(i);
		if (xx[ch].size() < 2) {
			cc.push_back(ch);
		}
	}
	vector<char>::iterator it;

	for (it = cc.begin();it < cc.end();++it) {
		//输出重复出现的词
		if (xx[*it].size() > 1) {
			vector<int>::iterator id = xx[*it].begin();
			cout << *it << ":" << *id;
			for (id = xx[*it].begin() + 1;id < xx[*it].end();++id) {
				cout << ", " << *it << ":" << *id;
			}
			cout << endl;
		}
	}


	//任务：找出字符串中重复的字符并按要求输出
	//样例:abcaaAB12ab12


}