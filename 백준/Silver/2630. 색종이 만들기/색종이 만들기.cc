#include<iostream>
#include<cmath>
using namespace std;
int map[130][130];
int cnt[2]={0,};
bool check(int x, int y, int n)
{
    int sum=0;
    for(int i=x;i<x+n;i++)
        for(int j=y;j<y+n;j++){
            sum+=map[i][j];
        }
    if(sum%(n*n)==0){
        return true;
    }
    return false;
            
}

void paper(int x, int y, int n){
    if(check(x,y,n)){
        cnt[map[x][y]]++;
        return ;
    }
    int m=n/2;
    paper(x,y,m);
    paper(x+m,y,m);
    paper(x,y+m,m);
    paper(x+m,y+m,m);
}



int main(void){
  	ios::sync_with_stdio(0);
  	cin.tie(0);
    int N;
    cin >> N;
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            cin >> map[i][j];
    paper(0,0,N);
    for(int i=0;i<2;i++)cout<<cnt[i]<<'\n';
}