#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
   	int K,W,H;
    cin >> K;
    cin>>W>>H;
    vector<vector<int>> map(H,vector<int>(W));
    vector<vector<vector<int>>> check(H,vector<vector<int>>(W,vector<int> (K+1,W*H)));
    for(int i=0;i<H;i++)
        for(int j=0;j<W;j++)
            cin >> map[i][j];
    queue<tuple<int,int,int>> q;
    check[0][0][0]=0;
    q.push({0,0,0});
    int num=0;
    while(!q.empty())
    {
        tuple<int,int,int> cur = q.front();
        q.pop();
        int x = get<0>(cur);
        int y = get<1>(cur);
        int t = get<2>(cur);
        
        if(x == H - 1 && y == W - 1)
        {
            cout << check[x][y][t];
            return 0;
        }
        
        int dx[12]={-1,-2,-2,-1,1,2,2,1,-1,0,1,0};
        int dy[12]={-2,-1,1,2,-2,-1,1,2,0,-1,0,1};
        for(int i=0;i<12;i++)
        {
            int nx = x+dx[i];
            int ny = y+dy[i];
            int nt =t+(i < 8 ? 1 : 0);
            if(nx<0||ny<0||nx>=H||ny>=W)continue;
            if(nt>K)continue;
            if(check[nx][ny][nt]!=W*H)continue;
            if(map[nx][ny]==1)continue;
            q.push({nx,ny,nt});
            check[nx][ny][nt]=check[x][y][t]+1;
        }
    }
    cout<<-1;
    
}