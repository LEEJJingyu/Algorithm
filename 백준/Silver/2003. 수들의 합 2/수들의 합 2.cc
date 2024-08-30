#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <list>
#include <algorithm>
using namespace std;

int N, M;
int A[10000];
int cnt = 0;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> A[i];
	int ed = 0;
	int sum = 0;
	for (int st = 0; st < N; st++)
	{
		while (ed < N && sum < M)
		{
			sum += A[ed];
			ed++;
		}
		if (sum < M)break;
		if (sum == M)
			cnt++;
		sum -= A[st];
	}
	cout << cnt;
}
