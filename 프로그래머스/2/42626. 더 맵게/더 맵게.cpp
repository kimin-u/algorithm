#include <string>
#include <vector>
#include <queue>

using namespace std;

struct compare{
    bool operator() (int a, int b){
        return a>b;
    }   
};

int solution(vector<int> scoville, int k) {
    int answer = 0;
    priority_queue<int, vector<int>, compare> min_pq;
    
    for (auto &scov :scoville){
        min_pq.push(scov);
    }
    
    while (true){
        if (min_pq.top() >= k) break;
        if (min_pq.size() == 1) return -1;
        int a = min_pq.top(); min_pq.pop();
        int b = min_pq.top(); min_pq.pop();
        int tmp = a + b*2;
        min_pq.push(tmp);
        answer++;
    }
    return answer;
}