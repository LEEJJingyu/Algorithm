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
	arr[0] = 0;
	arr[1] = 1;
	cin >> N;
	for (int i = 2; i <= abs(N); i++)
	{
		arr[i] = arr[i - 1] + arr[i - 2];
		arr[i] %= 1000000000;
	}
	if (N == 0)
		cout << 0 << '\n';
	else if (N < 0 && N % 2 == 0)
		cout << -1 << '\n';
	else
		cout << 1 << '\n';
	cout << arr[abs(N)];
}
