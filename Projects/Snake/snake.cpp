#include <graphics.h>
#include <time.h>
#include <conio.h>

#define Width 400
#define Height 300

int direct = 3;
struct Food
{
	int x;
	int y;
};
Food food;
bool IsFood = true;
bool IsOver = false;
struct Body
{
	int x;
	int y;
};
Body snake[1200];
int len;
bool IsChange = true;

void AddFood();
void Move();
void Paint();

DWORD WINAPI ThreadProc(LPVOID lParam);
int main()
{
	initgraph(Width, Height);
	srand((unsigned int)time(0));
	snake[0].x = 0;
	snake[0].y = 0;
	len = 1;
	AddFood();
	CreateThread(0, 0, ThreadProc, 0, 0, 0);
	while (!IsOver)
	{
		Paint();
		Move();
		Sleep(100);
	}

	getch();
	closegraph();
	return 0;
}

void AddFood()
{
	if (!IsFood)
		return;
	IsFood = false;
	bool b = false;

	do
	{
		food.x = rand() % (Width / 10);
		food.y = rand() % (Height / 10);

		for (int i = 0; i < len; i++)
		{
			if (snake[i].x == food.x&&snake[i].y == food.y)
			{
				b = true;
				break;
			}
			else
				b = false;
		}
	} while (b);

}

void Move()
{
	int px = 0;
	int py = 0;
	switch (direct)
	{
	case 0:
		py -= 1;
		break;
	case 1:
		py += 1;
		break;
	case 2:
		px -= 1;
		break;
	case 3:
		px += 1;
		break;
	}
	Body head;
	head.x = snake[0].x + px;
	head.y = snake[0].y + py;
	for (int i = len - 1; i > 0; i--)
	{
		snake[i] = snake[i - 1];
		if (head.x == snake[i].x&&head.y == snake[i].y)
			IsOver = true;
	}
	
	snake[0].x += px;
	snake[0].y += py;
	if (snake[0].x < 0)
		snake[0].x = 39;
	if (snake[0].x>39)
		snake[0].x = 0;

	if (snake[0].y < 0)
		snake[0].y = 29;
	if (snake[0].y>29)
		snake[0].y = 0;

	if (snake[0].x == food.x&&snake[0].y == food.y)
	{
		snake[len].x = -1;
		snake[len].y = -1;
		len++;
		IsFood = true;
		
		food.x = -1;
		food.y = -1;
	}
	AddFood();
	IsChange = true;
}

void Paint()
{
	IMAGE img(400, 300);

	SetWorkingImage(&img);

	setfillcolor(RGB(255, 255, 255));
	solidrectangle(0, 0, 400, 300);
	setfillcolor(RGB(0, 255, 0));
	for (int i = 0; i < len; i++)
	{
		fillrectangle(snake[i].x * 10, snake[i].y * 10, snake[i].x * 10 + 10, snake[i].y * 10 + 10);
	}
	setfillcolor(RGB(255, 0, 0));
	fillrectangle(food.x * 10, food.y * 10, food.x * 10 + 10, food.y * 10 + 10);

	SetWorkingImage();
	putimage(0, 0, &img);
}

DWORD WINAPI ThreadProc(LPVOID lParam)
{
	while (!IsOver)
	{
		char ch = _getch();

		if (!IsChange)
			continue;
		switch (ch)
		{
		case 'W':
		case 'w':
			if (direct == 1)
				break;
			direct = 0;
			IsChange = false;
			break;
		case 'S':
		case 's':
			if (direct == 0)
				break;
			direct = 1;
			IsChange = false;
			break;
		case 'A':
		case 'a':
			if (direct == 3)
				break;
			direct = 2;
			IsChange = false;
			break;
		case 'D':
		case 'd':
			if (direct == 2)
				break;
			direct = 3;
			IsChange = false;
			break;
		}
	}
	return 0;
}