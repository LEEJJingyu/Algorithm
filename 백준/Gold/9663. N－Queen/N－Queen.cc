# include<iostream>
using namespace std;
int n;
int cnt;
bool isuse[15]={0,};
bool isuse_L[30]={0,};
bool isuse_R[30]={0,};
void queen(int k)
{
    if(k==n)
    {
        cnt++;
        return ;
    }
    for(int i=0;i<n;i++)
    {
        if(!(isuse[i]||isuse_R[i+k]||isuse_L[n-1-i+k])){
            isuse_R[i+k]=true;
            isuse_L[n-1-i+k]=true;
            isuse[i]=true;
            queen(k+1);
            isuse[i]=false;
            isuse_R[i+k]=false;
            isuse_L[n-1-i+k]=false;
        }
    }
}


int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    cnt=0;
    queen(0);
    cout<<cnt;
}
