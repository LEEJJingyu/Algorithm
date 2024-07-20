#include<iostream>
using namespace std;
long long pow(long long expo,long long base,long long value)
{
    if(expo==1)return base%value;
    long long val=pow(expo/2,base,value)%value;
    val = (val*val)%value;
    if(expo%2==0){
        return val;
    }
    return (val*base)%value;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
	long long A,B,C;
    cin>>A>>B>>C;
    cout<<pow(B,A,C);
}