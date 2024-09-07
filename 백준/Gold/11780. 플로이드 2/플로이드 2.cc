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

int N;
int M;
int arr[101][101];
int arr2[101][101];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	for(int i=1;i<=N;i++)
		fill(arr[i]+1, arr[i]+1 + N, 1e9);
	for (int i = 0; i < M; i++)
	{
		int u, v, cost;
		cin >> u>>v>> cost;
		arr[u][v] = min(cost,arr[u][v]);
		arr2[u][v] = v;
	}
	for (int k = 1; k <= N; k++)
	{
		for (int i = 1; i <= N; i++)
		{
			arr[i][i] = 0;
			for (int j = 1; j <= N; j++)
			{
				if (arr[i][j] > arr[i][k] + arr[k][j])
				{
					arr[i][j] = arr[i][k] + arr[k][j];
					arr2[i][j] = arr2[i][k];
				}
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (arr[i][j] == 1e9) cout << "0 ";
			else cout << arr[i][j] << ' ';
		}
		cout << '\n';
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (arr[i][j] == 0 || arr[i][j] == 1e9) {
				cout << "0\n";
				continue;
			}
			vector<int> path;
			int st = i;
			while (st != j) {
				path.push_back(st);
				st = arr2[st][j];
			}
			path.push_back(j);
			cout << path.size() << ' ';
			for (auto x : path) cout << x << ' ';
			cout << '\n';
		}
	}
}