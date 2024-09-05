#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include<unordered_map>
#include<map>
#include<set>
using namespace std;


int N;
priority_queue<int> maxq;
priority_queue<int, vector<int>, greater<int>> minq;
int mx=0, mn=0;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int t;
		cin >> t;
		if (maxq.empty() || maxq.top() >= t) {
			mn++;
			maxq.push(t);
		}
		else {
			mx++;
			minq.push(t);
		}
		while (mn - mx!=1&& mn-mx != 0)
		{
			if (mn>=mx)
			{
				minq.push(maxq.top());
				maxq.pop();
				mx++;
				mn--;
			}
			else {
				maxq.push(minq.top());
				minq.pop();
				mn++;
				mx--;
			}
		}
		cout<<maxq.top()<<'\n';
	}
}