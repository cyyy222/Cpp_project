#include<iostream>
#include<queue>
#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	
	int n, p, m;
	
	while (1) {
		queue<int> que;
		scanf_s("%d%d%d", &n, &p, &m);
		if (n == 0 && p == 0 && m == 0) {
			break;
		}
		//将所有学生入队，队头为p位置的学生
		for (int i = p;;++i) {
			que.push(i);
			if (i == n) {
				i = 0;
			}
			
			if (que.size() == n) {
				break;
			}
		}

		//开始进行报数，报道m的学生出队
		for (int i = 1;i<=m;++i) {
			
			int tmp = que.front();
			que.pop();
			if (i == m&&!que.empty()) {
				printf("%d,", tmp);
				i = 0;
			}
			else if (i==m&&que.empty()) {
				printf("%d\n", tmp);
			}
			else {
				que.push(tmp);
			}
			
			
		}


	}
}