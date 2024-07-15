#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int M,N,K;
    cin>>M>>N>>K;
    vector<vector<int>> map(M,vector<int> (N,0));
    vector<vector<int>> num(M,vector<int> (N,0));
    for(int i=0;i<K;i++)
    {
        int x1,y1,x2,y2;
        cin >> y1>>x1>> y2>>x2;
        for(int j=x1;j<x2;j++)
        {
            for(int k=y1;k<y2;k++)
            {
                map[j][k]=-1;
            }
        }
    }
    vector<int> size;
    for(int j=0;j<M;j++)
    {
        for(int k=0;k<N;k++)
        {
            if(map[j][k]==0&&num[j][k]==0)
            {
    			queue<pair<int,int>> q;
                num[j][k]=1;
                q.push({j,k});
                    int count=1;
                while(!q.empty()){
                    int dx[4]={-1,0,1,0};
                    int dy[4]={0,-1,0,1};
                    pair<int,int> cur = q.front();
                    q.pop();
                    for(int dir=0;dir<4;dir++)
                    {
                        int nx = cur.first+dx[dir];
                        int ny = cur.second+dy[dir];
                        if(nx<0||ny<0||nx>=M||ny>=N)continue;
                        if(map[nx][ny]==-1||num[nx][ny]!=0)continue;
                        num[nx][ny]=num[cur.first][cur.second]+1;
                        q.push({nx,ny});
                        count++;
                    }
                    if(q.empty())size.push_back(count);
                }
                
            }
        }
    }
    cout<<size.size()<<'\n';
    for(int i=0;i<size.size();i++)
    {
        for(int j=size.size()-1;j>i;j--)
        {
			if(size[i]>size[j])
            {
                int temp=size[i];
                size[i]=size[j];
                size[j]=temp;
            }
        }
        cout<<size[i]<<' ';
    }
    
}