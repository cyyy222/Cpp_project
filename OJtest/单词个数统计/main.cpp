#include<iostream>
#include<vector>
#include<stdio.h>
#include<map>
#include<string>

using namespace std;

//fgets()������C��ʹ�ַ����鰴������
//getline()������C++��ʹstring���ͺ�������
int main() {
	//����һ���ַ�����
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
			//��¼�ж��ٸ���ĸ
			++apcount;
			//��¼�ж��ٸ�����
			if (isSpace) {
				++wordcount;
				isSpace = false;
			}
			//��¼ÿ�����ʳ��ֵĴ����������ִ�Сд
			if (arr[i] >= 'A' && arr[i] <= 'Z') {
				arr[i] += 32;
			}
			++cp[arr[i]];
			
		}
		++i;
	}

	cout << apcount << endl;
	cout << wordcount << endl;
	
	//ʹ�õ���������map���ҳ����ִ���������ĸ�������Щ��ĸ���Լ����ֵ�Ƶ��
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