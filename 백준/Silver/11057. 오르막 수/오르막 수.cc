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
int arr[1001][10] = {0,};
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int sum = 0;
	cin >> N;
	for (int i = 9; i >= 0; i--)
		arr[0][i] = 1;
	for (int k = 1; k < N; k++)
	{
		for (int i = 9; i >= 0; i--) {
			for(int j=0;j<=i;j++)
				arr[k][i] += arr[k-1][j];
			arr[k][i] %= 10007;
		}
	}
	for (int i = 0; i < 10; i++)
		sum += arr[N - 1][i];
	cout << sum%10007;

}
