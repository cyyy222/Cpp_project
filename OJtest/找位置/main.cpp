#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<map>

using namespace std;

int main() {
	string input;
	getline(cin, input);
	//��¼�ַ������ַ����г��ֵ�λ��
	map<char, vector<int>> xx;
	//��¼��һ�γ��ֵ��ַ�
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
		//����ظ����ֵĴ�
		if (xx[*it].size() > 1) {
			vector<int>::iterator id = xx[*it].begin();
			cout << *it << ":" << *id;
			for (id = xx[*it].begin() + 1;id < xx[*it].end();++id) {
				cout << ", " << *it << ":" << *id;
			}
			cout << endl;
		}
	}


	//�����ҳ��ַ������ظ����ַ�����Ҫ�����
	//����:abcaaAB12ab12


}