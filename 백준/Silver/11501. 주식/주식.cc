#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<stack>
#include<cmath>
using namespace std;
int T;
int N;
long long ans = 0;
int arr[1000000];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    while (T--)
    {
        cin >> N;
        ans = 0;
        for (int i = 0; i < N; i++)
            cin >> arr[i];
        int mx = arr[N-1];
        for (int i = N - 2; i >= 0; i--)
        {
            if (mx < arr[i])
                mx = arr[i];
            else
                ans += ( mx - arr[i]);
        }
        cout << ans<<'\n';
    }

}
