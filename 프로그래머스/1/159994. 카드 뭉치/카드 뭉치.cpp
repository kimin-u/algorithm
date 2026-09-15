#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "";
    
    int idx1= 0;
    int idx2= 0;
    
    for (int i=0; i<goal.size(); i++){
        string pivot = goal[i];
        
        bool flag = false;
        if (idx1 < cards1.size() && cards1[idx1] == pivot){
            idx1++;
            flag = true;
        }
        else if (idx2 < cards2.size() && cards2[idx2] == pivot){
            idx2++;
            flag = true;
        }
        
        if (!flag) {
            return "No";
        }
    }
    
    answer = "Yes";
    return answer;
}