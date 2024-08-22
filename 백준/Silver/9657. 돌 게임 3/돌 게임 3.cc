#include<iostream>
#include<string>
using namespace std;

int N;
bool arr[1001];
int stone[3][3] = {
    {2,4,5},
    {4,6,7},
    {5,7,8},
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    arr[1] = true;
    arr[2] = false;
    for (int i = 3; i <= N; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            bool SK = true;
            for (int k = 0; k < 3; k++)
            {
                if (i < stone[j][k])break;
                
                if (i==stone[j][k]||!arr[i - stone[j][k]])
                    SK=false;
            }
            arr[i] = SK;
            if (SK)
                break;
        }
    }
    if (arr[N])
        cout << "SK";
    else
        cout << "CY";
    
}
