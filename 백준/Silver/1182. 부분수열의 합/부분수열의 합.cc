# include<iostream>
using namespace std;
int n,ans;
int cnt;
int num[20];
void sum(int k,int t)
{
    if(t==n){
        if(k==ans)
        {
            cnt++;
        }
        return;
    }
            sum(k,t+1);
            sum(k+num[t],t+1);
}


int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n>>ans;
    for(int i=0;i<n;i++)cin>>num[i];
    cnt=0;
    sum(0,0);
    if(ans==0)cnt--;
    cout<<cnt;
}
