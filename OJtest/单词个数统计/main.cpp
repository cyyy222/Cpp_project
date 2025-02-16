#include<iostream>
#include<vector>
#include<stdio.h>
#include<map>
#include<string>

using namespace std;

//fgets()函数是C中使字符数组按行输入
//getline()函数是C++中使string类型含行输入
int main() {
	//输入一串字符数组
	char arr[200];
	
	fgets(arr, 200, stdin);

	map<char, int> cp;
	int i = 0;
	int apcount = 0;
	int wordcount = 0;
	bool isSpace = true;
	while (true) {
		if (arr[i] == '\n' || arr[i] == '\0') {
			break;
		}
		else if (arr[i] == ' ') {
			isSpace = true;
		}
		else {
			//记录有多少个字母
			++apcount;
			//记录有多少个词组
			if (isSpace) {
				++wordcount;
				isSpace = false;
			}
			//记录每个单词出现的次数，不区分大小写
			if (arr[i] >= 'A' && arr[i] <= 'Z') {
				arr[i] += 32;
			}
			++cp[arr[i]];
			
		}
		++i;
	}

	cout << apcount << endl;
	cout << wordcount << endl;
	
	//使用迭代器遍历map，找出出现次数最多的字母并输出这些字母，以及出现的频数
	map<char, int>::iterator it;
	int max = 0;
	for (it = cp.begin();it != cp.end();++it) {
		if (it->second > max) {
			max = it->second;
		}
	}
	for (it = cp.begin();it != cp.end();++it) {
		if (it->second == max) {
			cout << it->first<<" ";
		}
	}
	cout << endl;
	cout << max << endl;
	
		
	
	return 0;
	
}