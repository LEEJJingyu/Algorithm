#include<iostream>
#include<vector>
using namespace std;

char map[5][5];
bool vis[5][5];
int cnt;
 int dx[4]={-1,0,1,0};
 int dy[4]={0,-1,0,1};
 int tmp;

bool dfs_visited[6][6];
void dfs(int r, int c)
{
    dfs_visited[r][c] = true;
	for (int i = 0; i < 4; i++)
	{
		int nr = r + dx[i];
		int nc = c + dy[i];
		if (nr < 0 || nr >= 5 || nc < 0 || nc >= 5) continue;
		if (!vis[nr][nc]) continue;
		if (dfs_visited[nr][nc]) continue;

		tmp++;
		dfs(nr, nc);
	}
}

void reset()
{
	fill_n(&dfs_visited[0][0], 6 * 6, 0);
}
bool isconnect(vector<pair<int,int>>& select){
    tmp=1;
    reset();
    dfs(select[0].first,select[0].second);
    return tmp==7;
}

void func(int idx, int n,vector<pair<int,int>>& select)
{
    if(select.size()==7)
    {
        if(n>=4 &&isconnect(select)){cnt++;}
        return;
    }
    if(idx==25)return;
    int x= idx/5;
    int y=idx%5;
        vis[x][y]=true;
        select.push_back({x,y});
        if(map[x][y]=='S')func(idx+1,n+1,select);
        else func(idx+1,n,select);
        select.pop_back();
        vis[x][y]=false;
    func(idx+1,n,select);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    for(int i=0;i<5;i++)
        for(int j=0;j<5;j++)
            cin >> map[i][j];
    cnt=0;
    vector<pair<int,int>> select;
    func(0,0,select);
    cout<<cnt;
}