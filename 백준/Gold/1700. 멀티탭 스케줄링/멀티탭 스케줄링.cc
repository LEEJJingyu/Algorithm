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

int N;
int K;
int num[101];
queue<int> cnt[101];
int ans = 0;
set<int> arr;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> K;
    for (int i = 0; i < K; i++)
    {
        cin >> num[i];
        cnt[num[i]].push(i);
    }
    for (int i = 0; i < K; i++)
    {
        if (arr.size() != N)
        {
            arr.insert(num[i]);
            cnt[num[i]].pop();
        }
        else if (arr.find(num[i]) != arr.end())
        {
            cnt[num[i]].pop();
        }
        else {
            int mx = 0;
            set<int>::iterator idx;
            for (set<int>::iterator itr = arr.begin(); itr !=arr.end(); itr++)
            {
                if (cnt[*itr].empty())
                {
                    idx = itr;
                    break;
                }
                if (mx < cnt[*itr].front()) {
                    mx = cnt[*itr].front();
                    idx = itr;
                }
            }
            arr.erase(idx);
            ans++;
            arr.insert(num[i]);
            cnt[num[i]].pop();
        }
    }
    cout << ans;
}

