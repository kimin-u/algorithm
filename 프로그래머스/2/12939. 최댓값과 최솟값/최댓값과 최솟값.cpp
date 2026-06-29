#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    
    int max = -1e9;
    int min = 1e9;
    
    string tmp = "";
    for (int i=0; i<s.length(); i++){
        if ((s[i] == ' ')||(i==s.length()-1)){
            //이전까지 저장된 tmp의 값으로 판단
            if (i==s.length()-1){
                tmp += s[i];
            }
            int tmp_val = stoi(tmp);
            if (tmp_val < min){
                min = tmp_val;
            }
            if (tmp_val > max){
                max = tmp_val;
            }
            tmp = "";
        }
        else{
            tmp += s[i];
        }
    }
    
    answer += to_string(min);
    answer += ' ';
    answer += to_string(max);
    return answer;
}