# include<iostream>
# include<string>
using namespace std;
char map[6600][6600];
void hole(int x,int y,int n)
{
    for(int i=x;i<x+n;i++)
        for(int j=y;j<y+n;j++)
            map[i][j]=' ';
}

void star(int x, int y, int n)
{
    if (n == 1)
    {
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++){
               	if(i==1&&j==1) map[x+i][y+j]=' ';
                else map[x+i][y+j]='*';
            }
        return;
    }
    int m=n/3;
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++){
           	if(i==1&&j==1) hole(x+m,y+m,m);
            else star(x+i*m,y+j*m,m);
        }
}


int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    star(0, 0, N);
    for (int i=0;i<N;i++){
    	for (int j=0;j<N;j++)
    		cout << map[i][j];
    	cout<<'\n';
    }
}
