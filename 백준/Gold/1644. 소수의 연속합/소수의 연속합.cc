#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <list>
#include <algorithm>
using namespace std;


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N;
	int cnt = 0;
	cin >> N;
	vector<bool> state(N+1, true);
	vector<int> primes;
	for (int i = 2; i*i <= N; i++)
	{
		if (!state[i])continue;
		for (int j = i * i; j <= N; j += i)
			state[j] = false;
	}
	for (int i = 2; i <= N; i++)
		if(state[i])primes.push_back(i);
	int ed = 0;
	int sum = 0;
	for (int st = 0; st < primes.size(); st++)
	{
		while (ed < primes.size() && sum < N) {
			sum += primes[ed];
			ed++;
		}
		if (sum < N)break;
		if (sum == N) {
			cnt++;
		}
		sum -= primes[st];
	}
	cout << cnt;
}
