#include <iostream>
using namespace std;
int N, M;
pair<int, int> market[13];
pair<int,int> city[2500];
int dist[2500][13] = {0};
bool chicken[13] = { false };
int city_num=0, market_num=0;
int mn = 150000;

int calculate()
{
    int sm = 0;
    for (int i = 0; i < city_num; i++)
    {
        int mn_r = 100;
        for (int j = 0; j < 13; j++)
        {
            if (chicken[j]) {
                mn_r = min(mn_r, dist[i][j]);
            }
            
        }
        sm += mn_r;
    }
    return sm;
}

void closure(int k,int n)
{
    if (k == M)
    {
        mn = min(mn, calculate());
        return;
    }
    for(int i=n;i<market_num;i++)
        if (!chicken[i])
        {
            chicken[i] = true;
            closure(k + 1,i+1);
            chicken[i] = false;
        }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int n;
            cin >> n;
            if (n == 1)
                city[city_num++] = { i,j };
            else if (n == 2)
                market[market_num++] = { i,j };
        }
    }
    for (int i = 0; i < city_num; i++)
    {
        for (int j = 0; j < market_num; j++)
        {
            dist[i][j] = (market[j].first > city[i].first ? market[j].first - city[i].first : city[i].first - market[j].first);
            dist[i][j] += (market[j].second > city[i].second ? market[j].second - city[i].second : city[i].second - market[j].second);
        }
    }

    closure(0,0);
    cout << mn;
}