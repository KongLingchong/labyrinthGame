#include <iostream>
#include <windows.h>
#include <cstdlib>
using namespace std;
int map[8][8],move,a1 = 0,b1 = 0,a2 = 0,b2 = 0;
//��һ�ֳ�ʼ������
void initDef()
{
	//0��ʾ·��1��ʾǽ��2��ʾ���λ�ã�3��ʾ�յ�λ��
	map[0][0] = 2;
	for (int i = 1;i <= 7;i++)
	{
		map[i][0] = 1;
		map[0][i] = 1;
		map[7][i] = 1;
		map[i][7] = 1;
	}
	map[1][0] = 0;
	map[6][6] = 3;
	map[2][2] = 1;
	map[2][3] = 1;
	map[3][2] = 1;
	map[3][3] = 1;
	map[3][4] = 1;
	map[3][5] = 1;
	map[4][5] = 1;
	map[5][2] = 1;
	map[5][3] = 1;
	map[5][6] = 1;
	map[5][5] = 1;
}
//ǽ����ײ��⺯��
bool meetDef(int a,int b)
{
	if (map[a][b] == 0 || map[a][b] == 3)
	{
		return true;
	}
	else if (map[a][b] == 1)
	{
		return false;
	}
}
//������º��� 
void aginDef()
{
	system("cls");
	for (int i = 0;i < 8;i++)
	{
		for (int j = 0;j < 8;j++)
		{
			if (map[i][j] == 0)
			{
				cout << "  ";
			}
			else if (map[i][j] == 1)
			{
				cout << "ǽ";
			}
			else if (map[i][j] == 2)
			{
				cout << "��";
			}
			else if (map[i][j] == 3)
			{
				cout << "��"; 
			}
		}
		cout << endl; 
	}
}
//ʤ���жϺ��� 
bool winDef()
{
	if (map[6][6] == 2)
	{
		return true;
	}
	return false;
}

//���������� 
int WINAPI WinMain(HINSTANCE hlnstance,HINSTANCE hPrevlnstance,PSTR szCmdLine,int nCmdShow)
{
	initDef();
	aginDef();
	MessageBox(NULL,TEXT("��ӭ�����Թ���Ϸ"),TEXT("�Թ���Ϸ"),0);
	while (true)
	{
		aginDef();
		cout << endl;
		cout << "������һ�����֣����������Թ����λ��" << endl;
		cout << "1��ʾ���ϣ�2��ʾ���£�3��ʾ����4��ʾ����" << endl;
		cin >> move;
		if (move == 1)
		{
			a2 = a2 - 1;
		}
		else if (move == 2)
		{
			a2 = a2 + 1;
		}
		else if (move == 3)
		{
			b2 = b2 - 1;
		}
		else if (move == 4)
		{
			b2 = b2 + 1;
		}
		else
		{
			MessageBox(NULL,TEXT("������Ч��"),TEXT("�Թ���Ϸ"),0);
		}
		if (meetDef(a2,b2))
		{
			map[a1][b1] = 0;
			a1 = a2;b1 = b2;
			map[a2][b2] = 2;
		}
		if (winDef())
		{
			MessageBox(NULL,TEXT("��ϲ�㣬���ѳɹ��ߵ��յ�"),TEXT("�Թ���Ϸ"),0);
			break;
		}
	}
	MessageBox(NULL,TEXT("�����˳���Ϸ"),TEXT("�Թ���Ϸ"),0);
	MessageBox(NULL,TEXT("û�뵽�ɣ��⻹�и��ʵ������ȷ�������ȷ���Ƿ����ʵ�����"),TEXT("�Թ���Ϸ"),0);
	int yn = rand()%1;
	MessageBox(NULL,TEXT("��������ɽ�������ȷ������"),TEXT("�Թ���Ϸ"),0);
	if (yn == 1)
	{
		MessageBox(NULL,TEXT("��ϲ�㣬�ѳɹ������ʵ�"),TEXT("�Թ���Ϸ"),0);
		system("cls");
		int cd = rand()%2;
		int ans = 0;
		if (cd == 1)
		{
			MessageBox(NULL,TEXT("��Ϊ�����ѡ��ʵ����ʵ����£����һ��0~10������"),TEXT("�ʵ�"),0);
			int num1 = rand()%10;
			while (true)
			{
				cout << "������һ�����֣�";
				cin >> ans;
				if (ans == num1)
				{
					break;
				}
				else if (ans > num1)
				{
					MessageBox(NULL,TEXT("�µ������е���ٲ�һ��"),TEXT("�ʵ�"),0);
				}
				else if (ans < num1)
				{
					MessageBox(NULL,TEXT("�µ������е�С���ٲ�һ��"),TEXT("�ʵ�"),0);
				} 
			}
			MessageBox(NULL,TEXT("��ϲ�㣬�¶��ˣ����ڣ��������˳���Ϸ��"),TEXT("�ʵ�"),0);
		}
		else
		{
			MessageBox(NULL,TEXT("��Ϊ�����ѡ��ʵ����ʵ����£����һ��0~30������"),TEXT("�ʵ�"),0);
			int num1 = rand()%30;
			while (true)
			{
				cout << "������һ�����֣�";
				cin >> ans;
				if (ans == num1)
				{
					break;
				}
				else if (ans > num1)
				{
					MessageBox(NULL,TEXT("�µ������е���ٲ�һ��"),TEXT("������"),0);
				}
				else if (ans < num1)
				{
					MessageBox(NULL,TEXT("�µ������е�С���ٲ�һ��"),TEXT("������"),0);
				} 
			}
			MessageBox(NULL,TEXT("��ϲ�㣬�¶��ˣ����ڣ��������˳���Ϸ��"),TEXT("������"),0);
		}
	}
	else
	{
		MessageBox(NULL,TEXT("���ź����޷������ʵ�����Ϸ�˳�"),TEXT("�Թ���Ϸ"),0);
	}
	return 0;
}
