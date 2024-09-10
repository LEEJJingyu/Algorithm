#include<algorithm>
#include<iostream>
#include<vector>
#include<queue>
#include<tuple>
using namespace std;

int N;
int arr1[200001];
int arr2[200001];

vector<int> fail()
{
	vector<int> p(N + 1);
	int t = 0;
	for (int i = 1; i < N; i++)
	{
		while (t > 0 && arr2[i] != arr2[t])t = p[t - 1];
		if (arr2[i] == arr2[t])p[i] = ++t;
	}
	return p;
}

bool func()
{
	vector<int> p = fail();
	int t = 0;
	for (int i = 0; i < 2*N; i++)
	{
		int ci = i % N;
		while (t > 0 && arr2[t] != arr1[ci])t = p[t - 1];
		if (arr2[t] == arr1[ci])t++;
		if (t == N)return 1;
	}
	return 0;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr1[i];
	for (int i = 0; i < N; i++)
		cin >> arr2[i];
	sort(arr1, arr1 + N);
	sort(arr2, arr2 + N);
	arr1[N] = arr1[0] + 360000;
	arr2[N] = arr2[0] + 360000;
	for (int i = 0; i < N; i++)
	{
		arr1[i] = arr1[i + 1] - arr1[i];
		arr2[i] = arr2[i + 1] - arr2[i];
	}
	if (func())cout << "possible\n";
	else cout << "impossible\n";
}
