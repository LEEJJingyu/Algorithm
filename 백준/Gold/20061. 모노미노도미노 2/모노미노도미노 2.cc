#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <tuple>
#include <algorithm>
#include <cmath>

using namespace std;
int blue[4][6] = { 0, };
int green[6][4] = { 0, };
int N;
int ans = 0;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int tc = 0; tc < N; tc++)
    {
        int t, x, y;
        cin >> t >> x >> y;
        if (t == 1)
        {
            int by = 5;
            for (int i = 2; i < 6; i++)
                if (blue[x][i]) { by = i-1; break; }
            blue[x][by] = 1;
            int gx = 5;
            for (int i = 2; i < 6; i++)
                if (green[i][y]) { gx = i-1; break; }
            green[gx][y] = 1;
        }
        else if (t == 2)
        {
            int by = 5;
            for (int i = 2; i < 6; i++)
                if (blue[x][i]) { by = i - 1; break; }
            blue[x][by] = 2;
            blue[x][by-1] = 2;
            int gx = 5;
            for (int i = 2; i < 6; i++)
                if (green[i][y]||green[i][y+1]) { gx = i - 1; break; }
            green[gx][y] = 3;
            green[gx][y+1] = 3;
        }
        else if (t == 3)
        {
            int by = 5;
            for (int i = 2; i < 6; i++)
                if (blue[x][i]|| blue[x+1][i]) { by = i - 1; break; }
            blue[x][by] = 3;
            blue[x+1][by] = 3;
            int gx = 5;
            for (int i = 2; i < 6; i++)
                if (green[i][y]) { gx = i - 1; break; }
            green[gx][y] = 2;
            green[gx-1][y] = 2;
        }
        bool istetris = false;
        for (int i = 2; i < 6; i++) {
            bool check = true;
            for (int j = 0; j < 4; j++)
            {
                check &= (blue[j][i] > 0);
            }
            if (check) {
                blue[0][i] = blue[1][i] = blue[2][i] = blue[3][i] = 0;
                ans++;
                for (int x = i-1; x >= 0; x--)
                    for (int y = 0; y < 4; y++)
                    {
                        swap(blue[y][x], blue[y][x+1]);
                    }
            }
        }
        istetris = false;
        for (int i = 2; i < 6; i++) {
            bool check = true;
            for (int j = 0; j < 4; j++)
            {
                check &= (green[i][j] > 0);
            }
            if (check) { 
                green[i][0] = green[i][1] = green[i][2] = green[i][3] = 0;
                ans++;
                for (int x = i-1; x >= 0; x--)
                    for (int y = 0; y < 4; y++)
                    {
                        swap(green[x][y], green[x + 1][y]);
                    }
            }
        }
        int line=0;
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 4; j++)
            {
                if (blue[j][i])
                {
                    line++;
                    break;
                }
            }
        if (line)
        {
            for (int i = 5-line; i >= 2-line; i--)
            {
                for (int j = 0; j < 4; j++)
                {
                    blue[j][i+line] = blue[j][i];
                }
            }
            for (int i = 2-line; i < 2; i++)
                for (int j = 0; j < 4; j++)
                    blue[j][i] = 0;
        }
        line = 0;
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 4; j++)
            {
                if (green[i][j])
                {
                    line++;
                    break;
                }
            }
        if (line)
        {
            for (int i = 5-line; i >= 2-line; i--)
            {
                for (int j = 0; j < 4; j++)
                {
                    green[i + line][j] = green[i][j];
                }
            }
            for (int i = 2-line; i<2; i++)
                for (int j = 0; j < 4; j++)
                    green[i][j] = 0;
        
        }
    }
    int total = 0;
    for(int i=0;i<4;i++)
        for (int j = 0; j < 4; j++)
        {
            if (blue[j][i + 2])
                total++;
            if (green[i + 2][j])
                total++;
        }
    cout << ans << '\n' << total;
}