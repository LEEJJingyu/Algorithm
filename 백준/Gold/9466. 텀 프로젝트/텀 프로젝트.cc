#include <iostream>
#include <vector>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
   	int T;
    cin >> T;
    for(int test_case=1;test_case<=T;test_case++)
    {
        int N;
        cin >> N;
        vector<pair<int,int>> select(N+1,{0,0});
        for(int i=1;i<=N;i++)cin >> select[i].first;
        int team=0;
        for(int i=1;i<=N;i++)
        {
            if(select[i].second==0)
            {
                int cur = i;
                while(true)
                {
                    select[cur].second=i;
                    cur = select[cur].first;
                    if(select[cur].second==i){
                        while(select[cur].second!=-1){
                       	select[cur].second=-1;
                        cur = select[cur].first;
                        team++;
                        }
                        break;
                    }
                    else if(select[cur].second!=0)break;
                }
            }
        }
        cout<<N-team<<'\n';
    }
}