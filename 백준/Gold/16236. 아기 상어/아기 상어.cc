#include <iostream>
#include <queue>
using namespace std;
int N;
int board[20][20];
int sharkSize = 2;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };
int visited[20][20] = {0,};
int tm = 0;
pair<int, int> shark;
int feed;
int mn;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == 9) {
                shark = { i,j };
                board[i][j] = 0;
                visited[i][j] = 1;
            }
        }
    bool iscon = true;
    while (iscon) {
        queue<pair<int, int>> q;
        queue<pair<int, int>> fishes;
        mn = -1;
        if (iscon)
        {
            q.push(shark);
        }
        iscon = false;
        while (!q.empty())
        {
            pair<int,int> cur = q.front();
            q.pop();
            if (mn==visited[cur.first][cur.second])continue;
            for (int dir = 0; dir < 4; dir++)
            {
                int nx = cur.first + dx[dir];
                int ny = cur.second + dy[dir];
                if (nx < 0 || ny < 0 || nx >= N || ny >= N || board[nx][ny]>sharkSize || visited[nx][ny])continue;
                visited[nx][ny] = visited[cur.first][cur.second]+1;
                q.push({ nx,ny });
                if (board[nx][ny] < sharkSize&&board[nx][ny]!=0)
                {
                    mn = visited[nx][ny];
                    iscon = true;
                    fishes.push({ nx,ny });
                }
            }
        }
        pair<int, int> fish;
        int x = -50,y=-50;
        while (!fishes.empty())
        {
            pair<int,int> fish_t = fishes.front();
            fishes.pop();
            if (shark.first - fish_t.first > x|| shark.first - fish_t.first == x&&shark.second - fish_t.second >= y) {
                    fish = fish_t;
                    x = shark.first - fish_t.first;
                    y = shark.second - fish_t.second;
                }
        }
        if (iscon) {
            feed++;
            if (feed == sharkSize) { sharkSize++; feed = 0; }
            board[fish.first][fish.second] = 0;
            shark = { fish.first,fish.second };

            tm += visited[fish.first][fish.second] - 1;

            for (int i = 0; i < N; i++)
                fill(visited[i], visited[i] + N, 0);
            visited[fish.first][fish.second] = 1;
        }
    }
    cout << tm;
    

}
