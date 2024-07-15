#include <iostream>
#include <vector>
#include <queue>
using namespace std;
void BFS(pair<int,int> str, int N, int M,vector<vector<int>> &map,vector<vector<int>> &pos)
{
    int dx[4]={-1,0,1,0};
    int dy[4]={0,-1,0,1};
    queue<pair<int,int>> q;
    q.push(str);
    while(!q.empty())
    {
        pair<int,int> cur = q.front();
        q.pop();
        for(int i=0;i<4;i++)
        {
            int nx = cur.first+dx[i];
            int ny = cur.second+dy[i];
            if(nx<0||ny<0||nx>=N||ny>=M)continue;
            if(map[nx][ny]==0||pos[nx][ny]>0)continue;
            q.push({nx,ny});
            pos[nx][ny]=1;
        }
    }
}
int main() {
   	int T;
    int M,N,K;
    vector<vector<int>> map;
    vector<vector<int>> pos;
    cin >> T;
    for(int test_case=1;test_case<=T;test_case++)
    {
        int num=0;
        cin >> N>>M>>K;
        vector<int> temp;
        temp.assign(M,0);
	   	pos.assign(N,temp);
	   	map.assign(N,temp);
        for(int i=0;i<K;i++)
        {
            int x,y;
            cin >>x>>y;
            map[x][y]=1;
        }
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<M;j++)
            {
                if(map[i][j]==1&&pos[i][j]==0)
                {
                    BFS({i,j},N,M,map,pos);
                    num++;
                }
            }
        }
        cout<<num<<'\n';
        
    }

    return 0;
}