#include<iostream>
using namespace std;
int N, M;
int num[2001];
bool arr[2001][2001];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> num[i];
	}
	cin >> M;
	for (int i = 1; i <= N; i++)
	{
		arr[i][i] = true;
		if (num[i] == num[i - 1])arr[i - 1][i] = true;
	}
	for (int gap = 2; gap < N; gap++)
	{
		for (int i = 1; i <= N - gap; i++)
		{
			if (num[i] == num[i + gap] && arr[i+1][i + gap-1])
				arr[i][i + gap] = true;
		}
	}
	for (int i = 0; i < M; i++)
	{
		int s, e;
		cin >> s >> e;
		cout << arr[s][e] << '\n';
	}
}