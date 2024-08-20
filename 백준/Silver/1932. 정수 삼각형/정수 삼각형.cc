#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <queue>
#include <cstring>
using namespace std;

int arr[500][2] = {0,};
int N;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	cin >> arr[0][0];
	for (int i = 1; i < N; i++)
	{
		cin >> arr[0][i%2];
		arr[0][i % 2] += arr[0][1 - i % 2];
		for (int j = 1; j <= i; j++)
		{
			cin >> arr[j][i%2];
			arr[j][i % 2] += max(arr[j-1][1 - i % 2], arr[j][1 - i % 2]);
		}
	}
	int mx = arr[0][(N - 1) % 2];
	for (int i = 1; i < N; i++)
	{
		mx = max(mx, arr[i][(N - 1) % 2]);
	}
	cout << mx;
}