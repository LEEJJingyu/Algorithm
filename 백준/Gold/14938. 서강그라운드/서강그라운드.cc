#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <tuple>
#include <queue>
#include <cmath>
#include <set>
#include<ctime>
#include <algorithm>
using namespace std;

int n, m, r;
int arr[101][101];
int val[101];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> r;
	for (int i = 1; i <= n; i++) {
		fill(arr[i] + 1, arr[i] + n + 1, 1e9);
		cin >> val[i];
	}
	for (int i = 0; i < r; i++)
	{
		int u, v, cost;
		cin >> u >> v >> cost;
		arr[u][v] = cost;
		arr[v][u] = cost;
	}
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
		{
			arr[i][i] = 1;
			for (int j = 1; j <= n; j++)
				arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
		}
	int mx = 0;
	for (int i = 1; i <= n; i++)
	{
		int sum = 0;
		for (int j = 1; j <= n; j++)
		{
			if (m >= arr[i][j])
			{
				sum += val[j];
			}
		}
		mx = max(mx, sum);
	}
	cout << mx;
}
