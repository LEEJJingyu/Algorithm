#include<iostream>
#include<vector>
#include<queue>
using namespace std;

queue<pair<int,int>> check[101][101];
int map[101][101]={0,};
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N,M;
    cin >> N >> M;
    for(int i=0;i<M;i++){
        int x1,y1,x2,y2;
        cin >> x1 >> y1>>x2>>y2;
        check[x1][y1].push({x2,y2});
    }
    queue<pair<int,int>> q;
    q.push({1,1});
    map[1][1]=-1;
    while(!q.empty()){
        pair<int,int> cur = q.front();
        q.pop();
        while(!check[cur.first][cur.second].empty())
        {
            int x =check[cur.first][cur.second].front().first;
            int y =check[cur.first][cur.second].front().second;
            if(map[x][y]!=-1)
            {
            	map[x][y]=1;
                for(int i=0;i<4;i++)
                {
                    int nx = x+dx[i];
                    int ny = y+dy[i];
                    if(nx<1&&ny<1&&nx>N&&ny>N)continue;
                    if(map[nx][ny]!=-1)continue;
                    q.push({nx,ny});
                }
            }
            check[cur.first][cur.second].pop();
        }
        for(int i=0;i<4;i++)
        {
            int nx = cur.first+dx[i];
            int ny = cur.second+dy[i];
            if(nx<1&&ny<1&&nx>N&&ny>N)continue;
            if(map[nx][ny]!=1)continue;
            map[nx][ny]=-1;
            q.push({nx,ny});
        }
    }
    int light=0;
    for(int i=1;i<=N;i++)
        for(int j=1;j<=N;j++)
            if(map[i][j]!=0)light++;
    cout << light;
}