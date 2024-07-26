# include<iostream>
using namespace std;
int map[1001];
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int N;
    cin >> N;
    for(int i=0;i<N;i++)cin>>map[i];
    for(int i=0;i<N;i++){
        for(int j=N-1;j>i;j--)
            if(map[i]>map[j])
            {
                int temp = map[i];
                map[i]=map[j];
                map[j]=temp;
            }
        cout<<map[i]<<'\n';
    }
    
}