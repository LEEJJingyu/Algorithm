#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <queue>
#include <cstring>
#include <list>
using namespace std;

string s1;
string s2;
int arr[1002][1002] = {0,};
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> s1 >> s2;
	for (int i = 1; i <= s1.length(); i++)
		for (int j = 1; j <= s2.length(); j++)
		{
			if (s1[i-1] == s2[j-1])arr[i][j] = arr[i - 1][j - 1] + 1;
			else arr[i][j] = max(arr[i - 1][j], arr[i][j - 1]);
		}
	cout << arr[s1.length()][s2.length()];
}


