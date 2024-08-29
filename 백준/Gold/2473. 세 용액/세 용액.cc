#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <list>
#include <algorithm>
using namespace std;
int N;
long long arr[5000];
long long ans[3] = { 3000000000, 3000000000, 3000000000 };
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	sort(arr, arr + N);
	for (int i = 0; i < N; i++)
		for (int j = i + 1; j < N; j++) {
			int idx = lower_bound(arr + j, arr + N, -arr[i] - arr[j]) - arr;
			for (int k = -2; k <= 2; k++) {
				if (idx + k == i || idx + k == j) continue;
				if (idx + k < 0 || idx + k >= N) continue;
				if (abs(ans[0] + ans[1] + ans[2]) > abs(arr[i] + arr[j] + arr[idx + k])) 
					ans[0]= arr[i], ans[1]= arr[j], ans[2]=arr[idx + k];
			}
		}
	sort(ans, ans + 3);
	cout << ans[0] << " " << ans[1] << " " << ans[2];
}
