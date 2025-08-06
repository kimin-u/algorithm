#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> solution(string my_string) {
    vector<string> answer;
    string tmp= my_string;
    for (int i=0; i<my_string.size(); i++){
        answer.push_back(tmp);
        tmp.erase(tmp.begin());
    }
    sort(answer.begin(), answer.end());
    return answer;
}