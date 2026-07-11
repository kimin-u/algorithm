#include <string>
#include <algorithm>
#include <vector>

using namespace std;

string to_binary(int num){
    string ret="";
    
    while (true){
        if (num == 0) break;
        
        if (num%2==0) ret+='0';
        else{
            ret += '1';
        }
        num/=2;
    }
    reverse(ret.begin(), ret.end());
    
    return ret;
}

vector<int> solution(string s) {
    vector<int> answer;
    
    int whileloopcnt = 0;
    int zerocnt = 0;
    while(true){
        int onecnt=0;
        for (auto& c: s){
            if (c == '1'){
                onecnt++;
            }
        }
        
        if (s=="1") break;
        
        whileloopcnt++;
        int tmpzero = s.length() - onecnt;
        zerocnt += tmpzero;
        s = to_binary(onecnt);
    }
    
    
    answer.push_back(whileloopcnt);
    answer.push_back(zerocnt);
    return answer;
}