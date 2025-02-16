#include<iostream>
#include<stack>
#include<string>
#include<algorithm>

using namespace std;

int main() {
	string str;
	
	cin >> str;
	stack<char> z;
	for (int i = 0;i < str.size();++i) {
		if (z.empty() && str[i] == '>' && str[i] == '}' && str[i] == ')' && str[i] == ']') {
			cout << "NO" << endl;
		}
		else if (z.empty()) {
			if (str[i] == '<') {
				z.push(str[i]);
			}
			else if (str[i] == '[') {
				z.push(str[i]);
			}
			else if (str[i] == '{') {
				z.push(str[i]);
			}
			else if (str[i] == '(') {
				z.push(str[i]);
			}

		}
		else if (!z.empty()) {
			if (str[i] == '<') {
				z.push(str[i]);
			}
			else if (str[i] == '[') {
				z.push(str[i]);
			}
			else if (str[i] == '{') {
				z.push(str[i]);
			}
			else if (str[i] == '(') {
				z.push(str[i]);
			}
			else if (str[i] == '>'&&z.top()=='<') {
				z.pop();
			}
			else if (str[i] == '}' && z.top() == '{') {
				z.pop();
			}
			else if (str[i] == ']' && z.top() == '[') {
				z.pop();
			}
			else if (str[i] == ')' && z.top() == '(') {
				z.pop();
			}
			else {
				cout << "NO" << endl;
			}
		}
	}
	if (z.empty()) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}

}