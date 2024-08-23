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
int N;
int pre;
int cnt = 1;
int mx = 0;
int num[1000001];
int arr[1000001];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> num[i];
        arr[num[i]] = i;
    }
    pre =arr[1];
    for (int i = 2; i <= N; i++)
    {
        if (arr[i] > pre) {
            cnt++;
        }
        else
        {
            mx = max(mx, cnt);
            cnt = 1;
        }
        pre = arr[i];
    }
    mx = max(mx, cnt);
    cout << N - mx;
}