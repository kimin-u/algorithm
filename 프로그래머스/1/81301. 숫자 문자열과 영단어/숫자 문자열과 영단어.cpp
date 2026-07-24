#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;

    
    string tmp_answer = "";
    
    for (int i=0; i<s.length(); i++){
        //애초에 숫자인지
        char tmp = s[i];
        
        if ( (tmp-'0') >= 0 && (tmp-'0')  <= 9){
            tmp_answer += tmp;
        }
        
        else{
            //문자인 경우
            if (tmp == 'z'){
                tmp_answer += "0";
                i+=3;
                continue;
            }
            else if (tmp == 'o'){
                tmp_answer += "1";
                i+=2;
                continue;
            }
            else if (tmp == 'e'){
                tmp_answer += "8";
                i+=4;
                continue;
            }
            else if (tmp == 'n'){
                tmp_answer += "9";
                i+=3;
                continue;
            }
            else {
                if (tmp == 't'){
                    if (s[i+1] == 'w'){
                        tmp_answer += "2";
                        i+=2;
                        continue;
                    }
                    else if (s[i+1] == 'h'){
                        tmp_answer += "3";
                        i+=4;
                        continue;
                        
                    }
                }
                else if (tmp == 'f'){
                    if (s[i+1] == 'o'){
                        tmp_answer += "4";
                        i+=3;
                        continue;
                    }
                    else if (s[i+1] == 'i'){
                        tmp_answer += "5";
                        i+=3;
                        continue;
                    }
                }
                else if (tmp == 's'){
                    if (s[i+1] == 'i'){
                        i+=2;
                        tmp_answer += "6";
                        continue;
                    }
                    else if (s[i+1] == 'e'){
                        tmp_answer += "7";
                        i+=4;
                        continue;
                    }
                }
            }
        }
    }
    
    answer  = stoi(tmp_answer);
    return answer;
}