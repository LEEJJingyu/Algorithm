#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<stack>
#include<cmath>
#include<vector>
#include<queue>
#include<set>
#include<tuple>
using namespace std;
int N, M;
vector<int> p(1001, -1);


int find(int x)
{
    if (p[x] < 0)return x;
    return p[x] = find(p[x]);
}
bool unionP(int u, int v)
{
    u = find(u), v = find(v);
    if (u == v)return 1;
    if (u < v)p[v] = u;
    else p[u] = v;
    return 0;
}
double func(double t)
{
    double ans = (double)((int)(t * 100 + 0.5)) / 100;
    return ans;
}

vector<tuple<double, int, int>> edge;
pair<long long, long long> pos[1001];
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed;
    cout.precision(2);
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
    {
        long long x, y;
        cin >> x >> y;
        pos[i] = { x,y };
    }
    int cnt = 0;
    for (int i = 0; i < M; i++)
    {
        int u, v;
        cin >> u >> v;
        if (!unionP(u, v))
            cnt++;
    }
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
        {
            if (i == j)continue;
            double t = sqrt((pos[i].first - pos[j].first) * (pos[i].first - pos[j].first) + (pos[i].second - pos[j].second) * (pos[i].second - pos[j].second));
            edge.push_back({ t,i,j });
        }
    sort(edge.begin(), edge.end());
    if (cnt >= N - 1) {
        cout << 0;
        return 0;
    }
    double sum = 0;
    for (int i = 0; i < edge.size(); i++)
    {
        double r; int u, v;
        tie(r, u, v) = edge[i];
        if (unionP(u, v))continue;
        sum += r;
        cnt++;
        if (cnt == N - 1)break;
    }
    cout << sum << '\n';
}