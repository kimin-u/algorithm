#include <string>
#include <vector>

using namespace std;

bool solution(string s) {
    bool answer = true;
    if (s.length() != 4 && s.length() != 6) 
        return false;
    
    for (auto c: s){
        if (c-'0' < 0 || c-'0' >9 ) return false;
    }
    return answer;
}