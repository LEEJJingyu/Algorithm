#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <tuple>
#include <algorithm>
#include <cmath>

using namespace std;

struct fish
{
    int x, y, dir;
};

int dx[8] = {-1,-1,0,1,1,1,0,-1};
int dy[8] = {0,-1,-1,-1,0,1,1,1};
int board[4][4];
fish fishes[16];
fish shark;
int mx =0;
bool check = true;

void func(int ans)
{
    mx = max(mx, ans);
    if (shark.x + dx[shark.dir] < 0 || shark.x + dx[shark.dir] >= 4 || shark.y + dy[shark.dir] < 0 || shark.y + dy[shark.dir] >= 4)
    {
        return;
    }
    
    
    int temp_board[4][4];
    //물고기 이동
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            temp_board[i][j] = board[i][j];
    fish temp_fishes[16];
    for (int i = 0; i < 16; i++)
    {
        temp_fishes[i] = fishes[i];
    }

    for (int i = 0; i < 16; i++)
    {
        if (fishes[i].dir == -1)continue;
        for (int dr = 0; dr < 8; dr++)
        {
            int nx = fishes[i].x + dx[(fishes[i].dir + dr) % 8];
            int ny = fishes[i].y + dy[(fishes[i].dir + dr) % 8];
            if (nx >= 0 && nx < 4 && ny >= 0 && ny < 4 && board[nx][ny] != 16)
            {
                int cx = fishes[i].x, cy = fishes[i].y;
                if (board[nx][ny] != -1)
                {
                    swap(fishes[board[nx][ny]].x, fishes[i].x);
                    swap(fishes[board[nx][ny]].y, fishes[i].y);
                }
                else
                {
                    fishes[i].x = nx;
                    fishes[i].y = ny;
                }
                fishes[i].dir = (fishes[i].dir + dr) % 8;
                swap(board[nx][ny], board[cx][cy]);
                break;
            }
        }
    }
    //상어 이동
    fish tmp = shark;
    board[shark.x][shark.y] = -1;
    for (int i = 1; i < 4; i++)
    {
        int nx = tmp.x + dx[tmp.dir] * i, ny = tmp.y + dy[tmp.dir] * i;
        if (nx < 0 || ny < 0 || nx >= 4 || ny >= 4 || board[nx][ny] == -1)
            continue;
        int fish_num = board[nx][ny];
        shark = fishes[fish_num];
        fishes[fish_num] = { -1,-1,-1 };
        board[nx][ny] = 16;
        func(ans + fish_num + 1);
        board[nx][ny] = fish_num;
        fishes[fish_num] = { nx,ny,shark.dir};
        
    }
    shark = tmp;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            board[i][j] = temp_board[i][j];
    for (int i = 0; i < 16; i++)
        fishes[i] = temp_fishes[i];
    

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
        {
            int n, dir;
            cin >> n >> dir;
            board[i][j] = n-1;
            fishes[n - 1] = { i,j,dir-1 };
        }
    shark = { 0,0,fishes[board[0][0]].dir };
    mx = board[0][0]+1;
    fishes[board[0][0]] = { -1,-1,-1 };
    board[0][0] = 16;
    func(mx);
    
    cout << mx;

}