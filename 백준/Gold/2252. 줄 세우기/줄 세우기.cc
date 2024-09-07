#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <tuple>
#include <queue>
#include <cmath>
#include <set>
#include<ctime>
#include<stack>
#include <algorithm>
using namespace std;

int N,M;
vector<int> arr[32001];
int cnt[32001] = {0};
stack<int> s;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	int num = N;
	while (M--)
	{
		int a, b;
		cin >> a >> b;
		arr[b].push_back(a);
		cnt[a]++;
	}
	while (num > 0)
	{
		for (int i = 1; i <= N; i++)
		{
			if (cnt[i] == 0){
				num--;
				cnt[i] = -1;
				s.push(i);
				for (int nxt : arr[i])
					cnt[nxt]--;
			}
		}
	}
	while (!s.empty())
	{
		cout << s.top() << ' ';
		s.pop();
	}

}

