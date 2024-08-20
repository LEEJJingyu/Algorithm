#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <queue>
#include <cstring>
using namespace std;
int N;
int arr[1000][3];
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int j = 0; j < 3; j++)
		cin >> arr[0][j];
	for (int i = 1; i < N; i++)
	{
		for(int j=0;j<3;j++)
			cin >> arr[i][j];
		for (int j = 0; j < 3; j++)
			arr[i][j] = min(arr[i - 1][(j+1)%3], arr[i - 1][(j + 2) % 3]) + arr[i][j];

	}
	cout << min(min(arr[N - 1][0], arr[N - 1][1]), arr[N - 1][2]);
}