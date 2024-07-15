#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

char map[1001][1001];
int dist[1001][1001]={-1,};
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int r,c;
    bool isfire=false;
    int best=-1;
    bool possible = false;
    int dx[4]={1,0,-1,0};
    int dy[4]={0,1,0,-1};
    queue<pair<int,int>> jh;
    queue<pair<int,int>> fire;
    cin >> r >> c;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            cin >> map[i][j];
            if(map[i][j]=='F'){fire.push({i,j});dist[i][j]=0;isfire=true;}
            if(map[i][j]=='J'){jh.push({i,j});}
        }
    }
    while(!fire.empty()){
        auto cur = fire.front();
        fire.pop();
        for(int dir=0;dir<4;dir++)
        {
            int nx = cur.first+dx[dir];
            int ny = cur.second+dy[dir];
            if(nx<0||nx>=r||ny<0||ny>=c)continue;
            if(map[nx][ny]=='F'||map[nx][ny]=='#'||dist[nx][ny]<0)continue;
            fire.push({nx,ny});
            dist[nx][ny]=dist[cur.first][cur.second]-1;
        }
    }
    
    dist[jh.front().first][jh.front().second]=0;
    if(jh.front().first==0||jh.front().first==r-1||jh.front().second==0||jh.front().second==c-1){best=0;possible=true;}
    if(!possible)while(!jh.empty()){
    	auto cur = jh.front();
        jh.pop();
        
       	for(int dir=0;dir<4;dir++)
        {
            int nx = cur.first+dx[dir];
            int ny = cur.second+dy[dir];
            if(nx<0||nx>=r||ny<0||ny>=c)continue;
            if(map[nx][ny]=='#'||dist[nx][ny]>0)continue;
            if(isfire)if(dist[cur.first][cur.second]+1>=abs(dist[nx][ny]))continue;
            jh.push({nx,ny});
            dist[nx][ny]=dist[cur.first][cur.second]+1;
            map[cur.first][cur.second]='.';
            if(nx==0||nx==r-1||ny==0||ny==c-1){if(best==-1||best>dist[nx][ny]){best=dist[nx][ny];}possible=true;}
        }
    }
    if(possible)cout << best+1;
    else cout << "IMPOSSIBLE";
    return 0;
}