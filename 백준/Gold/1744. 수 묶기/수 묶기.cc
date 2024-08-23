#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<stack>
#include<cmath>
#include<vector>
using namespace std;
int N;
vector<int> arrM;
vector<int> arrP;
int ans = 0;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int t;
        cin >> t;
        if (t > 0)
            arrP.push_back(t);
        else
            arrM.push_back(t);
    }
    if (!arrP.empty())
    {
        sort(arrP.begin(), arrP.end(), greater<int>());
        for (int i = 0; i < arrP.size() - 1; i++)
        {
            if (arrP[i + 1] != 1) {
                ans += arrP[i] * arrP[i + 1];
                i++;
            }
            else
            {
                ans += arrP[i];
            }
        }
        if (arrP.back() == 1||arrP.size()%2)
            ans+=arrP.back();
    }
    if (!arrM.empty())
    {
        sort(arrM.begin(), arrM.end());
        for (int i = 0; i < arrM.size() - 1; i++)
        {
            ans += arrM[i] * arrM[i + 1];
            i++;
        }
        if (arrM.size() % 2)
            ans += arrM.back();
    }
    cout << ans;
}
