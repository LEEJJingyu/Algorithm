#include <iostream>
#include <cstring>
using namespace std;

int N;
int cnt = 0;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int t;
		cin >> t;
		int n = 2;
		for (; n <= 32; n++)
			if (n * n > t && (n - 1) * (n - 1) <= t)
				break;
		while (n-->1)
		{
			if (t % n == 0)
				break;
		}
		if (n == 1&&t!=1)
			cnt++;
	}
	cout << cnt;
}