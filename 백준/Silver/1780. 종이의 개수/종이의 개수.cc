#include<iostream>
#include<cmath>
using namespace std;
int map[2200][2200];
int cnt[3]={0,};
bool paper(int x, int y, int n){
    int dn = pow(3,n)/2-pow(3,n-1)/2;
	int dx[9]={-dn,0,dn,-dn,dn,-dn,0,dn,0};
	int dy[9]={-dn,-dn,-dn,0,0,dn,dn,dn,0};
    if(n==1){
        int temp=map[x][y];
        for(int i=0;i<8;i++)
            if(temp!=map[x+dx[i]][y+dy[i]])
                return false;
        cnt[temp+1]-=8;
        return true;
    }
    bool isSame=true;
    for(int i=0;i<9;i++)
        if(!paper(x+dx[i],y+dy[i],n-1))
            isSame=false;
    if(isSame)for(int i=0;i<8;i++)if(map[x][y]!=map[x+dx[i]][y+dy[i]])isSame=false;
    if(isSame)cnt[map[x][y]+1]-=8;
    return isSame;
}



int main(void){
  	ios::sync_with_stdio(0);
  	cin.tie(0);
    int N;
    cin >> N;
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
        {
            cin >> map[i][j];
            cnt[map[i][j]+1]++;
        }
    if(N!=1)
    {
    int k=-1;
    int t=N;
    while(t){t/=3;k++;}
    paper(N/2,N/2,k);
    }
    for(int i=0;i<3;i++)cout<<cnt[i]<<'\n';
}