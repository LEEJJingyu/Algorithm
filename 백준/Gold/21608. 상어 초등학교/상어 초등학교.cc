#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <cmath>
using namespace std;
int N;
int board[20][20] = {0,};
vector<vector<int>> students(401);
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int ans = 0;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N * N; i++)
    {
        int n;
        cin >> n;
        for (int j = 0; j < 4; j++)
        {
            int t;
            cin >> t;
            students[n].push_back(t);
        }
        int bx=0, by=0;
        int mxhope=-1, mxemp=-1;
        for (int x = 0; x < N; x++)
            for (int y = 0; y < N; y++)
                if (board[x][y] == 0)
                {
                    int hope = 0;
                    int emp = 0;
                    for (int dir = 0; dir < 4; dir++)
                    {
                        int nx = x + dx[dir], ny = y + dy[dir];
                        if (nx < 0 || ny < 0 || nx >= N || ny >= N)continue;
                        for (int num : students[n])
                            if (board[nx][ny] == num) {
                                hope++;
                                break;
                            }
                        if (board[nx][ny] == 0)
                            emp++;
                    }
                    if (mxhope < hope)
                        mxhope = hope, mxemp = emp, bx = x, by = y;
                    else if (mxhope == hope) {
                        if(mxemp < emp)
                            mxhope = hope, mxemp = emp, bx = x, by = y;
                        else if (mxemp == emp)
                        {
                            if (bx > x)
                                mxhope = hope, mxemp = emp, bx = x, by = y;
                            else if (bx == x)
                                if (by > y)
                                    mxhope = hope, mxemp = emp, bx = x, by = y;
                        }
                    }
                }
        board[bx][by] = n;
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
        {
            int hope = 0;
            for (int dir = 0; dir < 4; dir++)
            {
                int nx = i + dx[dir], ny = j + dy[dir];
                if (nx < 0 || ny < 0 || nx >= N || ny >= N)continue;
                for (int num : students[board[i][j]])
                    if (num == board[nx][ny])
                    {
                        hope++;
                        break;
                    }
            }
            ans += pow(10, hope-1);
        }
    }

    cout << ans;
}
