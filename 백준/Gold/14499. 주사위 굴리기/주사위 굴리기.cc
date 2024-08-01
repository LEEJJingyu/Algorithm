#include <iostream>
using namespace std;
int N,M,x,y,K;
int dice[6] = { 0,0,0,0,0,0 };// 오른 위 앞 왼 아래 뒤
int map[20][20];
int dx[4] = {0,0,-1,1}; 
int dy[4] = {1,-1,0,0};

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M >> x >> y >> K;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> map[i][j];
	int cur = 4;
	int side = 0;
	int front = 2;
	for (int i = 0; i < K; i++)
	{
		int com;
		cin >> com;
		com--;
		int nx = x + dx[com];
		int ny = y + dy[com];
		if (nx < 0 || ny < 0 || nx >= N || ny >= M)
			continue;
		int temp;
		switch (com)
		{
		case 0:
			temp = cur;
			cur = side;
			side = (temp + 3) % 6;
			break;
		case 1:
			temp = cur;
			cur = (side + 3) % 6;
			side = temp;
			break;
		case 2:
			temp = cur;
			cur = (front + 3) % 6;
			front = temp;
			break;
		case 3:
			temp = cur;
			cur = front;
			front = (temp + 3) % 6;
			break;
		}

		if (map[nx][ny] == 0)
		{
			map[nx][ny] = dice[cur];
		}
		else
		{
			dice[cur] = map[nx][ny];
			map[nx][ny] = 0;
		}
		cout << dice[(cur + 3) % 6]<<'\n';

		x = nx;
		y = ny;
	}
}