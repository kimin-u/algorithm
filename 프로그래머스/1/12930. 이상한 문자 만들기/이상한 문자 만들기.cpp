#include <string>
#include <vector>
#include <cctype>

using namespace std;

string solution(string s) {
    string answer = "";
    int idx = -1;
    for (auto c : s){
        if (c==' ' || c=='\n') {
            idx = -1;
            answer+=c;
        }
        else{
            idx++;
            if (idx %2 ==0)
                answer += toupper(c);
            else
                answer += tolower(c);
        }           
    }
    return answer;
}