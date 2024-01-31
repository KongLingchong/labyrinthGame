#include <iostream>
#include <windows.h>
#include <cstdlib>
using namespace std;
int map[8][8],move,a1 = 0,b1 = 0,a2 = 0,b2 = 0;
//第一轮初始化函数
void initDef()
{
	//0表示路，1表示墙，2表示玩家位置，3表示终点位置
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
//墙壁碰撞检测函数
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
//画面更新函数 
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
				cout << "墙";
			}
			else if (map[i][j] == 2)
			{
				cout << "你";
			}
			else if (map[i][j] == 3)
			{
				cout << "终"; 
			}
		}
		cout << endl; 
	}
}
//胜利判断函数 
bool winDef()
{
	if (map[6][6] == 2)
	{
		return true;
	}
	return false;
}

//程序主函数 
int WINAPI WinMain(HINSTANCE hlnstance,HINSTANCE hPrevlnstance,PSTR szCmdLine,int nCmdShow)
{
	initDef();
	aginDef();
	MessageBox(NULL,TEXT("欢迎来玩迷宫游戏"),TEXT("迷宫游戏"),0);
	while (true)
	{
		aginDef();
		cout << endl;
		cout << "请输入一个数字，控制你在迷宫里的位置" << endl;
		cout << "1表示向上，2表示向下，3表示向左，4表示向右" << endl;
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
			MessageBox(NULL,TEXT("操作无效！"),TEXT("迷宫游戏"),0);
		}
		if (meetDef(a2,b2))
		{
			map[a1][b1] = 0;
			a1 = a2;b1 = b2;
			map[a2][b2] = 2;
		}
		if (winDef())
		{
			MessageBox(NULL,TEXT("恭喜你，你已成功走到终点"),TEXT("迷宫游戏"),0);
			break;
		}
	}
	MessageBox(NULL,TEXT("即将退出游戏"),TEXT("迷宫游戏"),0);
	MessageBox(NULL,TEXT("没想到吧，这还有个彩蛋，点击确定，随机确定是否进入彩蛋环节"),TEXT("迷宫游戏"),0);
	int yn = rand()%1;
	MessageBox(NULL,TEXT("已随机生成结果，点击确定继续"),TEXT("迷宫游戏"),0);
	if (yn == 1)
	{
		MessageBox(NULL,TEXT("恭喜你，已成功触发彩蛋"),TEXT("迷宫游戏"),0);
		system("cls");
		int cd = rand()%2;
		int ans = 0;
		if (cd == 1)
		{
			MessageBox(NULL,TEXT("已为你随机选择彩蛋。彩蛋如下：请猜一个0~10的数字"),TEXT("彩蛋"),0);
			int num1 = rand()%10;
			while (true)
			{
				cout << "请输入一个数字：";
				cin >> ans;
				if (ans == num1)
				{
					break;
				}
				else if (ans > num1)
				{
					MessageBox(NULL,TEXT("猜的数字有点大，再猜一遍"),TEXT("彩蛋"),0);
				}
				else if (ans < num1)
				{
					MessageBox(NULL,TEXT("猜的数字有点小，再猜一遍"),TEXT("彩蛋"),0);
				} 
			}
			MessageBox(NULL,TEXT("恭喜你，猜对了，现在，就真正退出游戏了"),TEXT("彩蛋"),0);
		}
		else
		{
			MessageBox(NULL,TEXT("已为你随机选择彩蛋。彩蛋如下：请猜一个0~30的数字"),TEXT("彩蛋"),0);
			int num1 = rand()%30;
			while (true)
			{
				cout << "请输入一个数字：";
				cin >> ans;
				if (ans == num1)
				{
					break;
				}
				else if (ans > num1)
				{
					MessageBox(NULL,TEXT("猜的数字有点大，再猜一遍"),TEXT("猜数字"),0);
				}
				else if (ans < num1)
				{
					MessageBox(NULL,TEXT("猜的数字有点小，再猜一遍"),TEXT("猜数字"),0);
				} 
			}
			MessageBox(NULL,TEXT("恭喜你，猜对了，现在，就真正退出游戏了"),TEXT("猜数字"),0);
		}
	}
	else
	{
		MessageBox(NULL,TEXT("很遗憾，无法触发彩蛋，游戏退出"),TEXT("迷宫游戏"),0);
	}
	return 0;
}
