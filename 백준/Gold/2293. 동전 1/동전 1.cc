#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <queue>
#include <cstring>
#include <list>
using namespace std;

int n, k;
int coin[100];
int arr[10001] = {0,};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> coin[i];
	}
	arr[0] = 1;
	for (int i = 0; i < n; i++)
		for (int j = coin[i]; j <= k; j++)
			arr[j]+=arr[j - coin[i]];
	cout << arr[k];
}