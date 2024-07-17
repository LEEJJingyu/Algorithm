#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<tuple>
using namespace std;
string map[1002];
int dist[1002][1002][12][2];
int dx[4]={-1,0,1,0};
int dy[4]={0,-1,0,1};
int N,M,K;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N>>M>>K;
    for(int i=0;i<N;i++)cin>>map[i];
    queue<tuple<int,int,int,int>> q;
    q.push({0,0,0,0});
    dist[0][0][0][0]=1;
    while(!q.empty())
    {
        tuple<int,int,int,int> cur = q.front();
        q.pop();
        if(get<0>(cur)==N-1&&get<1>(cur)==M-1)
        {
            cout<<dist[get<0>(cur)][get<1>(cur)][get<2>(cur)][get<3>(cur)];
            return 0;
        }
        for(int i=0;i<4;i++)
        {
            int nx = get<0>(cur)+dx[i];
            int ny = get<1>(cur)+dy[i];
            if(nx<0||ny<0||nx>=N||ny>=M)continue;
            if(map[nx][ny]=='0'){
            	int nw = get<2>(cur);
                int nt = 1-get<3>(cur);
                if(dist[nx][ny][nw][nt]>0)continue;
                dist[nx][ny][nw][nt]=dist[get<0>(cur)][get<1>(cur)][get<2>(cur)][get<3>(cur)]+1;
                q.push({nx,ny,nw,nt});
            }
            else{
                if(get<2>(cur) == K) continue;
                if(get<3>(cur) == 0){
                  int nw = get<2>(cur)+1;
                  int nt = 1;
                  if(dist[nx][ny][nw][nt]>0)continue;
                    dist[nx][ny][nw][nt]=dist[get<0>(cur)][get<1>(cur)][get<2>(cur)][get<3>(cur)]+1;
                    q.push({nx,ny,nw,nt});
                }
                else{
                  int nt = 0;
                  if(dist[get<0>(cur)][get<1>(cur)][get<2>(cur)][nt]>0)continue;
                   dist[get<0>(cur)][get<1>(cur)][get<2>(cur)][nt]=dist[get<0>(cur)][get<1>(cur)][get<2>(cur)][get<3>(cur)]+1;
                    q.push({get<0>(cur),get<1>(cur),get<2>(cur),nt});
                }
            }
        }
    }
  cout << -1;
}