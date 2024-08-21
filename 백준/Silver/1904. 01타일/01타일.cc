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
int arr[1000001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	arr[0] = 1;
	arr[1] = 2;
	for (int i = 2; i < N; i++)
	{
		arr[i] = arr[i - 1] + arr[i - 2];
		arr[i] %= 15746;
	}
	cout << arr[N - 1];
}
