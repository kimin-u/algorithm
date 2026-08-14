#include <string>
#include <vector>
#include <algorithm>


using namespace std;

int int2time(int time){
    string hh = to_string(time / 100);
    string mm = to_string(time % 100);
    
    int h = stoi(hh) * 60;
    int ret = h + stoi(mm);
    
    return ret;
}


int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int answer = 0;
    
    vector<int> exception;
    if (6-startday >= 0 ){
        exception.push_back(6-startday);
    }
    else{
        exception.push_back(6);
    }
    exception.push_back(7-startday);
    
    
    int n = schedules.size();
    for (int i=0; i<n; i++){
        int flag = 1;
        int pivot = int2time(schedules[i]);
        for (int day = 0; day < timelogs[i].size(); day++){
            if (find(exception.begin(), exception.end(), day) != exception.end()){
                continue;
            }
            int log = int2time(timelogs[i][day]);
            
            if (log > pivot + 10){
                flag = 0;
                break;
            }
        }
        if (flag){
            answer++;
        }
    }
    
    return answer;
}