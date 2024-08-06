#include<iostream>
using namespace std;
char cube[6][3][3];
char color[6] = { 'w','y','r','o','g','b' };

const int UP = 0;
const int DOWN = 1;
const int FRONT = 2;
const int BACK = 3;
const int LEFT = 4;
const int RIGHT = 5;

void initcube()
{
	for (int i = 0; i < 6; i++)
		for (int j = 0; j < 3; j++)
			for (int k = 0; k < 3; k++)
				cube[i][j][k] = color[i];
}
void rotate(int side, bool dir) {
	char tmp[3][3];
	if (dir) {
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				tmp[j][2 - i] = cube[side][i][j];
	}
	else {
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				tmp[2 - j][i] = cube[side][i][j];
	}
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			cube[side][i][j] = tmp[i][j];
}
void rotateSide(int side, bool dir)
{
	rotate(side, dir);
	char tmp;
	if (side == UP)
	{
		if(dir)
		for (int i = 0; i < 3; i++)
		{
			tmp = cube[FRONT][0][i];
			cube[FRONT][0][i] = cube[RIGHT][0][i];
			cube[RIGHT][0][i] = cube[BACK][2][2-i];
			cube[BACK][2][2-i] = cube[LEFT][0][i];
			cube[LEFT][0][i] = tmp;
		}
		else
			for (int i = 0; i < 3; i++)
			{
				tmp = cube[FRONT][0][i];
				cube[FRONT][0][i] = cube[LEFT][0][i];
				cube[LEFT][0][i] = cube[BACK][2][2-i];
				cube[BACK][2][2-i] = cube[RIGHT][0][i];
				cube[RIGHT][0][i] = tmp;
			}
	}
	else if (side == DOWN)
	{
		if (dir)
			for (int i = 0; i < 3; i++)
			{
				tmp = cube[FRONT][2][i];
				cube[FRONT][2][i] = cube[LEFT][2][i];
				cube[LEFT][2][i] = cube[BACK][0][2-i];
				cube[BACK][0][2-i] = cube[RIGHT][2][i];
				cube[RIGHT][2][i] = tmp;
			}
		else
			for (int i = 0; i < 3; i++)
			{
				tmp = cube[FRONT][2][i];
				cube[FRONT][2][i] = cube[RIGHT][2][i];
				cube[RIGHT][2][i] = cube[BACK][0][2-i];
				cube[BACK][0][2-i] = cube[LEFT][2][i];
				cube[LEFT][2][i] = tmp;
			}
	}
	else if (side == FRONT)
	{
		if (dir)
			for (int i = 0; i < 3; i++)
			{
				tmp = cube[UP][2][i];
				cube[UP][2][i] = cube[LEFT][2-i][2];
				cube[LEFT][2-i][2] = cube[DOWN][0][2 - i];
				cube[DOWN][0][2 - i] = cube[RIGHT][i][0];
				cube[RIGHT][i][0] = tmp;
			}
		else
			for (int i = 0; i < 3; i++)
			{
				tmp = cube[UP][2][i];
				cube[UP][2][i] = cube[RIGHT][i][0];
				cube[RIGHT][i][0] = cube[DOWN][0][2 - i];
				cube[DOWN][0][2 - i] = cube[LEFT][2-i][2];
				cube[LEFT][2-i][2] = tmp;
			}
	}
	else if (side == BACK)
	{
		if (dir)
			for (int i = 0; i < 3; i++)
			{
				tmp = cube[UP][0][i];
				cube[UP][0][i] = cube[RIGHT][i][2];
				cube[RIGHT][i][2] = cube[DOWN][2][2 - i];
				cube[DOWN][2][2 - i] = cube[LEFT][2 - i][0];
				cube[LEFT][2 - i][0] = tmp;
			}
		else
			for (int i = 0; i < 3; i++)
			{
				tmp = cube[UP][0][i];
				cube[UP][0][i] = cube[LEFT][2 - i][0];
				cube[LEFT][2 - i][0] = cube[DOWN][2][2 - i];
				cube[DOWN][2][2 - i] = cube[RIGHT][i][2];
				cube[RIGHT][i][2] = tmp;
			}
	}
	else if (side == LEFT)
	{
		if (dir)
			for (int i = 0; i < 3; i++)
			{
				tmp = cube[UP][i][0];
				cube[UP][i][0] = cube[BACK][i][0];
				cube[BACK][i][0] = cube[DOWN][i][0];
				cube[DOWN][i][0] = cube[FRONT][i][0];
				cube[FRONT][i][0] = tmp;
			}
		else
			for (int i = 0; i < 3; i++)
			{
				tmp = cube[UP][i][0];
				cube[UP][i][0] = cube[FRONT][i][0];
				cube[FRONT][i][0] = cube[DOWN][i][0];
				cube[DOWN][i][0] = cube[BACK][i][0];
				cube[BACK][i][0] = tmp;
			}
	}
	else if (side == RIGHT)
	{
		if (dir)
			for (int i = 0; i < 3; i++)
			{
				tmp = cube[UP][i][2];
				cube[UP][i][2] = cube[FRONT][i][2];
				cube[FRONT][i][2] = cube[DOWN][i][2];
				cube[DOWN][i][2] = cube[BACK][i][2];
				cube[BACK][i][2] = tmp;
			}
		else
			for (int i = 0; i < 3; i++)
			{
				tmp = cube[UP][i][2];
				cube[UP][i][2] = cube[BACK][i][2];
				cube[BACK][i][2] = cube[DOWN][i][2];
				cube[DOWN][i][2] = cube[FRONT][i][2];
				cube[FRONT][i][2] = tmp;
			}
	}
}



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int n;
		cin >> n;
		initcube();
		while (n--)
		{
			char side, dir;
			cin >> side>> dir;
			if (side == 'F') rotateSide(FRONT, dir == '+');
			else if (side == 'B') rotateSide(BACK, dir == '+');
			else if (side == 'U') rotateSide(UP, dir == '+');
			else if (side == 'D') rotateSide(DOWN, dir == '+');
			else if (side == 'L') rotateSide(LEFT, dir == '+');
			else if (side == 'R')rotateSide(RIGHT, dir == '+');
			
		}
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++)
				cout << cube[UP][i][j];
			cout << '\n';
		}
	}
	
}