#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<pair<int, int>> q;
    priority_queue<int, vector<int>, less<int>> pq;
    for (int i =0; i<priorities.size(); i++){
        q.push({i,priorities[i]});
        pq.push(priorities[i]);
    }
    while (!q.empty()){
        int idx = q.front().first;
        int priority = q.front().second;
        q.pop();
        if (priority == pq.top()){
            pq.pop();
            answer++;
            if (idx == location) {          
                return answer;
                
            }
        }
        else{
            q.push({idx,priority});
        }
    }
    
    return answer;
}