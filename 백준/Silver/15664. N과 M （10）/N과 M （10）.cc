# include<iostream>
using namespace std;
int n,m;
int arr[9];
int num[9];
bool isuse[9];
void func(int k, int x)
{
    if(k==m)
    {
        for(int i=0;i<m;i++){
            cout<<arr[i]<<' ';
        }
        cout<<'\n';
        return ;
    }
    int tmp = 0;
    for(int i=x;i<n;i++){
        if(!isuse[i]&&tmp!=num[i])
        {
            isuse[i]=true;
            arr[k]=num[i];
            tmp=arr[k];
            func(k+1,i);
            isuse[i]=false;
        }
    }
}


int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n>>m;
    for(int i=0;i<n;i++)cin>>num[i];
    for(int i=0;i<n;i++)
        for(int j=n-1;j>i;j--)
            if(num[i]>num[j]){
    			int temp=num[i];
            	num[i]=num[j];
                num[j]=temp;
            }
    func(0,0);
}
