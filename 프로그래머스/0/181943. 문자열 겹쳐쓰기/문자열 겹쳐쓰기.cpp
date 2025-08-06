#include <string>
#include <vector>

using namespace std;

string solution(string my_string, string overwrite_string, int s) {
    string answer = "";
    for (int i=0; i<s; i++){
        answer+=my_string[i];
    }
    for (auto s : overwrite_string){
        answer += s;
    }
    int left= my_string.length() - s - overwrite_string.length();
    if (left <=0) return answer;
    for (int i = s+overwrite_string.length(); i < my_string.length(); i++){
        answer+=my_string[i];
    }
    return answer;
}