#include <string>
#include <vector>

using namespace std;

int solution(string myString, string pat) {
    int answer = 0;
    string tmp ="";
    for (auto c: myString){
        if (c=='A') tmp += 'B';
        else tmp+='A';
    }
    
    // if (tmp.find(pat) != string::npos) answer =1;
    for (int i=0; i<myString.length()- pat.length()+1; i++){
        if (tmp.substr(i, pat.length()) == pat) {
            answer=1;
            break;
        }
    }
    return answer;
}