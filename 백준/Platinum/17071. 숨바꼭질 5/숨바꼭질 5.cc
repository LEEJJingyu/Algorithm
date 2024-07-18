#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int x[2][500001];
int K[1002];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin >> n>>k;
    int temp=1;
    K[0]=k;
    for(int i=0;i<2;i++)
        fill(x[i],x[i]+500001,-1);
   while(true){
       if(K[temp-1]+temp>500000)break;
        K[temp]=K[temp-1]+temp;
   		temp++;
    }
    queue<pair<int,int>> q;
    q.push({n,0});
    x[0][n]=0;
    if(n==k){cout<<0;return 0;}
    while(!q.empty())
    {
        pair<int,int> cur = q.front();
        if(x[cur.second][cur.first]>temp)break;
        q.pop();
        int pos[3]={cur.first-1,cur.first+1,cur.first*2};
        for(int i=0;i<3;i++)
        {
            int sis = cur.second? 0:1;
            if(pos[i]<0||pos[i]>500000)continue;
            if(x[sis][pos[i]]!=-1||x[sis][pos[i]]>=temp)continue;
            x[sis][pos[i]]=x[cur.second][cur.first]+1;
            q.push({pos[i],sis});
        }
    }
    
    int best=1001;
    for(int i=0;i<temp;i++)
    {
        if((x[0][K[i]]<=i&&x[0][K[i]]>=0&&(i%2==0))||(x[1][K[i]]<=i&&x[1][K[i]]>=0&&(i%2==1))){best=i;break;}
     }
     if(best!=1001)cout << best;
     else cout << -1;
}