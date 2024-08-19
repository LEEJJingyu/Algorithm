#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <queue>
#include <cstring>
using namespace std;

struct grade
{
	int korean, math, english;
	string name;
};

struct cmp
{
	bool operator()(grade a, grade b)
	{
		if (a.korean == b.korean)
		{
			if (a.english == b.english)
			{
				if (a.math == b.math)
				{
					return a.name > b.name;
				}
				else
					return a.math < b.math;
			}
			else
				return a.english > b.english;
		}
		else
			return a.korean < b.korean;
	}
};
int N;
priority_queue<grade,vector<grade>,cmp> v1;
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		string name;
		int a, b, c;
		cin >> name >> a >> b >> c;
		v1.push({a,c,b,name });
	}
	while (!v1.empty())
	{
		cout << v1.top().name << '\n'; v1.pop();
	}
}