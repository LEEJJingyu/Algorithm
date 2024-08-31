#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <list>
#include <algorithm>
#include <unordered_map>
using namespace std;
int N;
int snowBall[600];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> snowBall[i];
	sort(snowBall, snowBall + N);
	int mn = 1e9*2;
	for (int st1=0; st1 < N; st1++)
	{
		for (int ed1 = st1 + 3; ed1 < N; ed1++)
		{
			int st2 = st1 + 1, ed2 = ed1-1;
			int snowMan1 = snowBall[st1] + snowBall[ed1];
			int snowMan2 = snowBall[ed2] + snowBall[st2];
			while (ed2>st2) {
				snowMan2 = snowBall[ed2] + snowBall[st2];
				if (snowMan1 > snowMan2)
					st2++;
				else if (snowMan1 < snowMan2)
					ed2--;
				else
				{
					cout << 0;
					return 0;
				}
				mn = min(mn, abs(snowMan2 - snowMan1));
			}
		}
	}
	cout << mn;
}