#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> dist;

void dijkstra(int N, vector<vector<int>> &graph){
    priority_queue< pair<int, int>, vector<pair<int, int>>, greater<> > pq;
    pq.push({0, 1});
    dist[1] = 0;
    
    while (!pq.empty()){
        int cost = pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        
        if (cost > dist[cur]) continue;
        
        for (int i=0; i<graph.size(); i++){
            int a = graph[i][0], b = graph[i][1], weight = graph[i][2];
            int end = -1;
            if (a == cur) end = b;
            else if (b == cur) end = a;
            else continue;
            
            if (dist[end] > dist[cur] + weight){
                dist[end] = dist[cur] + weight;
                pq.push({dist[end], end});
            }
        }
    }
    
}


int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;

    dist.assign(N+1,1e9);
    
    dijkstra(N, road);
    
    for (auto &d: dist){
        if (d <= K){
            answer++;
        }
    }
    
    return answer;
}