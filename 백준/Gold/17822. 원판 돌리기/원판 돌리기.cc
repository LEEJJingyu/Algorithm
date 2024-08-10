#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <tuple>
#include <algorithm>
#include <cmath>

using namespace std;
int N,M=0,T;
float cPlate[50][50];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

void rotatePlate(bool dir, int n,int i)
{
    float *arr=new float[M];
    for (int j = 0; j < M; j++)
        arr[j] = cPlate[i][j];
    if (dir) {
        for (int j = 0; j <M; j++)
            cPlate[i][j] = arr[(j + n + M) % M];
    }
    else {
        for (int j = 0; j < M; j++)
            cPlate[i][j] = arr[(j - n + M) % M];
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M >> T;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin>>cPlate[i][j];
    for (int i = 0; i < T; i++)
    {
        bool isch = false;
        int x, k;
        bool d;
        cin >> x >> d >> k;
        for (int j = 0; j < N; j++)
        {
            if ((j + 1) % x == 0)
            {
                rotatePlate(d,k,j);
            }
        }
        
        for (int j = 0; j < N; j++)
            for (int k = 0; k < M; k++)
            {
                if (cPlate[j][k] != 0)
                {
                    queue<pair<int, int>> q;
                    q.push({ j,k });
                    bool isSame = false;
                    while (!q.empty())
                    {
                        pair<int, int> cur = q.front();
                        q.pop();
                        for (int dir = 0; dir < 4; dir++)
                        {
                            int nx = cur.first + dx[dir], ny = cur.second + dy[dir];
                            if (nx < 0 || nx >= N)continue;
                            if (ny < 0)ny = M - 1;
                            else if (ny >= M)ny = 0;
                            if (nx == j && ny == k)continue;
                            if (cPlate[j][k] != cPlate[nx][ny]) continue;
                            cPlate[nx][ny] = 0;
                            q.push({ nx,ny });
                            isSame = true;
                            isch = true;
                        }
                    }
                    if (isSame)
                    {
                        cPlate[j][k] = 0;
                    }
                }
            }
        if (!isch)
        {
            float tmp = 0;
            int cnt = 0;
            for (int i = 0; i < N; i++)
                for (int j = 0; j < M; j++) {
                    tmp += cPlate[i][j];
                    if(cPlate[i][j]!=0)
                        cnt++;
                }

            for (int i = 0; i < N; i++)
                for (int j = 0; j < M; j++) {
                    if (cPlate[i][j] > (tmp / cnt))
                    {
                        cPlate[i][j]--;
                    }
                    else if (cPlate[i][j] < (tmp / cnt) && cPlate[i][j]!=0)
                    {
                        cPlate[i][j]++;
                    }
                }
        }
    }
    int ans = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            ans += cPlate[i][j];
    cout << ans;
}
