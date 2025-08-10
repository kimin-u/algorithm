#include <string>
#include <vector>
#include <algorithm>

using namespace std;
bool compare(int a, int b){
    return a>b;
}

string solution(string X, string Y) {
    string answer = "";
    vector<int> vec;
    string tmp;
    vector<int> count_x(10,0);
    vector<int> count_y(10,0);
    for (auto x: X)
        count_x[x-'0']++;
    for (auto y: Y)
        count_y[y-'0']++;
    
    for (int i=9; i>=0; i--){
        while (count_x[i] > 0 && count_y[i]>0){
            count_x[i]--;
            count_y[i]--;
            answer+=to_string(i);
        }
    }
    
    if (answer == ""){
        answer="-1";
    }
    if (answer[0] == '0') 
        answer="0";
    
    return answer;
}