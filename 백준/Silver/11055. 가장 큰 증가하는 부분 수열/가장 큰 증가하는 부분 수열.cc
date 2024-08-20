#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <queue>
#include <cstring>
#include <list>
using namespace std;

int mx = 0;
int num[1000];
int arr[1000];
int N;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> num[i];
		arr[i] = num[i];
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (num[j] < num[i]) arr[i] = max(arr[i], arr[j] + num[i]);
		}
		mx = max(arr[i], mx);
	}
	cout << mx;
}