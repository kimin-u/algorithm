#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

bool compare(vector<string> a, vector<string> b){
    int time_a = stoi(a[1]);
    int time_b = stoi(b[1]);
    
    return time_a < time_b;
}
    
int toTime(string time){
    int ret=0;
    
    string hh = time.substr(0,2);
    string mm = time.substr(3,2);
    
    ret += stoi(hh) * 60;
    ret += stoi(mm);
    
    return ret;
}

vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;

    for (auto &plan : plans){
        plan[1] = to_string(toTime(plan[1]));        
    }
    
    sort(plans.begin(), plans.end(), compare);
    
    stack<pair<string, int>> st;
    
    for (int i=0; i<plans.size()-1; i++){
        string name = plans[i][0];
        int start = stoi(plans[i][1]);
        int playtime = stoi(plans[i][2]);
        
        int next_start = stoi(plans[i+1][1]);
        int gap = next_start - start;
        
        if (gap >= playtime){
            //완료되는경우
            answer.push_back(name);
            gap -= playtime; 
            
            while (!st.empty() && gap > 0){
                //다른 과제 진행
                pair<string, int>& top = st.top();
                
                if (top.second <= gap){
                    gap -= top.second;
                    answer.push_back(top.first);
                    st.pop();
                }
                else{
                    top.second -= gap;
                    gap = 0;
                }
            }
        }
        else{
            playtime -= gap;
            st.push({name, playtime});
        }
        
    }
    answer.push_back(plans.back()[0]);
    
    while (!st.empty()){
        answer.push_back(st.top().first);
        st.pop();
    }
    return answer;
}