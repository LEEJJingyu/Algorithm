#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <tuple>
#include <algorithm>
#include <cmath>
#include <string>
#include <climits>
using namespace std;
int N, M, K;

int board[50][50];
vector<tuple<int, int, int>> rotation;
int mn= 5000;
bool isused[6] = {0,};
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
void func(int k)
{
    if (k == K)
    {
        for (int i = 0; i < N; i++) {
            int t = 0;
            for (int j = 0; j < M; j++)
            {
                t += board[i][j];
            }
            if (mn > t)
                mn = t;
        }
        return;
    }
    for (int i = 0; i < K; i++)
    {
        if (!isused[i])
        {
            int x, y, size;
            tie(x, y, size) = rotation[i];
            for (int s = 1; s <= size; s++)
            {
                int sx = x - s;
                int sy = y - s;
                int t = board[sx][sy];
                for (int dir = 0; dir < 4; dir++)
                {
                    for (int j = 0; j < s * 2; j++)
                    {
                        int px = sx, py = sy;
                        sx += dx[dir>1?1-dir%2+2: 1 - dir % 2], sy += dy[dir > 1 ? 1 - dir % 2 + 2 : 1 - dir % 2];
                        board[px][py] = board[sx][sy];
                    }
                }
                board[sx][sy + 1] = t;
            }
            isused[i] = true;
            func(k + 1);
            isused[i] = false;
            for (int s = 1; s <= size; s++)
            {
                int sx = x - s;
                int sy = y - s;
                int t = board[sx][sy];
                for (int dir = 0; dir < 4; dir++)
                {
                    for (int j = 0; j < s * 2; j++)
                    {
                        int px = sx, py = sy;
                        sx += dx[dir], sy += dy[dir];
                        board[px][py] = board[sx][sy];
                    }
                }
                board[sx+1][sy] = t;
            }
        }
    }

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M >> K;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> board[i][j];
    for (int i = 0; i < K; i++)
    {
        int x, y, size;
        cin >> x >> y >> size;
        rotation.push_back({x-1,y-1,size});
    }
    func(0);
    cout << mn;
}