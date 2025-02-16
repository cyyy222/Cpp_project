
#include<vector>
#include<algorithm>
#include<iostream>


using namespace std;

struct Student {
	string name;
	int score;
	int seq;
};



bool compare0(Student lhs, Student rhs) {
	if (lhs.score > rhs.score) return true;
	else if (lhs.score == rhs.score && lhs.seq < rhs.seq) return true;
	else return false;
}

bool compare1(Student lhs, Student rhs) {
	if (lhs.score < rhs.score) return true;
	else if (lhs.score == rhs.score && lhs.seq < rhs.seq) return true;
	else return false;
}

//sort�����������Խ�����������򣨰���С�����Ӵ�С�������Ը���Ҫ����к�������
int main() {

	int n;
	while (cin >> n) {
		vector<Student> xx(n);
		int xh;
		cin >> xh;
		for (int i = 0;i < n;i++) {
			cin >> xx[i].name >> xx[i].score;
			xx[i].seq = i;
		}
		
		if (xh == 0) {
			sort(xx.begin(), xx.end(), compare0);
		}
		else {
			sort(xx.begin(), xx.end(), compare1);
		}


		for (int i = 0;i < n;i++) {
			cout << xx[i].name << " " << xx[i].score << endl;
		}


	}

	//���񣺽�ѧ�����ɼ��Ӹߵ��ͻ��ߴӵ͵������򣬳ɼ���ͬ�߰�������ϵͳ������ǰ��

}