#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    //작업의 진도 progresses //작업별 속도 speeds
    vector<int> answer;
    int num = progresses.size();
    
    int current = 0;
    queue<int> q;
    while (true){
        for (int i=0; i<num; i++){
            progresses[i] += speeds[i];
        }
        
        if (progresses[current] >=100){
            for (int i = current; i<num; i++){
                if (progresses[i] >= 100)
                    q.push(i);
                else break;
            }
        }
        
        if (!q.empty()){
            answer.push_back(q.size());
            current += q.size();
            while (!q.empty()){
                q.pop();
            }
        }
        if (current >=num) break;        
    }
    return answer;
}