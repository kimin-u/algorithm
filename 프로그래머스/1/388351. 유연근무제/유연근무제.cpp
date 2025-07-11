#include <string>
#include <vector>

using namespace std;

int toMinutes(int time) {
    return (time / 100) * 60 + (time % 100);
}

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int answer = 0;
    int n = schedules.size();
    int sat =( 6-startday + 7)%7;
    int sun = (sat+1)%7;
    for (int i=0; i<n; i++){
        int limit = toMinutes(schedules[i]) + 10;
        int flag = true;
        for (int j=0; j<timelogs[i].size(); j++){
            if (j == sat || j == sun) continue;
            int log_time = toMinutes(timelogs[i][j]);
            if (log_time > limit) {
                flag = false;
                break;
            }
        }
        if (flag) answer++;
        
    }
    return answer;
}