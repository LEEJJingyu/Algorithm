#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <queue>
#include <cstring>
#include <list>
using namespace std;

int N;
int num[1001];
pair<int, int> arr[1001];

void func(int next)
{
	if (next == -1)
	{
		return;
	}
	func(arr[next].second);
	cout << num[next]<<' ';
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> num[i];
	memset(arr, 0, sizeof(arr));
	arr[1] = { 1,-1 };
	for (int i = 2; i <= N; i++)
	{
		for (int j = 1; j < i; j++)
		{
			if (num[i] > num[j])
				if (arr[j].first + 1 > arr[i].first) {
					arr[i].first = arr[j].first + 1;
					arr[i].second = j;
				}
		}
		if (arr[i].second == 0)
			arr[i] = { 1, -1 };
	}
	int mx = arr[N].first;
	int idx = N;
	for (int i =N-1;i>0;i--)
	{
		if (mx < arr[i].first)
		{
			mx = arr[i].first;
			idx = i;
		}
	}
	cout << arr[idx].first<<'\n';
	func(idx);
}