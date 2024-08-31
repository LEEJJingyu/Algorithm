#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <list>
#include <algorithm>
#include <unordered_map>
using namespace std;
int A, B;
int stick[1000001];
int mx = 0;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> A >> B;
	for (int i = 0; i < A; i++)
	{
		int st, ed;
		cin >> st >> ed;
		mx = max(ed, mx);
		for (int i = st; i < ed; i++)
		{
			stick[i]++;
		}
	}
	int ed = 0;
	long long sum = 0;
	int st = 0;
	for (; st < mx; st++)
	{
		while (sum < B&&ed<mx)
		{
			sum += stick[ed];
			ed++;
		}
		if (sum == B||ed==mx&&sum<B)
			break;
		sum -= stick[st];
	}
	if (sum == B)
		cout << st << ' ' << ed;
	else
		cout << 0 << ' ' << 0;
}