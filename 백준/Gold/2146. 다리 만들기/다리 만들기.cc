#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
   	int N;
    cin>>N;
    vector<vector<int>> map(N,vector<int> (N));
    vector<vector<int>> check(N,vector<int> (N,0));
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            cin >> map[i][j];
    int count=0;
    vector<vector<pair<int,int>>> bundle(N*N,vector<pair<int,int>>(0));
    for(int i=0;i<N;i++)
    {    
        for(int j=0;j<N;j++)
        {
            if(map[i][j]==1&&check[i][j]==0)
            {
                count++;
                int dx[4]={-1,0,1,0};
                int dy[4]={0,-1,0,1};
                queue<pair<int,int>> q;
                check[i][j]=-1;
                q.push({i,j});
                while(!q.empty())
                {
                    pair<int,int> cur = q.front();
                    q.pop();
                    for(int dir=0;dir<4;dir++)
                    {
                        int nx = cur.first+dx[dir];
                        int ny = cur.second+dy[dir];
                        if(nx<0||ny<0||nx>=N||ny>=N)continue;
                        if(map[nx][ny]==0&&map[cur.first][cur.second]==1&&check[cur.first][cur.second]!=count){
                            check[cur.first][cur.second]=count;
                        	bundle[count].push_back({cur.first,cur.second});
                        }
                        if(map[nx][ny]==0||check[nx][ny]!=0)continue;
                        check[nx][ny]=-1;
                        q.push({nx,ny});
                    }
                }
            }
        }
    }
    int best=300;
    for(int i=1;i<count;i++)
    {
        for(int j=i+1;j<=count;j++){
            for(int k=0;k<bundle[i].size();k++)
            {
				for(int w=0;w<bundle[j].size();w++)
                {
                    int nx = abs(bundle[i][k].first-bundle[j][w].first);
                    int ny = abs(bundle[i][k].second-bundle[j][w].second);
					if(best>nx+ny-1)best=nx+ny-1;
                }
            }
        }
    }
    cout<<best;
}