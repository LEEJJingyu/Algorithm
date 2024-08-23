#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<stack>
#include<cmath>
#include<vector>
using namespace std;
int N;
int ans = 0;
int arr[100];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    for (int i = N - 2; i >= 0; i--)
    {
        if (arr[i] >= arr[i + 1])
        {
            ans += arr[i]-arr[i + 1] + 1;
            arr[i] = arr[i+1] - 1;
        }
    }
    cout << ans;
}
