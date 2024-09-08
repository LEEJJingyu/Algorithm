#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<stack>
#include<cmath>
#include<vector>
#include<queue>
#include<set>
#include<tuple>
using namespace std;

int N, K;
int arr[10][10];
vector<int> comb;
int mn;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> K;
    for (int i = 0; i < N; i++)
        if (i != K) comb.push_back(i);

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> arr[i][j];

    for (int k = 0; k < N; k++)
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);

    mn =1e9;
    do {
        int tmp = arr[K][comb[0]];
        for (int i = 0; i < N - 2; i++)
            tmp += arr[comb[i]][comb[i+1]];
        mn = min(tmp, mn);
    } while (next_permutation(comb.begin(), comb.end()));

    cout << mn;
}