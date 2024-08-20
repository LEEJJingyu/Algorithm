#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <queue>
#include <cstring>
using namespace std;
long long arr[91][2];
int N;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	arr[0][0] = 0;
	arr[0][1] = 1;

	cin >> N;
	for (int i = 1; i < N; i++) {
		arr[i][0] = arr[i - 1][0]+ arr[i - 1][1];
		arr[i][1] = arr[i - 1][0];
	}
	cout << arr[N - 1][0]+arr[N-1][1];
}