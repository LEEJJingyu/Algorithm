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
vector<vector<pair<int,string>>> s (50,vector<pair<int,string>>());
int N;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    string tmp;
    getline(cin,tmp);
    for (int i = 0; i < N; i++)
    {
        string t;
        getline(cin,t);
        int ans = 0;
        for (char c : t)
        {
            if (c >= '0' && c <= '9')
            {
                ans += c - '0';
            }
        }
        s[t.size() - 1].push_back({ ans,t });
    }

    
    for (int i = 0; i < 50; i++)
    {
        sort(s[i].begin(), s[i].end());
    }
    for (int i = 0; i < 50; i++)
        for (auto t : s[i])
            cout << t.second << '\n';
}