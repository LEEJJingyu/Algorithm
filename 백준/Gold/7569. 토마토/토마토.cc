#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;
void BFS(queue<tuple<int,int,int>> str, int N,int M,int H,vector<vector<vector<int>>> &map,vector<vector<vector<int>>> &pos)
{
    int dx[6]={-1,0,1,0,0,0};
    int dy[6]={0,-1,0,1,0,0};
    int dz[6]={0,0,0,0,-1,1};
    queue<tuple<int,int,int>> q;
    q=str;
    while(!q.empty())
    {
        tuple<int,int,int> cur = q.front();
        q.pop();
        for(int i=0;i<6;i++)
        {
            int nx = get<1>(cur)+dx[i];
            int ny = get<2>(cur)+dy[i];
            int nz = get<0>(cur)+dz[i];
            if(nx<0||ny<0||nx>=N||ny>=M||nz<0||nz>=H)continue;
            if(map[nz][nx][ny]==-1||pos[nz][nx][ny]>0)continue;
            q.push({nz,nx,ny});
            pos[nz][nx][ny]=pos[get<0>(cur)][get<1>(cur)][get<2>(cur)]+1;
        }
    }
}
int main() {
    int N,M,H;
    bool error=false;
    bool allripe=true;
    int num=0;
        cin >> M>>N>>H;
   vector<vector<vector<int>>> map(H, vector<vector<int>>(N, vector<int>(M, 0)));
    vector<vector<vector<int>>> pos(H, vector<vector<int>>(N, vector<int>(M, 0)));
    queue<tuple<int,int,int>> q;
    for(int k=0;k<H;k++)
    {    
    for(int i=0;i<N;i++)
        {
            for(int j=0;j<M;j++)
        	{
                
                    cin >> map[k][i][j];
                if(map[k][i][j]==1){q.push({k,i,j});pos[k][i][j]=1;}
                else if(map[k][i][j]==0)allripe=false;
                
            }
        }
    }
    if(allripe){cout<<0;return 0;}
                    BFS(q,N,M,H,map,pos);
               
                for(int k=0;k<H;k++)
        		{
    for(int i=0;i<N;i++)
        {
            for(int j=0;j<M;j++)
            {
                    if(pos[k][i][j]==0&&map[k][i][j]==0){error=true;}
                    if(map[k][i][j]==0&&num<pos[k][i][j])num=pos[k][i][j];
                }
            }
        }
    num--;
    if(error)num=-1;
        cout<<num;
        

    return 0;
}