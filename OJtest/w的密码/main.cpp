#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

void Funtion(string& str ,vector<int>& vec ,int offset) {
	vector<char> temp;
	//保持数组中后offset个数据，将其存储到另一个数组中，再将剩下的几个数进行右旋操作后，再移出的offset个数写回
	for (int i = vec.size() - offset;i < vec.size();++i) {
		temp.push_back(str[vec[i]]);
	}
	for (int i = vec.size() - offset - 1;i >= 0;--i) {
		str[vec[i + offset]] = str[vec[i]];
	}
	for (int i = 0;i < offset;++i) {
		str[vec[i]] = temp[i];
	}
}


int main() {
	int a, b, c;
	string str;
	string newstr;

	//存储a~i  
	vector<int> vec1;
	//存储j~r
	vector<int> vec2;
	//存储s~z与下划线_
	vector<int> vec3;

	while (cin >> a >> b >> c) {
		if (a == 0 && b == 0 && c == 0) {
			cout << "程序已退出" << endl;
			break;
		}
		//输入字符串
		cin >> str;
		

		//1.分组
		int i;
		for (i = 0;i < str.size();++i) {
			if (str[i] >= 'a' && str[i] <= 'i') {
				vec1.push_back(i);
			}
			else if (str[i] >= 'j' && str[i] <= 'r') {
				vec2.push_back(i);
			}
			else {
				vec3.push_back(i);
			}
		}


		//2.右旋
		Funtion(str, vec1, a);
		Funtion(str, vec2, b);
		Funtion(str, vec3, c);


		cout << str << endl;
		


	}


	return 0;

}