#include <iostream>
using namespace std;
struct Truck
{
	int num, time;
};
int n, w, L;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> w >> L;
	int* truck = new int[n];
	Truck* cur = new Truck[n];
	for (int i = 0; i < n; i++)cin >> truck[i];
	int sm = 0;
	int f = 0,b = 0;
	int tm = 0,i = 0;
	while (i < n)
	{
		tm++;
		for (int j = b; j < f; j++)
		{
			if (cur[j].time >= w) {
				sm -= truck[cur[j].num];
				b++;
			}
			else
				cur[j].time++;
		}
		if (sm + truck[i] <= L)
		{
			sm += truck[i];
			cur[f++] = { i,1 };
			i++;
		}
	}
	cout << tm+w;
}