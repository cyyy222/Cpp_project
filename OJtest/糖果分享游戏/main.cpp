#include<stdio.h>
#include<vector>

using namespace std;

//��ÿ��ѧ���ǹ���һ�뽻����һ��ͬѧ������������ǹ�Ϊ������Ҫ��1
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

//�ж�ÿ��ѧ���ǹ������Ƿ���ͬ
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

	//����һЩѧ��Χ��һȦ���ţ�������м����ʦ��
	//ÿ��ѧ���������ż�����ǹ�������ʦ��������ʱ��
	//ÿ��ѧ��ͬʱ����������һ���ǹ����ұߵ��ھӡ�
	//�κ�ѧ����������յõ��������ǹ�����ʦ�ͻ������һ�顣
	//������ѧ��������ͬ�������ǹ�ʱ����Ϸ������
	
	
}


