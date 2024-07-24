# include<iostream>
using namespace std;
int x,y;
int N,R;
int dx[4][4]={{0,1,1,0},{0,0,1,1},{1,1,0,0},{1,0,0,1}};
int dy[4][4]={{0,0,1,1},{0,1,1,0},{1,0,0,1},{1,1,0,0}};
void mage(int min,int n,int num)
{
    if(n==2)
    {
        x+=dx[num][R-min];
        y+=dy[num][R-min];
        return;
    }
    int m = n/2;
    if(min<=R&&R<min+m*m){
        x+=m*dx[num][0];
        y+=m*dy[num][0];
    	mage(min,m,(num%2==0?num+1:num-1));
    }
    else if(min+m*m<=R&&R<min+2*m*m){
        x+=m*dx[num][1];
        y+=m*dy[num][1];
    	mage(min+m*m,m,num);
    }
    else if(min+m*m*2<=R&&R<min+3*m*m){
        x+=m*dx[num][2];
        y+=m*dy[num][2];
    	mage(min+2*m*m,m,num);
    }
    else if(min+3*m*m<=R&&R<min+4*m*m){
        x+=m*dx[num][3];
        y+=m*dy[num][3];
    	mage(min+3*m*m,m,(num+2)%4);
    }
    
}


int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N>>R;
    x=1;
    y=1;
    mage(1,N,0);
    cout<<y<<' '<<x;
}
