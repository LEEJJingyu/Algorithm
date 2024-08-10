#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>
#include <cmath>
using namespace std;
int dice[10];
int board[] = {
    2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40,0, //0~20
    13,16,19, //21
    22,24, //24
    28,27,26, //26
    25,30,35 //29
};
int mx = 0;
bool visited[32] = { 0, };
int token[4] = { -1,-1,-1,-1 };

int pos_ch(int n1, int n2)
{
    if (n1 == 4)
    {
        if (n2 < 4)
            return 21 + n2 - 1;
        else
            return 28 + n2 - 3;
    }
    else if (n1 == 9)
    {
        if (n2 < 3)
            return 24 + n2 - 1;
        else
            return 28 + n2 - 2;
    }
    else if (n1 == 14)
    {
        return 26 + n2 - 1;
    }
    else if (n1 >= 21 && n1 <= 23)
    {
        if ((n1 + n2) % 21 < 3)
            return n1 + n2;
        else if ((n1 + n2) % 21 < 6)
            return n1 + n2 + 5;
        else
            return n1 + n2 - 8;
    }
    else if (n1 >= 24 && n1 <= 25)
    {
        if ((n1 + n2) % 24 < 2)
            return n1 + n2;
        else if ((n1 + n2) % 24 < 5)
            return n1 + n2 + 3;
        else
            return n1 + n2 - 10;
    }
    else if (n1 >= 26)
    {
        if ((n1 + n2) % 26 < 6)
            return n1 + n2;
        else if ((n1 + n2) % 26 < 8)
            return n1 + n2 - 13;
        else
            return 20;
    }
    else
    {
        if (n1 + n2 > 20)
            return 20;
        else
            return n1 + n2;
    }
}

void func(int k, int score)
{
    if (k == 10) {
        mx = max(mx, score);
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        if (visited[pos_ch(token[i], dice[k])] && pos_ch(token[i], dice[k]) != 20)continue;
        int t = token[i];
        if (t != -1)visited[token[i]] = false;
        token[i] = pos_ch(token[i], dice[k]);
        visited[token[i]] = true;
        func(k + 1, board[token[i]] + score);
        visited[token[i]] = false;
        token[i] = t;
        if (t != -1)visited[t] = true;
    }
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 0; i < 10; i++)
        cin >> dice[i];
    func(0, 0);
    cout << mx;
}
