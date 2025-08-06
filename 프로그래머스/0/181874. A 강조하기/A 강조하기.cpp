#include <string>
#include <vector>
#include <cctype>

using namespace std;

string solution(string myString) {
    string answer = "";
    for (auto c: myString){
        if (c=='a' || c=='A') answer+='A';
        else{
            answer+=(char)tolower(c);
        }
    }
    return answer;
}