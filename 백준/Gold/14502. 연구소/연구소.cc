#include<iostream>
#include<queue>
using namespace std;
int N, M;
int board[8][8];
int temp_board[8][8];
int mx = 0;
int bl = 3;
vector<pair<int, int>> empty_board;
vector<pair<int, int>> virus;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

int bfs()
{
    int n = 0;
    queue<pair<int, int>> q;
    for (pair<int, int> i : virus)
    {
        n++;
        q.push(i);
    }
    while (!q.empty())
    {
        pair<int,int> cur = q.front();
        q.pop();
        if (N * M - n - bl == mx)return 0;
        for (int i = 0; i < 4; i++)
        {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if (nx < 0 || ny < 0 || nx >= N || ny >= M)
                continue;
            if (temp_board[nx][ny] != 0)
                continue;
            n++;
            temp_board[nx][ny] = 2;
            q.push({ nx,ny });
        }
    }
    return N * M - n - bl;
}
void func(int start, int k)
{
    if (k == 3)
    {
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                temp_board[i][j] = board[i][j];
        int val = bfs();
        if (val > mx)
            mx = val;
        return;
    }
    for (int i = start; i < empty_board.size(); i++) {
        int nx = empty_board[i].first;
        int ny = empty_board[i].second;
        board[nx][ny] = 1;
        func(i+1,k + 1);
        board[nx][ny] = 0;
    }
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
            if (board[i][j] == 1) {
                bl++;
            }
            else if (board[i][j] == 2) {
                virus.push_back({ i,j });
            }
            else
            {
                empty_board.push_back({ i,j });
            }
        }
    func(0,0);
    cout << mx;
}
