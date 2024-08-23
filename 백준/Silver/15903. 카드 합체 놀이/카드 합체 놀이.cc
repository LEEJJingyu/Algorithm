#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<stack>
#include<cmath>
#include<vector>
#include<queue>
using namespace std;
int N, M;
priority_queue<long long,vector<long long>,greater<long long>> arr;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        int t;
        cin >> t;
        arr.push(t);
    }
    for (int i = 0; i < M; i++)
    {
        long long a =arr.top();
        arr.pop();
        long long b = arr.top();
        arr.pop();
        arr.push(a + b);
        arr.push(a + b);
    }
    long long sum = 0;
    while (!arr.empty())
    {
        sum += arr.top();
        arr.pop();
    }
    cout << sum;
}

