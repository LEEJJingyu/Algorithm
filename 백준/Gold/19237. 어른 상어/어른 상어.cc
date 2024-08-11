#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <tuple>
#include <algorithm>
#include <cmath>

struct Shark
{
    int x, y,dir_num;
    int dir[4][4];//up, down, left, right
};


using namespace std;
int N, M,K;
int num;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int timer = 0;
vector<vector<pair<int, int>>> board(20, vector<pair<int, int>>(20, {0,0}));
bool visited[20][20] = { 0, };
vector<Shark> sharkes(401);
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M >> K;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            int t = 0;
            cin >> t;

            if (t != 0) {
                sharkes[t].x = i; sharkes[t].y = j;
                board[i][j] = {t,K};
            }
        }
    num = M;
    for (int i = 1; i <= M; i++)
    {
        cin >> sharkes[i].dir_num;
        sharkes[i].dir_num--;
    }
    for (int i = 1; i <= M; i++)
    {
        for (int j = 0; j < 4; j++)
            for (int k = 0; k < 4; k++) {
                cin >> sharkes[i].dir[j][k];
                sharkes[i].dir[j][k]--;
            }
    }
    
    for (int timer = 1; timer < 1001; timer++)
    {
        for (int i = 0; i < N; i++)
            fill(visited[i], visited[i] + N, 0);
        for (int i = 1; i <= M; i++)
        {
            if (sharkes[i].x == -1)continue;
            int x = sharkes[i].x, y = sharkes[i].y;
            int dir = sharkes[i].dir_num;
            bool check=false;
            for (int j = 0; j < 4; j++)
            {
                int nx =x+ dx[sharkes[i].dir[dir][j]], ny =y+ dy[sharkes[i].dir[dir][j]];
                if (nx < 0 || ny < 0 || nx >= N || ny >= N||board[nx][ny].second>=timer)continue;
                sharkes[i].x = nx, sharkes[i].y = ny;
                sharkes[i].dir_num = sharkes[i].dir[dir][j];
                check = true;
                break;
            }
            if(!check)
                for (int j = 0; j < 4; j++)
                {
                    int nx = x + dx[sharkes[i].dir[dir][j]], ny = y + dy[sharkes[i].dir[dir][j]];
                    if (nx < 0 || ny < 0 || nx >= N || ny >= N || board[nx][ny].first!=i)continue;
                    sharkes[i].x = nx, sharkes[i].y = ny;
                    sharkes[i].dir_num = sharkes[i].dir[dir][j];
                    break;
                }
            if (visited[sharkes[i].x][sharkes[i].y])
            {
                sharkes[i].x = -1;
                sharkes[i].y = -1;
                num--;
            }
            else
            {
                visited[sharkes[i].x][sharkes[i].y] = true;
            }
        }
        for (int i = 1; i <= M; i++)
        {
            if (sharkes[i].x == -1)continue;
            board[sharkes[i].x][sharkes[i].y] = { i,timer + K};
        }
        if (num == 1)
        {
            cout << timer;
            return 0;
        }
    }
    cout << -1;
    
}