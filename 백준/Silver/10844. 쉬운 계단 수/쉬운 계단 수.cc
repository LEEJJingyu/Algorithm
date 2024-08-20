#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <queue>
#include <cstring>
#include <list>
using namespace std;

int arr[101][10];
int N;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	arr[1][0] = 0;
	for (int i = 1; i <= 9; i++)
		arr[1][i] = 1;
	cin >> N;

	for (int i = 2; i <= N; i++)
	{
		arr[i][0] = arr[i - 1][1];
		for (int j = 1; j < 9; j++)
			arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j + 1];
		arr[i][9] = arr[i - 1][8];

		for (int j = 0; j < 10; j++)
			arr[i][j] %= 1000000000;

	}
	int ans = 0;
	for (int i = 0; i < 10; i++) {
		ans += arr[N][i];
		ans %= 1000000000;
	}
	
	cout << ans;

}