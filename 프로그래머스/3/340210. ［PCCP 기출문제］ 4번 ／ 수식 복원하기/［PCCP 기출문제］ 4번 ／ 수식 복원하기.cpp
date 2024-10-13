#include <string>
#include <sstream>
#include <vector>
#include <iostream>

using namespace std;
string cal[3];
vector<string> solution(vector<string> expressions) {
    vector<string> answer;
    int base = 10;
    int mx = 1;
    for (string exp : expressions)
    {
        if (exp.back() == 'X')
        {
            answer.push_back(exp.substr(0, exp.size() - 1));

        }
        else if (base == 10)
        {
            bool isminus = true;
            int pos = 0;
            int st = 0;
            for (int i = 0; i < exp.size(); i++)
            {
                if (exp[i] == ' ')
                {
                    if(st!=-1){cal[pos++] = exp.substr(st, i - st);
                               st=-1;
                              }
                }
                else if (exp[i] == '+')
                    isminus = false;
                else if (exp[i] != '=' && exp[i] != '-') {
                    if (st < i - 2)st = i;
                }
            }
            cal[pos] = exp.substr(st, exp.size() - st);
            if (isminus)
            {
                int diff = cal[0].back() - cal[1].back();
                if (diff < 0) {
                    base = (cal[2].back() - '0')-diff;
                }
            }
            else {
                if ((cal[0].back() + cal[1].back()-'0') != cal[2].back()) {
                    base = cal[0].back()+cal[1].back()-'0'-cal[2].back();
                    
                }
                else if(cal[0].size()>1&&cal[1].size()>1&&cal[2].size()>2){
                    base = cal[0][0]+cal[1][0]-'0'-cal[2][1];
                }
            }

        }
        if (base == 10) {
            for (char c : exp)
            {
                if (c > '0' && c < '9')mx = max(mx, c - '0');
            }
            if (mx == 8)base = 9;
        }
    }
    for(string &s : answer)
    {
        char op;
        int num[2];
        stringstream ss(s);
        ss >> num[0] >> op >> num[1];
        
        if(base!=10||op=='+'&&(num[0]+num[1])<100&&max(num[0]%10+num[1]%10,num[0]/10+num[1]/10)<=mx||op=='-'&&num[0]%10>=num[1]%10){
        int val;
        if(num[0]>9)
            num[0]=num[0]/10*base+num[0]%10;
        if(num[1]>9)
            num[1]=num[1]/10*base+num[1]%10;
            if(op=='+'){
                val = num[0]+num[1];
            }
            else{
                val = num[0]-num[1];
            }
            int ans = 0;
            int n=1;
            while(val){
                ans+=val%base*n;
                val/=base;
                n*=10;
            }
            s+=to_string(ans);
        }
        else
            s+="?";
    }

    return answer;
}