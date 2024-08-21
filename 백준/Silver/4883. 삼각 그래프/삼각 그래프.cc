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
int t;
int num[100001][3];
int arr[100001][3];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	t = 0;
	while (true)
	{
		t++;
		cin >> N;
		if (N == 0)break;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				cin >> num[i][j];
			}
		}
		arr[0][0] = (1<<30);
		arr[0][1] = num[0][1];
		arr[0][2] = num[0][2]+num[0][1];
		for (int i = 1; i < N; i++)
		{
			arr[i][0] = min(arr[i - 1][0], arr[i - 1][1])+num[i][0];
			arr[i][1] = min({ arr[i - 1][0],arr[i - 1][1],arr[i - 1][2],arr[i][0]}) + num[i][1];
			arr[i][2] = min({ arr[i - 1][1],arr[i - 1][2],arr[i][1]}) + num[i][2];
		}
		cout << t << '.' << ' ' << arr[N-1][1] << '\n';
	}
}
