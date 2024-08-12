#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <tuple>
#include <algorithm>
#include <cmath>
struct fireball
{
    int x, y, mass, vel, dir;
};

using namespace std;
int N, M, K;
int dx[8] = { -1,-1,0,1,1,1,0,-1 };
int dy[8] = { 0,1,1,1,0,-1,-1,-1 };
tuple<int, int, int, int, int> board[51][51]; //질량, 속도, 방향, 갯수
queue<fireball> spell;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M >> K;
    for (int i = 0; i < M; i++)
    {
        int r, c, m, s, d;
        cin >> r >> c >> m >> s >> d;
        spell.push({ r - 1,c - 1,m,s,d });
    }
    for (int timer = 0; timer < K; timer++)
    {
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                board[i][j] = { 0,0,0,0,0 };
        while (!spell.empty())
        {
            fireball cur = spell.front();
            spell.pop();
            cur.x = (cur.x + dx[cur.dir] * cur.vel) % N;
            cur.y = (cur.y + dy[cur.dir] * cur.vel) % N;

            if (cur.x < 0) cur.x += N;
            if (cur.y < 0) cur.y += N;

            get<0>(board[cur.x][cur.y]) += cur.mass;
            get<1>(board[cur.x][cur.y]) += cur.vel;
            if (cur.dir % 2 == 1)
                get<2>(board[cur.x][cur.y])+=cur.dir+1;
            else
                get<3>(board[cur.x][cur.y])+=cur.dir+1;
            get<4>(board[cur.x][cur.y])++;
        }
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
            {
                int mass, vel, odd, even, num;
                tie(mass, vel, odd, even, num) = board[i][j];
                if (num > 1)
                {
                    
                    if ((mass / 5) == 0)continue;
                    if (odd == 0 || even == 0)
                    {
                        for (int dir = 0; dir < 4; dir++)
                            spell.push({ i,j , mass / 5,vel / num,dir * 2 });
                    }
                    else
                    {
                        for (int dir = 0; dir < 4; dir++)
                            spell.push({ i ,j, mass / 5,vel / num,dir * 2 + 1 });
                    }
                }
                else if (num== 1)
                {
                    spell.push({ i, j, mass, vel, odd+even-1 });
                }
            }
    }
    int ans = 0;
    while (!spell.empty())
    {
        ans += spell.front().mass;
        spell.pop();
    }
    cout << ans;
}

