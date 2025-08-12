#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    int cnt_bin = 0; int cnt_zero = 0;
    
    while (true){
        if (s=="1") break;
        cnt_bin++;
        int tmp;
        for (auto c: s){
            if (c=='0') cnt_zero++;
            else tmp++;
        }
        
        //upate s; 
        s.clear();
        while (tmp!=0){
            if (tmp%2==1){
                s+='1';
            }
            else s+='0';
            tmp/=2;
        }
    }
    answer.push_back(cnt_bin);
    answer.push_back(cnt_zero);
    return answer;
}