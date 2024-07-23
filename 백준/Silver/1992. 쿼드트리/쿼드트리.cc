#include<iostream>
#include<string>
using namespace std;
string map[64];
string answer;
bool check(int x, int y, int n)
{
    char first = map[x][y];
    for(int i=x;i<x+n;i++)
        for(int j=y;j<y+n;j++)
            if(map[i][j]!=first)return false;
    return true;
}
string zp_mv(int x,int y,int n)
{
    if(check(x,y,n))
    {
        string temp="";
        temp+=map[x][y];
        return temp;
    }
    int m=n/2;
    string s="";
    s+='(';
    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)
        {
            s+=zp_mv(x+i*m,y+j*m,m);
        }
    s+=')';
    return s;
}


int main(void){
  	ios::sync_with_stdio(0);
  	cin.tie(0);
    int N;
    cin >> N;
    for(int i=0;i<N;i++)
        cin >> map[i];
    answer=zp_mv(0,0,N);
    cout<<answer;
}