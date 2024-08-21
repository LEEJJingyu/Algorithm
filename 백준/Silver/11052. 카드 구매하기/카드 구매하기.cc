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
int arr[1001] = {0,};
int num[1001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> num[i];
	}
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			arr[i] = max(arr[i - j] + num[j], arr[i]);
		}
	}
	cout << arr[N];
}
