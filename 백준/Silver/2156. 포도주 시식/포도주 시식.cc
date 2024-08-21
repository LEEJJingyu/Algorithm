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
int arr[10001][3] = { 0, };
int num[10001];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> num[i];
	arr[0][0] = num[0];
	arr[0][1] = num[0];
	for (int i = 1; i < N; i++)
	{
		arr[i][0] = arr[i - 1][1] + num[i];
		arr[i][1] = arr[i - 1][2] + num[i];
		arr[i][2] = max({arr[i - 1][0], arr[i - 1][1], arr[i - 1][2]});
	}
	cout << max({ arr[N - 1][0],arr[N - 1][1],arr[N - 1][2] });
}