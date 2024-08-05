#include<iostream>
#include<vector>
using namespace std;
int N;
int board[20][20];
bool isstart[20] = { false, };
int mn = 10000000;
int calculator()
{
    vector<int> link;
    vector<int> start;
    for (int i = 0; i < N; i++)
    {
        if (isstart[i])start.push_back(i);
        else link.push_back(i);
    }
    int st=0, li=0;
    while (!start.empty())
    {
        int i = start.back();
        start.pop_back();
        for (int j : start)
        {
            st += board[i][j] + board[j][i];
        }
    }
    while (!link.empty())
    {
        int i = link.back();
        link.pop_back();
        for (int j : link)
        {
            li += board[i][j] + board[j][i];
        }
    }
    return li > st ? li - st : st - li;
}

void func(int k, int st) {
    if (k == N / 2) {
        int ans = calculator();
        if (mn > ans)
            mn = ans;
        return;
    }
    if (st >= N) return;

    for (int i = st; i < N; i++) {
        isstart[i] = true;
        func(k + 1, i + 1);
        isstart[i] = false;
    }
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> board[i][j];
    isstart[0] = true;
    func(1, 1);
    cout << mn;
}
