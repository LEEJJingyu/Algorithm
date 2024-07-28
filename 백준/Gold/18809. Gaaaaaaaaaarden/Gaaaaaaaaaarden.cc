#include<iostream>
#include<queue>
using namespace std;
struct Cell {
	int x,y,time,type;
};
int map[50][50];
pair<int,int> board[11];
int Green[5];
int Red[5];
int N,M,G,R;
int num_board=0;
int max_flowers=0;
int dx[4]={-1,0,1,0};
int dy[4]={0,-1,0,1};

int calculate()
{
	queue<Cell> q;
	int flowerCount=0;
	int dist[50][50]={0};
	int type[50][50]={0}; //0:empty, 1:green, 2:red, 3:green

	for(int i=0;i<G;i++){
		int g = Green[i];
		int x = board[g].first;
		int y = board[g].second;
		q.push({x,y,0,1});
		type[x][y] = 1;

	}
	for(int i=0;i<R;i++){
		int r = Red[i];
		int x = board[r].first;
		int y = board[r].second;
		q.push({x,y,0,2});
		type[x][y] = 2;
	}
	while(!q.empty())
	{
		Cell cell = q.front();
		q.pop();
		if(type[cell.x][cell.y]==3)continue;
		for(int i=0;i<4;i++)
		{
			int nx = cell.x+dx[i];
			int ny = cell.y+dy[i];
			if(nx<0||ny<0||nx>=N||ny>=M)continue;
			if(map[nx][ny]==0||type[nx][ny]==3)continue;
			if(type[nx][ny]==0){
				type[nx][ny]=cell.type;
				dist[nx][ny]=cell.time+1;
				q.push({nx,ny,dist[nx][ny],type[nx][ny]});
			}
			else if(type[nx][ny]+cell.type==3&&dist[nx][ny]==cell.time+1){
				type[nx][ny]=3;
				flowerCount++;
			}
		}
	}
	return flowerCount;
}

void func(int x,int y,int start){
	if(x==G&&y==R){
		int n = calculate();
		if(n>max_flowers)
			max_flowers=n;
		return ;
	}
	if(start>=num_board||x>G||y>R)return ;
	if(x<G)
	{
		Green[x]=start;
		func(x+1,y,start+1);
	}
	if(y<R){
		Red[y]=start;
		func(x,y+1,start+1);
	}
	func(x,y,start+1);

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N>>M;
	cin >> G>>R;
	for(int i=0;i<N;i++)
		for(int j=0;j<M;j++){
			cin>>map[i][j];
			if(map[i][j]==2){
				board[num_board++]={i,j};
			}
		}
	func(0,0,0);
	cout<<max_flowers;
}