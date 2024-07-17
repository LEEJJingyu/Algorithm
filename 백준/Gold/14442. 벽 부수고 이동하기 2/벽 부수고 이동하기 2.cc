#include <iostream>
#include <queue>
#include <tuple>
#include <string>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
   	int N,K,M;
    cin>>N>>M>>K;
    string map[N];
    int time[N][M][K+1];
    for(int i=0;i<N;i++)
    {
        cin >> map[i];
        for(int j=0;j<M;j++){
            for(int k=0;k<=K;k++)time[i][j][k]=-1;
        }
    }
   queue<tuple<int,int,int>> q;
   q.push({0,0,0});
   time[0][0][0]=1;
    while(!q.empty()){
        tuple<int,int,int> cur = q.front();
        q.pop();
        int dx[4]={-1,0,1,0};
        int dy[4]={0,-1,0,1};
        for(int i=0;i<4;i++)
        {
            int nx = get<0>(cur)+dx[i];
            int ny =get<1>(cur)+dy[i];
            int n = get<2>(cur);
            if(nx<0||ny<0||nx>=N||ny>=M)continue;
            if(map[nx][ny]=='1'){if(n<K)n++;else continue;}
            if(time[nx][ny][n]!=-1)continue;
            time[nx][ny][n]=time[get<0>(cur)][get<1>(cur)][get<2>(cur)]+1;
            if(nx==N-1&&ny==M-1){cout<<time[nx][ny][n]; return 0;}
            q.push({nx,ny,n});
        }
    }
    if(N==1&&M==1)cout<<1;
    else cout<< -1;
}