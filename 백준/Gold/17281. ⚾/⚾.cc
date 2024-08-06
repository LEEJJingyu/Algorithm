#include <iostream>
using namespace std;
int N;
int bat[50][9];
int hitter[9] = { 0, };
bool isused[9] = { 0, };
int mx = 0;
void game()
{
    int cur=0;
    int out;
    int score=0;
    int hit;
    for (int i = 0; i < N; i++)
    {
        out = 0;
        hit = 0;
        while (out < 3)
        {
            switch (bat[i][hitter[cur]])
            {
            case 0:
                out++;
                break;
            case 1:
                hit=hit << 1;
                hit += 1;
                if (hit / (1 << 3))score++;
                hit %= (1 << 3);
                break;
            case 2:
                hit = hit << 2;
                hit +=2;
                if (hit / (1 << 4))score++;
                hit %= (1 << 4);
                if (hit / (1 << 3))score++;
                hit %= (1 << 3);
                break;
            case 3:
                hit = hit << 3;
                hit += 4;
                if (hit / (1 << 5))score++;
                hit %= (1 << 5);
                if (hit / (1 << 4))score++;
                hit %= (1 << 4);
                if (hit / (1 << 3))score++;
                hit %= (1 << 3);
                break;
            case 4:
                hit = hit << 4;
                hit += 8;
                if (hit / (1 << 6))score++;
                hit %= (1 << 6);
                if (hit / (1 << 5))score++;
                hit %= (1 << 5);
                if (hit / (1 << 4))score++;
                hit %= (1 << 4);
                if (hit / (1 << 3))score++;
                hit %= (1 << 3);
                break;
            }
            cur=cur==8?0:cur+1;
        }
    }
    if (score > mx)
        mx = score;
}

void func(int k)
{
    if (k == 9)
    {
        game();
        return;
    }
    if (k == 3) { func(k + 1); return; }
    for (int i = 0; i < 9; i++)
    {
        if (!isused[i])
        {
            isused[i] = true;
            hitter[k] = i;
            func(k + 1);
            isused[i] = false;
        }
    }

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < 9; j++)
            cin >> bat[i][j];
    hitter[3] = 0;
    isused[0] = true;
    func(0);
    cout << mx;
}