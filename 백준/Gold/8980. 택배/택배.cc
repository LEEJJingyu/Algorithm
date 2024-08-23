#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<stack>
#include<cmath>
#include<vector>
#include<queue>
#include<set>
using namespace std;
int N, C,M;
int item[101][101] = {0,};
int arr[100];
int ans = 0;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >>C>> M;
    for (int i = 0; i < M; i++) {
        int st, ed, weight;
        cin >> st >> ed;
        cin >>item[st][ed];
    }
    for (int gap = 1; gap < N; gap++)
    {
        for (int i = 1; i <= N - gap; i++)
        {
            int mx = 0;
            for (int j = i; j < i + gap; j++)
                mx = max(arr[j], mx);
            mx = C-mx;
            if (mx == 0)continue;
            if (mx > item[i][i + gap]) {
                ans += item[i][i + gap];
                for (int j = i; j < i + gap; j++)
                    arr[j] += item[i][i + gap];
            }
            else if (mx <= item[i][i + gap]) {
                ans += mx;
                for (int j = i; j < i + gap; j++)
                    arr[j] += mx;
            }
        }
    }
    cout << ans;
}
