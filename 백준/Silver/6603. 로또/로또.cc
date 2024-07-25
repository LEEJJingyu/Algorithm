# include<iostream>
using namespace std;
int n;
int num[51];
int arr[6];
bool isuse[51];
void lotto(int k,int x)
{
    if(k==6)
    {
        for(int i=0;i<6;i++)
            cout<<arr[i]<<' ';
        cout<<'\n';
        return ;
    }
    for(int i=x;i<n;i++)
        if(!isuse[i])
        {
            isuse[i]=true;
            arr[k]=num[i];
            lotto(k+1,i);
            isuse[i]=false;
        }
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    bool isstart=true;
    while(true){
    	cin >> n;
    	if (n==0) break;
        else if (!isstart)cout<<'\n';
        for(int i=0;i<n;i++)cin >>num[i];
        lotto(0,0);
        isstart=false;
    }
}
