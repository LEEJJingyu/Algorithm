#include <iostream>
#include <cstring>
#include <queue>
#include <unordered_map>
#include <algorithm>

using namespace std;

int dist[12][12], w, h, dp[12][(1 << 12)], num, dx[4] = { -1,0,1,0 }, dy[4] = { 0,-1,0,1 };
pair<int, int> pos[11];
char board[20][20];
bool visited[20][20];

int tsp(int cur , int visit)
{
	if (visit == (1 << num) - 1)
	{
		return 0;
	}
	if (dp[cur][visit])return dp[cur][visit];
	dp[cur][visit] = 1e9;
	for (int i = 1; i < num; i++)
	{
		if (!dist[cur][i])continue;
		if (visit & (1 << i))continue;
		int tmp = tsp(i, visit | (1 << i));
		dp[cur][visit] = min(dp[cur][visit], tmp + dist[cur][i]);
	}
	return dp[cur][visit];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	while (true)
	{
		cin >> w >> h;
		if (w + h == 0)
			break;
		num = 1;
		memset(dist, 0, sizeof dist);
		queue<pair<pair<int,int>,int>> q;
		memset(visited, 0, sizeof visited);
		for (int i = 0; i < h; i++)
			for (int j = 0; j < w; j++) {
				cin >> board[i][j];
				if (board[i][j] == '*') {
					pos[num] = { i,j };
					board[i][j] = num++;
				}
				else if (board[i][j] == 'o') {
					q.push({ { i, j } ,0});
					board[i][j] = 0;
					visited[i][j] = true;
				}
			}
		for (int i = 0; i < num; i++) {
			while (!q.empty())
			{
				auto cur = q.front(); q.pop();
				for (int dir = 0; dir < 4; dir++)
				{
					int nx = cur.first.first + dx[dir], ny = cur.first.second + dy[dir];
					if (nx < 0 || ny < 0 || nx >= h || ny >= w || visited[nx][ny]||board[nx][ny]=='x')continue;
					visited[nx][ny] = true;
					if (board[nx][ny] != '.')
					{
						dist[i][board[nx][ny]] = cur.second+1;
					}
					q.push({ {nx,ny} ,cur.second + 1 });
				}
			}
			memset(visited, 0, sizeof visited);
			q.push({pos[i+1],0});
			visited[pos[i + 1].first][pos[i + 1].second] = true;
		}

		memset(dp, 0, sizeof dp);
		int ans = tsp(0, 1);
		if (ans == 1e9)
			ans = -1;
		cout << ans << '\n';
	}
	
}