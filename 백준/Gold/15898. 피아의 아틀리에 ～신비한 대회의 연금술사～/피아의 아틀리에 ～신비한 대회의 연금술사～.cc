#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;
int n;
int status[10][4][4];
char type_s[10][4][4];
bool isused[10] = {0,};
pair<char,int> temp[3][4][4];
int dx[4] = { 0,1,0,1 };
int dy[4] = { 0,0,1,1 };
map<char, int> cal = { {'R',0},{'B',0},{'G',0},{'Y',0}, {'W',0} };
int ans = 0;
int makePotion()
{
    int mx = 0;
    for(int t1=0;t1<4;t1++)
        for(int t2=0;t2<4;t2++)
            for (int t3 = 0; t3 < 4; t3++)
            {
                cal['R'] = 0,cal['B']=0, cal['G']=0, cal['Y']=0;
                vector<vector<pair<char, int>>> board(5, vector<pair<char, int>>(5, {'W',0}));
                for (int i = 0; i <  4; i++)
                    for (int j = 0; j <  4; j++)
                    {
                        if(temp[0][i][j].first != 'W')board[i + dx[t1]][j + dy[t1]].first = temp[0][i][j].first;
                        board[i + dx[t1]][j + dy[t1]].second += temp[0][i][j].second;
                        if (board[i + dx[t1]][j + dy[t1]].second < 0)board[i + dx[t1]][j + dy[t1]].second = 0;
                        else if(board[i + dx[t1]][j + dy[t1]].second>9)board[i + dx[t1]][j + dy[t1]].second=9;
                    }
                for (int i = 0; i < 4; i++)
                    for (int j = 0; j < 4; j++)
                    {
                        if (temp[1][i][j].first != 'W')board[i + dx[t2]][j + dy[t2]].first = temp[1][i][j].first;
                        board[i + dx[t2]][j + dy[t2]].second += temp[1][i][j].second;
                        if (board[i + dx[t2]][j + dy[t2]].second < 0)board[i + dx[t2]][j + dy[t2]].second = 0;
                        else if(board[i + dx[t2]][j + dy[t2]].second>9)board[i + dx[t2]][j + dy[t2]].second = 9;
                    }
                for (int i = 0; i < 4; i++)
                    for (int j = 0; j < 4; j++)
                    {
                        if (temp[2][i][j].first != 'W')board[i + dx[t3]][j + dy[t3]].first = temp[2][i][j].first;
                        board[i + dx[t3]][j + dy[t3]].second += temp[2][i][j].second;
                        if (board[i + dx[t3]][j + dy[t3]].second < 0)board[i + dx[t3]][j + dy[t3]].second = 0;
                        else if (board[i + dx[t3]][j + dy[t3]].second>9)board[i + dx[t3]][j + dy[t3]].second = 9;
                    }
                for (int i = 0; i < 5; i++)
                    for (int j = 0; j < 5; j++)
                        cal[board[i][j].first] += board[i][j].second;


                mx = max(mx, cal['R'] * 7 + cal['B'] * 5 + cal['G'] * 3 + cal['Y'] * 2);
            }
    return mx;
}

void func(int k)
{
    if (k == 3)
    {
        ans = max(ans, makePotion());
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (!isused[i])
        {
            isused[i] = true;
            for (int x = 0; x < 4; x++)
                for (int y = 0; y < 4; y++) {
                    temp[k][x][y].first = type_s[i][x][y];
                    temp[k][x][y].second = status[i][x][y];
                }
            func(k + 1);
            for (int x = 0; x < 4; x++)
                for (int y = 0; y < 4; y++) {
                    temp[k][3-y][x].first = type_s[i][x][y];
                    temp[k][3-y][x].second = status[i][x][y];
                }
            func(k + 1);
            for (int x = 0; x < 4; x++)
                for (int y = 0; y < 4; y++) {
                    temp[k][3-x][3-y].first = type_s[i][x][y];
                    temp[k][3-x][3-y].second = status[i][x][y];
                }
            func(k + 1);
            for (int x = 0; x < 4; x++)
                for (int y = 0; y < 4; y++) {
                    temp[k][y][3 - x].first = type_s[i][x][y];
                    temp[k][y][3 - x].second = status[i][x][y];
                }
            func(k + 1);
            isused[i] = false;
        }
    }
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int t = 0; t < n; t++)
    {
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                cin >> status[t][i][j];
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                cin >> type_s[t][i][j];
    }
    func(0);
    cout << ans;
}
