#include<iostream>
using namespace std;
int c,r;
int cnt=0;
bool isend=false;
void zz(int x,int y, int n)
{
    if(isend)return;
   	if(n==0)
    {
        if(x==c&&y==r){
        	cout<<cnt;
        	isend=true;
        }
    	cnt++;
        return ;
    }
    if(c+1>x+1+(1<<n))
    {
        cnt+=(1<<(2*n));
        return ;
    }
    if(r+1>y+1+(1<<n))
    {
        cnt+=(1<<(2*n));
        return ;
    }
    if(((x+1)*(y+1))%(1<<2*n)==0)
    	zz(x-(1<<(n-1)),y,n-1);
    else
        zz(x,y,n-1);
    zz(x,y+(1<<(n-1)),n-1);
    if(((x+1)*(y+1))%(1<<2*n-1)==0)
    	zz(x+(1<<(n-1)),y-(1<<(n-1)),n-1);
    else
    	zz(x+(1<<(n-1)),y,n-1);
    zz(x+(1<<(n-1)),y+(1<<(n-1)),n-1);
}

int main(void){
  	ios::sync_with_stdio(0);
  	cin.tie(0);
    int n;
    cin >> n >> c >>r;
    zz(0,0,n);
}