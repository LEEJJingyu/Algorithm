#include<iostream>
using namespace std;
struct Bishop
{
    int x, y;
};
int map[10][10];
Bishop board[2][50];
int N;
int max_count[2]={0,0};
int board_num[2]={0,0};
bool isused_L[19]={false};
bool isused_R[19]={false};

void func(int type,int start, int n)
{
    if(start>=board_num[type])
    {
        if(n>max_count[type])
            max_count[type]=n;
        return;
    }
    Bishop bishop = board[type][start];
    int x= bishop.x;
    int y= bishop.y;
    if(map[x][y]==1)
    {
        if(!isused_R[x+y]&&!isused_L[N-x-1+y])
        {
            isused_R[x+y]=true;
            isused_L[N-x-1+y]=true;
            func(type,start+1,n+1);
            isused_R[x+y]=false;
            isused_L[N-x-1+y]=false;
        }
    }
    func(type,start+1,n);
    
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++){
			cin>>map[i][j];
            if(map[i][j]==1)
                board[(i+j)%2][board_num[(i+j)%2]++]={i,j};
			}
	func(0,0,0);
	func(1,0,0);
	cout<<max_count[0]+max_count[1];
}