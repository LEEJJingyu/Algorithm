#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	while (true)
	{
		int a, b, c;
		cin >> a >> b >> c;
		bool ans=false;
		if (a + b + c == 0)
			break;
		if (a * a == b * b + c * c|| b * b == a * a + c * c|| c * c == a * a + b * b)
			ans = true;
		cout <<( ans ? "right" : "wrong") << '\n';
	}
}