#include <iostream>
using namespace std;
int N, K;
int L;
pair<int, int> tail = {0,0};
int ln=1;
int tm = 0;
int d = 0;
int dt = 0;
int tail_t = 0;
pair<int, char> t_t[100];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int board[100][100] = { {0,} , };

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	cin >> K;
	for (int i = 0; i < K; i++)
	{
		int x, y;
		cin >> x >> y;
		board[x-1][y-1] = 1;
	}
	cin >> L;
	int x = 0;
	int y = 0;
	bool isend = false;
	for (int i = 0; i < L+1; i++)
	{
		int t=0;
		char dir=' ';
		if (i != L) {
			cin >> t >> dir;
			t_t[i] = { t,dir };
		}
		while (true)
		{
			x += dx[d];
			y += dy[d];
			if (x < 0 || y < 0 || x >= N || y >= N || board[x][y]==-1)
			{
				isend = true;
				break;
			}
			if (board[x][y] == 1) {
				ln++;
			}
			else {
				board[tail.first][tail.second] = 0;
				if (t_t[tail_t].first == tm - ln + 1)
				{
					dt = t_t[tail_t].second == 'D' ? (dt + 1) % 4 : (dt + 3) % 4;
					tail_t++;
				}
				tail = { tail.first + dx[dt],tail.second + dy[dt] };
			}
			tm++;
			board[x][y] = -1;
			if (tm == t)
			{
				break;
			}
		}
		if (isend)
		{
			break;
		}
		d = dir == 'D' ? (d + 1) % 4 : (d + 3) % 4;
		
	}
	cout << tm+1;
	
}