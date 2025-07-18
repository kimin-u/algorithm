#include <string>
#include <vector>

using namespace std;
vector<vector<int>> graph;
vector<int> visited;

void dfs(int i){
    visited[i] = 1;
    
    for (int k=0; k<graph[i].size(); k++){
        int ni = graph[i][k];
        if (visited[ni] == 0) {
            dfs(ni);
        }
    }
}
int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    graph.assign(n,vector<int>());
    visited.assign(n,0);
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            if (i==j) continue;
            if (computers[i][j]==1)
                graph[i].push_back(j);
        }
    }
    
    for (int i=0; i<n; i++){
        if (visited[i] == 0){
            dfs(i);
            answer++;
        }
    }
    return answer;
}