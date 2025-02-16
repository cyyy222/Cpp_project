
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

//sort（）函数可以将数组进行排序（按从小到大或从大到小），可以根据要求进行函数重载
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

	//任务：将学生按成绩从高到低或者从低到高排序，成绩相同者按先输入系统的排在前面

}