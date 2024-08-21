#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <queue>
#include <cstring>
#include <list>
using namespace std;

int N,M;
int arr[41];
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	arr[0] = 1;
	arr[1] = 1;
	for (int i = 2; i <= 40; i++)
		arr[i] = arr[i - 1] + arr[i - 2];
	cin >> N>>M;
	int st = 0;
	int ans = 1;
	for(int i=0;i<M;i++)
	{
		int t;
		cin >> t;
		ans *= arr[t-st-1];
		st = t;
	}
	ans *= arr[N - st];
	cout << ans;
}
