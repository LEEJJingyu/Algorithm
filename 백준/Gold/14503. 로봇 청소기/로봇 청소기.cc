#include <iostream>
using namespace std;
//
int board[50][50];
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
int N, M, dir;
int x, y;
int cnt = 1;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	cin >> x >> y>>dir;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> board[i][j];
	board[x][y] = -1;
	while (true)
	{
		bool isclean = true;
		for (int i = 0; i < 4; i++)
		{
			dir = (dir + 3) % 4;
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (nx < 0 || nx >= N || ny < 0 || ny >= M || board[nx][ny]!=0){
				continue;
			}
			x = nx;
			y = ny;
			board[x][y] = -1;
			cnt++;
			isclean = false;
			break;
		}
		if (isclean)
		{
			x += dx[(dir + 2) % 4];
			y += dy[(dir + 2) % 4];
			if (x < 0 || x >= N || y < 0 || y >= M || board[x][y]==1)
			{
				break;
			}
		}
	}
	cout << cnt;
	
}