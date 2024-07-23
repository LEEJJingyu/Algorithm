# include<iostream>
# include<string>
using namespace std;
char map[6200][6200]={' ',};
void star(int x, int y, int n)
{
    if (n == 3)
    {
        for(int j=y;j<y+5;j++)
            map[x][j]='*';
        map[x-1][y+1]='*';
        map[x-1][y+3]='*';
        map[x-2][y+2]='*';
        return;
    }
    int m=n/2;
    star(x,y,m);
    star(x,y+2*m,m);
    star(x-m,y+m,m);
}


int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    for (int i=0;i<=N;i++)
    	for (int j=0;j<=2*N;j++)
            map[i][j]=' ';
    star(N,1, N);
    for (int i=1;i<N+1;i++){
    	for (int j=1;j<2*N+1;j++)
    		cout << map[i][j];
    	cout<<'\n';
    }
}
