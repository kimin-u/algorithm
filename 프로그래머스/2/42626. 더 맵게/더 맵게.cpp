#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> min_pq;
    
    for (int i=0; i<scoville.size(); i++){
        min_pq.push(scoville[i]);
    }
    
    while (true){
        if (min_pq.top() >=K) break;
        answer++;
        if (min_pq.size()<2) return -1;
        int first = min_pq.top(); min_pq.pop();
        int second = min_pq.top(); min_pq.pop();
        int next = first + second*2;
        min_pq.push(next);
    }
    return answer;
}