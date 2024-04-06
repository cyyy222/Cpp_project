#include<stdio.h>
#include<graphics.h>
#include<Windows.h>
#include<time.h>
#define BJ_width 1408
#define	 BJ_height  800
#define  WJ_bullet  15//һ�η�����ӵ�����
#define  DR_enemy   10//�л�������
#define  DR_bullet    10//�л�������ӵ�

IMAGE bk;//����
IMAGE me;//�ҷ��ɻ�
IMAGE bull;//�ӵ�
IMAGE emy;//�л�
IMAGE emybull;//�л��ӵ�
IMAGE happyend;//ͨ��
IMAGE badend;//ʧ��
int score = 0;
int life = 10;
int i, x;
int y = 0;
int code = 123456;

DWORD t1, t2;
//����ɻ��ṹ��
struct  Plane
{
	int x;
	int y;
	bool flag;
	int width;
	int height;
}flyme, bullet[WJ_bullet], enemy[DR_enemy], enemybullet[DR_bullet], kunge, kungege;

//���ö�ʱ��
bool Timer(int ms, int id)
{
	static int start[5];
	int end = clock();
	if(end - start[id] >= ms)
	{
		start[id] = end;
		return true;
	}
	return false;
}

//��ʼ������
void GameInit() 
{ 
    initgraph(BJ_width, BJ_height,SHOWCONSOLE);//����һ��ͼ�λ�����
	srand(GetTickCount());
	loadimage(&bk, "./tp/beijin.png");
	//loadimage(&bk, "./tp/shejie.jpg");//��ͼƬ����ͼ�λ�������
	loadimage(&me, "./tp/fly2.png");//���Լ��ɻ�����ͼ�λ�������
	loadimage(&bull, "./tp/zidan1.jfif");//���ӵ�����ͼ�λ�������
	loadimage(&emy, "./tp/diren1.png");//���л�����ͼ�λ�������
	loadimage(&emybull, "./tp/zidan3.jfif");//���л��ӵ�����ͼ�λ�������
	loadimage(&happyend, "./tp/kunge.jpg");//��ʤ����������
	loadimage(&badend, "./tp/kungege.jpg");//��ʧ�ܱ�������
	flyme.height = 55;
	flyme.width = 38; 
	flyme.x = BJ_width / 2 - flyme.width / 2;//�ɻ�xλ��
	flyme.y = BJ_height - flyme.height;//�ɻ�yλ��
	flyme.flag = true;
	for(int i=0 ; i < WJ_bullet ; i++ )//�ӵ��ĳ�ʼ��
	{
		bullet[i].flag = false;
		bullet[i].height = 25;
		bullet[i].width = 20;
	}
	t1 = t2 = GetTickCount(); //��ʼ���ӵ�����ʱ��
	for(int i =0 ; i < DR_enemy ; i++)//��ʼ���л�
	{
		enemy[i].flag = false;
		enemy[i].width = 57;
		enemy[i].height = 74;

	}
	for (int i = 0; i < DR_bullet; i++)//�л��ӵ���ʼ��
	{
		enemybullet[i].flag = false;
		enemybullet[i].height = 17;
		enemybullet[i].width = 10;
	}
	kunge.x = 270;
	kunge.y = 100;
	kungege.x = 400;
	kungege.y = 100;

}

