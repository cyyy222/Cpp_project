#include<stdio.h>
#include<vector>

using namespace std;

//将每个学生糖果的一半交给后一个同学，如果交换后糖果为奇数则要加1
void Sharecandy(vector<int>& student) {
	int size = student.size();
	vector<int> xx(size);
	for (int i = 0;i < size;++i) {
		xx[i] = student[i] / 2;
	}

	for (int i = 0;i < size;++i) {
		student[i] -= xx[i];
	}
	for (int i = 0;i < size;++i) {
		student[(i + 1) % size] += xx[i];
	}
	for (int i = 0;i < size;++i) {
		if (student[i] % 2 == 1) {
			++student[i];
		}
	}
}

//判断每个学生糖果数量是否相同
bool  Candy(vector<int>& student){
	int size = student.size();
	int one = student[0];
	for (int i = 1;i < size;++i) {
		if (one != student[i]){
			return false;
		}
	}
	return true;
}

int main() {
	int N;
	while (scanf("%d", &N)!=EOF){
		if (N == 0) {
			break;
		}

		vector<int> student(N);
		for (int i = 0;i < N;++i) {
			scanf_s("%d", &student[i]);
		}

		int number = 0;
		while (Candy(student)==false) {
			Sharecandy(student);
			++number;
		}

		printf("%d %d\n", number, student[0]);

	}
	return 0;

	//任务：一些学生围成一圈坐着，面对着中间的老师。
	//每个学生最初都有偶数颗糖果。当老师吹响哨声时，
	//每个学生同时将他或她的一半糖果给右边的邻居。
	//任何学生，如果最终得到奇数块糖果，老师就会给他另一块。
	//当所有学生都有相同数量的糖果时，游戏结束。
	
	
}


