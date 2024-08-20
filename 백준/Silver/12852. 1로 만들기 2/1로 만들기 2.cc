#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <queue>
#include <cstring>
using namespace std;
pair<int,int> arr[1000001];
int N;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	memset(arr, 0, sizeof(arr));
	cin >> N;
	arr[1] = {0,-1};
	for (int i = 2; i <= N; i++)
	{
		if (arr[i].first == 0||arr[i].first>arr[i-1].first+1) {
			arr[i].first = arr[i-1].first + 1;
			arr[i].second = i - 1;
		}
		if (i % 2 == 0)
			if (arr[i].first > arr[i / 2].first + 1) {
				arr[i].first = arr[i / 2].first + 1;
				arr[i].second = i / 2;
			}
		if (i % 3 == 0)
			if (arr[i].first > arr[i / 3].first + 1) {
				arr[i].first = arr[i / 3].first + 1;
				arr[i].second = i / 3;
			}
	}
	cout << arr[N].first << '\n';
	int next=N;
	while (next != -1)
	{
		cout << next << ' ';
		next = arr[next].second;
	}
}