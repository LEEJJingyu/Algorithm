#include<iostream>
#include<queue>
#include<vector>
using namespace std;

char map[5][5];
bool vis[5][5];
int cnt;
 int dx[4]={-1,0,1,0};
 int dy[4]={0,-1,0,1};
bool isconnect(vector<pair<int,int>>& select){
    int tmp=0;
    bool vised[5][5]={false};
	queue<pair<int,int>> q;
    q.push(select[0]);
    vised[select[0].first][select[0].second]=true;
    while(!q.empty())
    {
        tmp++;
        pair<int,int> cur = q.front();
        q.pop();
        for(int i=0;i<4;i++)
        {
            int nx=cur.first+dx[i];
            int ny=cur.second+dy[i];
            if(nx<0||ny<0||nx>=5||ny>=5)continue;
            if(vis[nx][ny]&&!vised[nx][ny]){
                q.push({nx,ny});
                vised[nx][ny]=true;
           }
        }
    }
    return tmp==7;
}

void func(int idx, int n,vector<pair<int,int>>& select)
{
    if(select.size()==7)
    {
        if(n>=4 &&isconnect(select)){cnt++;}
        return;
    }
    if(idx==25)return;
    int x= idx/5;
    int y=idx%5;
        vis[x][y]=true;
        select.push_back({x,y});
        if(map[x][y]=='S')func(idx+1,n+1,select);
        else func(idx+1,n,select);
        select.pop_back();
        vis[x][y]=false;
    func(idx+1,n,select);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    for(int i=0;i<5;i++)
        for(int j=0;j<5;j++)
            cin >> map[i][j];
    cnt=0;
    vector<pair<int,int>> select;
    func(0,0,select);
    cout<<cnt;
}