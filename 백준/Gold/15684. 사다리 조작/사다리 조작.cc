#include <iostream>
using namespace std;

int N, M, H;
int** ladder;
int mn = 4;

bool play_ladder()
{
    for (int i = 0; i < N; i++)
    {
        int x = i;
        for (int j = 0; j < H; j++)
        {
            switch (ladder[j][x])
            {
            case 1:
                x += 1;
                break;
            case 2:
                x -= 1;
                break;
            }
        }
        if (x != i)
            return false;
    }
    return true;
}

void func(int cnt, int x, int y)
{
    if (cnt >= mn) return;
    if (play_ladder())
    {
        mn = cnt;
        return;
    }
    if (cnt == 3)
    {
        return;
    }
    for (int i = x; i < H; i++)
    {
        for (int j = (i == x ? y : 0); j < N - 1; j++)
        {
            if (ladder[i][j] == 0 && ladder[i][j + 1] == 0)
            {
                ladder[i][j] = 1;
                ladder[i][j + 1] = 2;
                func(cnt + 1, i, j + 2);
                ladder[i][j] = 0;
                ladder[i][j + 1] = 0;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M >> H;
    ladder = new int* [H];
    for (int i = 0; i < H; i++)
    {
        ladder[i] = new int[N]();
    }

    for (int i = 0; i < M; i++)
    {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        ladder[x][y] = 1; //right
        ladder[x][y + 1] = 2; //left
    }
    func(0, 0, 0);
    cout << (mn == 4 ? -1 : mn);
}