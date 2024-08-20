#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <queue>
#include <cstring>
using namespace std;
int arr[1000];
int N;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	arr[0] = 1;
	arr[1] = 2;
	for (int i = 2; i < N; i++)
		arr[i] = arr[i - 1] % 10007 + arr[i - 2] % 10007;
	cout << arr[N - 1] % 10007;
}