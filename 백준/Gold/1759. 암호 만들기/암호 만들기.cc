# include<iostream>
using namespace std;
int m,n;
char alp[26];
char arr[15];
bool isuse[26];
bool canKey()
{
    bool isgather=false;
    int isconsonant=0;
    for(int i=0;i<m;i++)
    {
        if(arr[i]=='a'||arr[i]=='e'||arr[i]=='i'||arr[i]=='o'||arr[i]=='u')isgather=true;
        else isconsonant++;
    }
    if(isconsonant>=2&&isgather)return true;
    return false;
}

void key(int k,int x)
{
    if(k==m)
    {
        if(canKey()){
        for(int i=0;i<m;i++)
            cout<<arr[i];
        cout<<'\n';}
        return ;
    }
    for(int i=x;i<n;i++)
        if(!isuse[i]){
        	isuse[i]=true;
            arr[k]=alp[i];
            key(k+1,i);
        	isuse[i]=false;
        }
}


int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> m >> n;
    for(int i=0;i<n;i++)cin>>alp[i];
    for(int i=0;i<n;i++)
        for(int j=n-1;j>i;j--)
            if(alp[i]>alp[j])
            {
                int temp=alp[i];
                alp[i]=alp[j];
                alp[j]=temp;
            }
    key(0,0);
}
