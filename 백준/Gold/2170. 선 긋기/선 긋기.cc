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
pair<int, int> lines[1000000];
vector<pair<int, int>> ans;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> lines[i].first >> lines[i].second;
    sort(lines, lines + N);
    ans.push_back(lines[0]);
    for (int i = 1; i < N; i++)
    {
        if (ans.back().second < lines[i].first)
        {
            ans.push_back(lines[i]);
        }
        else if (ans.back().second < lines[i].second)
            ans.back().second = lines[i].second;
    }
    int sum = 0;
    for (pair<int, int> line : ans)
    {
        sum += line.second - line.first;
    }
    cout << sum;
}

