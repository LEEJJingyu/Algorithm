#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin>>N;
    vector<string> map(N,"\0");
    vector<vector<int>> num(N,vector<int> (N,0));
    for(int i=0;i<N;i++)
    {
        cin >> map[i];
    }
    vector<int> size;
    for(int j=0;j<N;j++)
    {
        for(int k=0;k<N;k++)
        {
            if(map[j][k]=='1'&&num[j][k]==0)
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
                        if(nx<0||ny<0||nx>=N||ny>=N)continue;
                        if(map[nx][ny]=='0'||num[nx][ny]!=0)continue;
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
        cout<<size[i]<<'\n';
    }
    
}