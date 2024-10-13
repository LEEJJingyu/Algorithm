#include <string>
#include <cstring>
#include <sstream>
#include <vector>
#include <unordered_map>

using namespace std;
vector<string> solution(vector<string> record) {
    unordered_map<string,string> dict;
    int n = 0;
    vector<string> answer;
    for(string s : record){
        stringstream ss(s);
        if(s[0]=='E'){
            string cmd, id, nick;
            ss>>cmd>>id>>nick;
            dict[id]=nick;
            answer.push_back(cmd+" "+id);
        }
        else if(s[0]=='C'){
            string cmd, id, nick;
            ss>>cmd>>id>>nick;
            dict[id]=nick;
        }
        else{
            string cmd, id;
            ss>>cmd>>id;
            answer.push_back(cmd+" "+id);
        }
        
    }
    for(string& s : answer){
        stringstream ss(s);
        string cmd, id;
        ss>>cmd>>id;
        if(cmd=="Enter")
            s=dict[id]+"님이 들어왔습니다.";
        else
            s=dict[id]+"님이 나갔습니다.";
    }
    
    return answer;
}