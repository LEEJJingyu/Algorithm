#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;

long long N, ans;


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	ans = N;
	for (long long i = 2; i * i <= N; i++) {
		if (N % i != 0) continue;
		ans -= ans / i;
		while (N % i == 0) N /= i;
	}

	if (N > 1) ans -= ans / N;
	cout << ans;
}