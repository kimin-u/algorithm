#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    
    bool space = true;
    for (int i=0; i<s.length(); i++){
        if (s[i] == ' ') {
            answer += s[i];
            space = true; 
        }
        //단어의 첫 문자 판별하기
        else if (space){
            //숫자인지 문자인지?
            if (isdigit(s[i])){
                answer += s[i];
            }
            //문자라면
            else{
                if (islower(s[i])){
                    answer += toupper(s[i]);
                }
                else{
                    answer += s[i];
                }
            }
            space = false;
            continue;
        }
        
        //첫 문자가 아닌 경우
        else{
            //첫 문자가 아닌 경우
            //소문자면 소문자
            if (isupper(s[i])){
                answer += tolower(s[i]);
            }
            //대문자면 소문자로
            else{
                answer += s[i];
            }
        }
        //
        
        
    }
    return answer;
}