#include<iostream>
#include<queue>
#define maxN 1000000001
using namespace std;
int N;
int num[11];
int oper[4];
int mx=-maxN, mn=maxN;

void func(int k, int ans)
{
    if (k == N-1)
    {
        if (mx < ans)
            mx = ans;
        if (mn > ans)
            mn = ans;
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        if (!oper[i])continue;
        oper[i]--;
        int temp=ans;
        switch (i)
        {
        case 0:
            temp += num[k + 1];
            break;
        case 1:
            temp -= num[k + 1];
            break;
        case 2:
            temp *= num[k + 1];
            break;
        case 3:
            temp /= num[k + 1];
            break;
        }
        func(k + 1, temp);
        oper[i]++;
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> num[i];
    for (int i = 0; i < 4; i++)
        cin >> oper[i];
    func(0, num[0]);
    cout << mx << '\n' << mn;
}
