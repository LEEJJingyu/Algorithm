#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
int R, C, T;
int board[50][50];
int cleaner;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int cleanUp[4] = {3,0,1,2};
int cleanDown[4] = { 1,2,3,0};
queue<tuple<int, int, int>> q;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> R >> C >> T;
    
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++) {
            int tmp;
            cin >> tmp;
            if (tmp == -1)
                cleaner = i;
            else if (tmp > 0)
                q.push({ i,j,tmp });
        }
    while (T--)
    {
        for (int i = 0; i < R; i++)
            fill(board[i], board[i] + C, 0);
        while (!q.empty())
        {
            int x, y, dust;
            tie(x,y,dust)  = q.front();
            q.pop();
            int cnt = 0;
            for (int dir = 0; dir < 4; dir++)
            {
                int nx = x + dx[dir], ny = y + dy[dir];
                if (nx < 0 || ny < 0 || nx >= R || ny >= C||(ny==0&&(nx==cleaner||nx==cleaner-1))) { cnt++; continue; }
                board[nx][ny] += dust / 5;
            }
            board[x][y] += dust - (dust / 5) * (4 - cnt);
        }

        q.push({ cleaner,0,0 });
        int dir = 0;
        while (!q.empty())
        {
            int x, y, dust;
            tie(x, y, dust) = q.front();
            q.pop();
            if (x + dx[dir] < 0 || y + dy[dir] < 0 || x + dx[dir] >= R || y + dy[dir] >= C) { if (cleanDown[dir] == 0)continue; dir = cleanDown[dir]; }
            x += dx[dir];
            y += dy[dir];
            if (y == 0 && x == cleaner)break;
            q.push({ x,y,board[x][y] });
            board[x][y] = dust;
        }
        q.push({ cleaner - 1,0,0 });
        dir = 0;
        while (!q.empty())
        {
            int x, y, dust;
            tie(x, y, dust) = q.front();
            q.pop();
            if (x+ dx[dir] < 0 || y+ dy[dir] < 0 || x+ dx[dir] >= R || y+ dy[dir] >= C) { if (cleanUp[dir] == 0)continue; dir = cleanUp[dir]; }
            x += dx[dir];
            y += dy[dir];
            if (y == 0 && x == cleaner-1)break;
            q.push({ x,y,board[x][y] });
            board[x][y] = dust;
        }
        for (int i = 0; i < R; i++)
            for (int j = 0; j < C; j++)
                if (board[i][j] > 0)
                    q.push({ i,j,board[i][j] });
    }
    int ans = 0;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            ans += board[i][j];
        }
    }
    cout << ans;

}
