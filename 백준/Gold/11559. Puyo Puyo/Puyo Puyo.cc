#include <iostream>
#include <queue>
#include <vector>
using namespace std;
char map[6][12];
int cnt = 0;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };

void gravity() {
	for (int i = 0; i < 6; i++) {
		int empty = 0;
		for (int j = 0; j < 12; j++) {
			if (map[i][j] != '.') {
				map[i][empty++] = map[i][j];
			}
		}
		while (empty < 12) {
			map[i][empty++] = '.';
		}
	}
}


void BFS()
{
	bool temp[6][12];
	while (true)
	{
		bool ispang = false;
		for (int i = 0; i < 6; i++)
			for (int j = 0; j < 12; j++)
				temp[i][j] = false;
		for (int i = 0; i < 6; i++) {
			for (int j = 0; j < 12; j++) {
				if (map[i][j] != '.' && !temp[i][j]) {
					queue<pair<int, int>> q;
					vector<pair<int, int>> blocks;
					q.push({ i, j });
					temp[i][j] = true;
					blocks.push_back({ i, j });
					int con = 1;
					while (!q.empty()) {
						pair<int, int> cur = q.front();
						q.pop();
						for (int dir = 0; dir < 4; dir++) {
							int nx = cur.first + dx[dir];
							int ny = cur.second + dy[dir];
							if (nx < 0 || ny < 0 || nx >= 6 || ny >= 12) continue;
							if (temp[nx][ny] || map[nx][ny] != map[cur.first][cur.second]) continue;
							temp[nx][ny] = true;
							blocks.push_back({ nx, ny });
							con++;
							q.push({ nx, ny });
						}
					}
					if (con >= 4) {
						ispang = true;
						for (auto& b : blocks) {
							map[b.first][b.second] = '.';
						}
					}
				}
			}
		}
		gravity();
		if (!ispang)break;
		cnt++;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	for (int j = 11; j >= 0; j--)
		for (int i = 0; i < 6; i++) {
			cin >> map[i][j];
		}
	BFS();
	cout << cnt;

}