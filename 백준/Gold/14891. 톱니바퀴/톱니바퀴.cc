#include <iostream>
using namespace std;
char gear[4][8];
int N;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 8; j++)
			cin >> gear[i][j];
	cin >> N;
	for (int i = 0; i< N; i++)
	{
		bool use[4] = { false,false,false,false };
		int n, r;
		cin >> n >> r;
		use[n - 1] = true;
		for (int left = n - 2; left >= 0; left--) {
			if (gear[left][2] != gear[left + 1][6])
				use[left] = true;
			else break;
		}
		for (int right = n; right < 4; right++) {
			if (gear[right - 1][2] != gear[right][6])
				use[right] = true;
			else break;
		}
		for (int j = 0; j < 4; j++)
		{
			if (use[j]) {
				int wr = (n - j + 3) % 2 ? -r : r;
				char temp[8];
				for (int k = 0; k < 8; k++) {
					temp[(k + wr + 8) % 8] = gear[j][k];
				}
				for (int k = 0; k < 8; k++) {
					gear[j][k] = temp[k];
				}
			}
		}
	}
	int sm = 0;
	for (int i = 0; i < 4; i++)
	{
		sm += (gear[i][0]-'0')*(1<<i);
	}
	cout << sm;
}