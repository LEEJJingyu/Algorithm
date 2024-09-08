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

int N, M,K;
int arr[201][201];
int fr[201];
int mn = 1e9;

int func(int i)
{
    int mx = 0;
    for (int j = 0; j < K; j++)
    {
        if (mn < arr[fr[j]][i]+ arr[i][fr[j]]) {
            return -1;
        }
        mx = max(mx, arr[fr[j]][i] + arr[i][fr[j]]);
    }
    if (mx > 1e8)
        mx = 1e9;
    return mx;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
    {
        fill(arr[i] + 1, arr[i] + N + 1, 1e8);
        arr[i][i] = 0;
    }
    for (int i = 0; i < M; i++)
    {
        int u, v, cost;
        cin >> u >> v >> cost;
        arr[u][v] = cost;
    }
    cin >> K;
    for (int i = 0; i < K; i++)
    {
        cin >> fr[i];
    }
    for (int k = 1; k <= N; k++)
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++)
                arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);

    vector<int> mnN;
    for (int i = 1; i <= N; i++)
    {
        int t = func(i);
        if (t != -1) {
            if(mn==t)
                mnN.push_back(i);
            else {
                mn = t;
                mnN.clear();
                mnN.push_back(i);
            }
        }
    }
    for (int i : mnN)
        cout << i<<' ';
}