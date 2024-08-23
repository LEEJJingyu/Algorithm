#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
int N;
int cal[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
pair<int,int> flower[13][32];
pair<int, int> cur = {3,1};
pair<int, int> pre = { 1,0 };
int cnt = 0;
bool func(pair<int,int> day)
{
    pre = cur;
    pair<int, int> mx = day;
    for (int m = cur.first; m >= day.first; m--)
    {
        int st = (m == cur.first ? cur.second : cal[m]);
        int ed = (m == day.first ? day.second + 1 : 1);
        for (int d = st; d >= ed; d--)
        {
            if (flower[m][d].first > mx.first)
                mx = flower[m][d];
            else if (flower[m][d].first == mx.first && flower[m][d].second > mx.second)
                mx = flower[m][d];
        }
    }
    if(mx!=day)
    {
        cur = mx;
        cnt++;
        return false;
    }
    return true;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    memset(flower, 0, sizeof(flower));
    for (int i = 0; i < N; i++)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if (flower[x1][y1].first < x2)
            flower[x1][y1] = { x2,y2 };
        else if (flower[x1][y1].first == x2 && flower[x1][y1].second < y2)
            flower[x1][y1].second = y2;
    }
    while (true)
    {
        if (func(pre)) {
            cout << 0;
            return 0;
        }
        if (cur.first == 12)
            break;
    }

    cout << cnt;

}