//���ͼ�Σ����ƺ���
void GameDarw()
{
	BeginBatchDraw();
	putimage(0,  0,  &bk);//�������ͼƬ
	if (flyme.flag) //�жϷɻ��Ƿ��������
	{
		putimage(flyme.x, flyme.y, &me);//����Լ��ɻ�ͼƬ
	}
	for(int i = 0 ; i< WJ_bullet ; i++)//����ȫ���ӵ�
	{
		if (bullet[i].flag)//�ж��ӵ��Ƿ��������
		{
			putimage(bullet[i].x, bullet[i].y, &bull);//����ӵ�ͼƬ
		}
	}
	for(int i =0 ; i < DR_enemy; i++)//�������ел�
	{
		if (enemy[i].flag)//�жϵл��Ƿ��������
		{
			putimage(enemy[i].x, enemy[i].y, &emy);//����о�ͼƬ
		}
	}
	for (int i = 0; i < DR_bullet; i++) //����л��ӵ�
	{
		if(enemybullet[i].flag)
		{
			putimage(enemybullet[i].x, enemybullet[i].y, &emybull);
		}
	}
	outtextxy(0, 0, "�÷�:");//���÷��������Ϸ��
	char s[5];
	sprintf_s(s, "%d", score);
	outtextxy(36, 0, s);
	if(score>=66)
	{
		cleardevice();
		putimage(kunge.x, kunge.y, &happyend);
		outtextxy(610, 590, "��Ϸ��������ͨ�أ�");
		enemy->flag = false;
		enemybullet->flag = false;
		flyme.flag = false;
	}
	outtextxy(0, 17, "����:");//�������������Ϸ��
	char c[5];
	sprintf_s(c, "%d", life);
	outtextxy(36, 17,c);
	if(life<=0)
	{
		cleardevice();
		putimage(kungege.x, kungege.y, &badend);
		outtextxy(610, 590, "���ź���Ϸʧ��");
		enemy->flag = false;
		enemybullet->flag = false;
		flyme.flag = false;
	}
	EndBatchDraw();
}

//С����
void Window()
{
	HWND hnd = GetHWnd();
	MessageBox(hnd, "������ȷ���Ƿ�ʼ��Ϸ", "��ʾ", MB_OK);
}

//�����ӵ�
void CreatBullet()
{
	for (int i = 0; i < WJ_bullet; i++)
	{
		if (!bullet[i].flag)//����ӵ����������ӵ�
		{
			bullet[i].x = flyme.x + 10;
			bullet[i].y = flyme.y;
			bullet[i].flag = true;
			break;
		}
	}
}

//�ӵ��ƶ�
void Bulltemove(int p)
{
	for (int i = 0; i < WJ_bullet; i++)
	{
		if (bullet[i].flag)
		{
			p = bullet[i].y--;
			if(bullet[i].y < 0)//����ӵ�������y=0���ӵ���Ϊ�����
			{
				bullet[i].flag = false;
			}
		}
	}
}

//���ɵл�
void CreatEnemy() 
{
	for (int i = 0; i < DR_enemy; i++)
	{
		if (!enemy[i].flag)
		{
			if(Timer(100,0))
			{
				enemy[i].x = rand() % (BJ_width - enemy[i].width);
				enemy[i].y = 0;
				enemy[i].flag = true;
				break;
			}	
		}
	}
}

//�л��ƶ�
void Enemymove(int p)
{
	if(Timer(10,1))
	{ 
		for (int i = 0; i < DR_enemy; i++)
		{
			if (enemy[i].flag)
			{
				p = enemy[i].y++;
				if (enemy[i].y > BJ_height)
					{
						enemy[i].flag = false;
					}
			}
		}
	}
}

//���ɵл��ӵ�
void Enemybullet()
{
	for (int i = 0; i < DR_bullet; i++)
	{
		if (!enemybullet[i].flag)
		{
			if(Timer(100,3))
			{
				enemybullet[i].x = enemy[i].x + 22;
				enemybullet[i].y = enemy[i].y + 67;
				enemybullet[i].flag = true;
				break;
			}
		}
	}
}

//�л��ӵ��ƶ�
void Enemybulletmove(int p)
{
	if (Timer(2, 2)) 
	{
		for (int i = 0; i < DR_bullet; i++)
		{
			if (enemybullet[i].flag)
			{
				p = enemybullet[i].y++;
				if (enemybullet[i].y > BJ_height)
				{
					enemybullet[i].flag = false;
				}
			}
		}
	}
	
}

