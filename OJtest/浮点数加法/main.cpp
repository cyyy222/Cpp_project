#include<stdio.h>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>


using namespace std;

//find��������������size_t���ߵ�����
//substr����������һ��λ������ʼλ�ã��ڶ���λ���ǳ���
//��ȡ�ַ���С������
string funtion1(string st) {
	return st.substr(st.find('.') + 1, st.size()-st.find('.'));
}

//��ȡ�ַ�����������
string funtion2(string st) {
	return st.substr(0, st.find('.'));
}

//max�������������������нϴ����
//�ַ���С�����ּӷ�
void funtion3(string& x,string s1x,string s2x,int& count) {
	int Max = max(s1x.size(), s2x.size());
	
	while (s1x.size() < Max) {
		s1x.push_back('0');
	}
	
	while (s2x.size() < Max) {
		s2x.push_back('0');
	}

	x.resize(Max);

	count = 0;

	for (int i = Max-1;i >= 0;--i) {
		if (s1x[i] + s2x[i] - '0'+count>'9') {
			x[i] = s1x[i] + s2x[i] + count - '0' - 10;
			count = 1;
		}
		else {
			x[i] = s1x[i] + s2x[i] + count - '0';
			count = 0;
		}
	}

	return;

}

//�ַ����������ּӷ�
void funtion4(string& z,string s1z,string s2z,int& count) {

	for (int i = s1z.size() - 1, j = s2z.size() - 1;i>= 0 || j>= 0 || count == 1;--i, --j) {
		//
		if (i>= 0 &&j>= 0) {
			if (s1z[i] + s2z[j] + count - '0' > '9') {
				z.insert(z.begin(), s1z[i] + s2z[j] + count - '0'-10);
				count = 1;
			}
			else {
				z.insert(z.begin(), s1z[i] + s2z[j] + count - '0');
				count = 0;
			}	
		}
		else if (i<0&&j>=0) {
			if (s2z[j] + count  > '9') {
				z.insert(z.begin(), s2z[j] + count - 10);
				count = 1;
			}
			else {
				z.insert(z.begin(), s2z[j] + count);
				count = 0;
			}
		}
		else if (i>=0 && j<0) {
			if (s1z[i] + count  > '9') {
				z.insert(z.begin(), s1z[i] +  count - 10);
				count = 1;
			}
			else {
				z.insert(z.begin(), s1z[i] + count);
				count = 0;
			}
		}
		else if(count==1){
			z.insert(z.begin(), '1');
		}
	}

	return;

}


int main() {
	string s1;
	string s2;
	cin >> s1;
	cin >> s2;

	string s1x = funtion1(s1);
	string s2x = funtion1(s2);

	string s1z = funtion2(s1);
	string s2z = funtion2(s2);

	string x;
	string z;
	int count;
	funtion3(x,s1x,s2x,count);
	funtion4(z,s1z,s2z,count);

	cout << z << "." << x << endl;

}