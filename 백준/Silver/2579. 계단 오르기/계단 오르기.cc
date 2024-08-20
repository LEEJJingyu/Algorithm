#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <queue>
#include <cstring>
using namespace std;

int stair[300];
int dist[300][2];
int N;
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> stair[i];
	}
	if (N == 1) {
		cout << stair[0];
		return 0;
	}
	dist[0][0] = stair[0];
	dist[0][1] = 0;
	dist[1][0] = stair[1];
	dist[1][1] = stair[0] + stair[1];
	for (int i = 2; i < N; i++) {
		dist[i][0] = max(dist[i - 2][0], dist[i - 2][1]) + stair[i];
		dist[i][1] = dist[i - 1][0] + stair[i];
	}
	cout << max(dist[N-1][0], dist[N-1][1]);
}