#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<stack>
#include<cmath>
#include<vector>
#include<queue>
#include<set>
#include<unordered_map>
#include<tuple>
using namespace std;

int V, E;
int arr[401][401];
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> V >> E;
    for (int i = 1; i <= V; i++) {
        fill(arr[i] + 1, arr[i] + V + 1, 1e9);
        arr[i][i] = 0;
    }
    for (int i = 0; i < E; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        arr[a][b] = c;
    }
    for (int k = 1; k <= V; k++)
        for (int i = 1; i <= V; i++)
            for (int j = 1; j <= V; j++)
                arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
    int mn = 1e9;
    for (int i = 1; i <= V; i++)
        for (int j = i + 1; j <= V; j++)
            mn = min(mn, arr[i][j] + arr[j][i]);
    if (mn >= 1e9)cout << -1;
    else cout << mn;
}