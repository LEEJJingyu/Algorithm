#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <tuple>
#include <algorithm>
#include <cmath>
#include <string>
#include <climits>
#include <map>
using namespace std;
int N;
vector<pair<int, string>> members;
bool compare(pair<int, string> a, pair<int, string> b)
{
    return a.first < b.first;
}
int cnt[201] = { 0, };
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        string s;
        int t;
        cin >> t;
        getline(cin, s);
        members.push_back({ t,s });
    }
    for (auto member : members)
    {
        cnt[member.first]++;
    }
    int total = 0;
    for (int i = 1; i < 201; i++)
    {
        if (cnt[i])
        {
            cnt[i] += total;
            total = cnt[i];
        }
    }
    reverse(members.begin(), members.end());
    pair<int, string> *sort_members=new pair<int,string>[N]();
    for(auto member : members)
    {
        sort_members[--cnt[member.first]] =member;
    }
    for (int i=0;i<N;i++)
    {
        cout << sort_members[i].first << sort_members[i].second << '\n';
    }
}