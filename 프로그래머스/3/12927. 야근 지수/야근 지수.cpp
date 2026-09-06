#include <string>
#include <vector>
#include <iostream>
#include <queue>

typedef long long ll;

using namespace std;

struct compare{
    bool operator() (pair<int, int> a, pair<int, int> b){
        return a.first < b.first;
    }
};

ll solution(int n, vector<int> works) {
    ll answer = 0;
    priority_queue<pair<int,int>, vector<pair<int, int>>, compare> pq;
    
    for (int i=0; i<works.size(); i++){
        pq.push({works[i], i});
    }
    
    for (int i=0; i<n; i++){
        if (pq.empty()) break;
        int work = pq.top().first;
        int idx = pq.top().second;
        pq.pop();
        
        if (work-1 > 0){
            pq.push({work-1, idx});    
        }
        
    }
    
    while (!pq.empty()){
        int work = pq.top().first;
        pq.pop();
        
        answer += (work*work);
    }
    
    return answer;
}