//�ɻ��ƶ�
void Control( int p)
{
	if (GetAsyncKeyState(VK_UP) && flyme.y>=0) //����
	{
		p = flyme.y--;
	}
	if (GetAsyncKeyState(VK_DOWN) && flyme.y + flyme.height<= BJ_height)//����
	{
		p = flyme.y++;
	}
	if (GetAsyncKeyState(VK_LEFT) && flyme.x + flyme.width/2>=0)//����
	{
		p = flyme.x--;
	}
	if (GetAsyncKeyState(VK_RIGHT) && flyme.x + flyme.width/2<= BJ_width)//����
	{
		p = flyme.x++;
	}
	if (GetAsyncKeyState(VK_SPACE) && t2-t1 >200)//����
	{
		CreatBullet();
		printf_s("11111");
		t1 = t2;
	}
	t2 = GetTickCount();
}

//����л�
void Bullteenemy()
{
	for (int i = 0; i < DR_enemy; i++) 
	{
		if (!enemy[i].flag)//�жϵл��Ƿ�����ʧ����ʧ������
			continue;
		for (int j = 0; j < WJ_bullet; j++)
		{
			if (!bullet[j].flag)//�ж��ӵ��Ƿ�����ʧ����ʧ������
				continue;
			if (bullet[j].x > enemy[i].x && bullet[j].x < enemy[i].x + enemy[i].width &&
				bullet[j].y > enemy[i].y && bullet[j].y < enemy[i].y + enemy[i].height)//�ж��ӵ��Ƿ���ел�
			{
				enemy[i].flag = false;
				bullet[i].flag = false;
				score = score + 2;
			}
		}
	}

}

//�л����
void Gamelife()
{
	for(int i =0;i<DR_bullet; i++)
	{
		if (!enemybullet[i].flag)
			continue;
		if (enemybullet[i].x > flyme.x && enemybullet[i].x < flyme.x + flyme.width &&
			enemybullet[i].y > flyme.y && enemybullet[i].y < flyme.y + flyme.height)//�жϵл��ӵ��Ƿ�����ҷ�
		{
			enemybullet[i].flag = false;
			life = life - 1;
		}
	}
}

//�໥��ײ
void Ganmelifeenemy()
{
	for(int i =0;i<DR_enemy;i++)
	{
		if (!enemy[i].flag)
			continue;
		if (flyme.x < enemy[i].x + enemy[i].width &&  flyme.x +flyme.width > enemy[i].x  &&
			flyme.y < enemy[i].y + enemy[i].height && flyme.y +flyme.height >enemy[i].y)//�жϵл��Ƿ�ײ���ҷ�
		{
			enemy[i].flag = false;
			life = life - 1;
		}
	}
}

//�ӵ���ײ
void Gameenemybull()
{
	for(int i =0;i<DR_bullet;i++)
	{
		if (!enemybullet[i].flag)
			continue;
		if (bullet->x-6 < enemybullet[i].x +enemybullet[i].width && bullet->x + bullet->width +5 > enemybullet[i].x  &&
			bullet->y <= enemybullet[i].y +enemybullet[i].height )
		{
			enemybullet[i].flag = false;
			bullet->flag = false;
		}
	}
}

int main() 
{
	printf("**************************��ӭ�����ɻ���ս*************************\n");
	for (i = 0; i < 3; i++)
	{
		printf("�û�����:611313651313\n");
		printf("����������:");
		scanf_s("%d", &x);
		if (x == code)
		{          
			printf("��½�ɹ�\n");
			GameInit();
			Window();
			getchar();
			while (1)
			{
				GameDarw();
				Control(1);
				Bulltemove(1);
				CreatEnemy();
				Enemybullet();
				Enemymove(1);
				Enemybulletmove(1);
				Bullteenemy();
				Gamelife();
				Ganmelifeenemy();
				Gameenemybull();
			}
			y = 1;  
			break;
		}
		else {
			printf("�����������������\n");
		}
	}
	if (y == 0) {
		printf("\n");
		printf("������������ѵ�,���˳�");
	}
	getchar();
	return 0;
}