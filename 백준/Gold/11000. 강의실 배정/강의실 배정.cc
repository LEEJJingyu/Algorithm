#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<stack>
#include<cmath>
#include<vector>
#include<queue>
using namespace std;
int N;
pair<int, int> lectures[200000];
priority_queue<int,vector<int>,greater<int>> q;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int a, b;
        cin >> a >> b;
        lectures[i] = { a,b };
    }
    sort(lectures, lectures + N);
    q.push(lectures[0].second);
    for(int i=1;i<N;i++)
    {
        if (q.top() <= lectures[i].first)
            q.pop();
        q.push(lectures[i].second);
    }
    cout << q.size();
}

