#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
   	int M,N;
    cin>>M>>N;
    vector<vector<pair<int,int>>> map(M,vector<pair<int,int>> (N));
    for(int i=0;i<M;i++)
    {
        for(int j=0;j<N;j++)
        {
            cin>>map[i][j].first;
        }
    }
    int time=0;
    while(true)
    {
        int num=0;
    	vector<vector<int>> solve(M,vector<int> (N,0));
        int dx[4]={-1,0,1,0};
        int dy[4]={0,-1,0,1};
        for(int i=0;i<M;i++)
        {
            for(int j=0;j<N;j++)
            {
                map[i][j].second=map[i][j].first;
                if(map[i][j].first!=0&&solve[i][j]==0)
                {
                    num++;
                    queue<pair<int,int>> q;
                    q.push({i,j});
                    while(!q.empty())
                    {
                        pair<int,int> cur = q.front();
                        q.pop();
                        for(int dir=0;dir<4;dir++)
                        {
                            int nx=cur.first+dx[dir];
                            int ny=cur.second+dy[dir];
                            if(nx<0||ny<0||nx>=M||ny>=N)continue;
                            if(map[nx][ny].first==0||solve[nx][ny]!=0)continue;
                            q.push({nx,ny});
                            solve[nx][ny]=num;
                        }
                    }
                }
            }
        }
        if(num>1)break;
        if(num==0){time=0;break;}
        time++;
        for(int i=0;i<M;i++)
        {
            for(int j=0;j<N;j++)
            {
                if(map[i][j].second!=0)
                {
                    for(int dir=0;dir<4;dir++)
                    {
                        int nx=i+dx[dir];
                        int ny=j+dy[dir];
                        if(nx<0||ny<0||nx>=M||ny>=N)continue;
                        if(map[nx][ny].second==0&&map[i][j].first>0)map[i][j].first--;
                    }
                }
            }
        }
    }
    cout<<time;
}