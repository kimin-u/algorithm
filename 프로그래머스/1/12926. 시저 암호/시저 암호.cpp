#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    for (auto c: s){
        if (c>='A' && c<='Z'){
            int alpha = c-'A';
            alpha = (alpha+n)%26;
            answer += alpha + 'A';
        }
            
        else if (c>='a' && c<='z'){
            int alpha = c-'a';
            alpha = (alpha+n)%26;
            answer += alpha + 'a';
        }
        else
            answer+=c;
    }
    return answer;
}