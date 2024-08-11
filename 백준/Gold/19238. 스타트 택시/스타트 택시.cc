#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <tuple>
#include <algorithm>
#include <cmath>
//현재 위치에서 최단거리가 가장 짧은 승객을 고른다.
//그런 승객이 여러 명이면 그중 행 번호가 가장 작은 승객을,
//그런 승객도 여러 명이면 그중 열 번호가 가장 작은 승객을 고른다.

using namespace std;

int N, M,K;
int board[20][20];
int dx[4] = { -1,0,0,1 };
int dy[4] = { 0,-1,1,0 };
vector<pair<int, int>> passener(1, {0,0});
queue<pair<int, int>> list;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M >> K;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> board[i][j];
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    for (int i = 1; i <= M; i++)
    {
        int x1, y1;
        cin >> x1 >> y1;
        board[x1 - 1][y1 - 1] = -i;
        cin >> x1 >> y1;
        passener.push_back({x1-1,y1-1});
    }
    while (true)
    {
        if (M == 0)break;
        queue<pair<int, int>> drive;
        int visited[20][20] = { 0, };
        int mn = -2;
        if (board[x][y] < 0)
        {
            list.push({ x,y });
            mn = 1;
        }
        else
        {
            drive.push({ x,y });
            visited[x][y] = 1;
        }
        while (!drive.empty())
        {
            pair<int, int> taxi = drive.front();
            drive.pop();
            if (mn == visited[taxi.first][taxi.second])
            {
                while (!drive.empty())
                    drive.pop();
                break;
            }
            for (int dir = 0; dir < 4; dir++)
            {
                int nx = taxi.first + dx[dir], ny = taxi.second + dy[dir];
                if (nx < 0 || ny < 0 || nx >= N || ny >= N || board[nx][ny] == 1 || visited[nx][ny])
                    continue;
                visited[nx][ny] = visited[taxi.first][taxi.second] + 1;
                if (board[nx][ny] != 0)
                {
                    mn = visited[nx][ny];
                    list.push({ nx,ny });
                }
                drive.push({ nx,ny });
            }
        }
        if (mn == -2)
        {
            cout << -1; return 0;
        }
        K -= mn - 1;
        if (K < 0) {
            cout << -1; return 0;
        }
        for (int i = 0; i < N; i++)
            fill(visited[i], visited[i] + N, 0);
        int mn_x=N, mn_y=N;
        while (!list.empty())
        {
            if (mn_x > list.front().first)
            {
                mn_x = list.front().first;
                mn_y = list.front().second;
            }
            else if (mn_x == list.front().first&&mn_y>list.front().second)
            {
                mn_y = list.front().second;
            }
            list.pop();
        }

        int obj = board[mn_x][mn_y];
        board[mn_x][mn_y] = 0;
        drive.push({mn_x,mn_y});
        visited[mn_x][mn_y] = 1;
        while (!drive.empty())
        {
            pair<int, int> taxi = drive.front();
            drive.pop();
            if (passener[-obj].first == taxi.first&& passener[-obj].second==taxi.second)
            {
                if (K < visited[taxi.first][taxi.second]-1)
                {
                    cout << -1;
                    return 0;
                }
                x = taxi.first;
                y = taxi.second;
                K += visited[taxi.first][taxi.second]-1;
                M--;
                break;
            }
            for (int dir = 0; dir < 4; dir++)
            {
                int nx = taxi.first + dx[dir], ny = taxi.second + dy[dir];
                if (nx < 0 || ny < 0 || nx >= N || ny >= N || board[nx][ny] ==1 || visited[nx][ny])
                    continue;
                visited[nx][ny] = visited[taxi.first][taxi.second] + 1;
                drive.push({ nx,ny });
            }
        }
        if (board[passener[-obj].first][passener[-obj].second] == obj)
        {
            cout << -1; return 0;
        }
    }
    cout << K;
}