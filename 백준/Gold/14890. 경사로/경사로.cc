#include<iostream>
using namespace std;
int N,L;
int board[100][100];
int cnt = 0;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> L;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> board[i][j];
    
    for (int i = 0; i < N; i++)
    {
        int l = 1;
        int pre = board[i][0];
        for (int j = 1; j < N; j++)
        {
            if (pre > board[i][j] ? pre - board[i][j] > 1: board[i][j] - pre > 1)
            {
                l = 0; cnt--; break;
            }
            else if (pre > board[i][j]) {
                if (l < 0) { l = 0; cnt--; break; }
                l = -L+1;
                pre = board[i][j];
            }
            else if (pre < board[i][j])
            {
                if (L > l) { l = 0; cnt--;  break; }
                l = 1;
                pre = board[i][j];
            }
            else l++;
        }
        if(l>=0)cnt++;
        
        l = 1;
        pre = board[0][i];
        for (int j = 1; j < N; j++)
        {
            if (pre > board[j][i] ? pre - board[j][i] > 1: board[j][i] - pre > 1)
            {
                l = 0; cnt--; break;
            }
            else if (pre > board[j][i]) {
                if (l < 0) { l = 0; cnt--; break; }
                l = -L + 1;
                pre = board[j][i];
            }
            else if (pre < board[j][i])
            {
                if (L > l) { l = 0; cnt--; break; }
                l = 1;
                pre = board[j][i];
            }
            else l++;
        }
        if (l >= 0)cnt++;
    }
    cout << cnt;
}
