#include <string>
#include <vector>

using namespace std;

vector<int> visited;

void dfs(int i, vector<vector<int>> &computers){
    visited[i] = 1;
    
    for (int next = 0; next<computers[i].size(); next++){
        if (next == i) continue;
        if (computers[i][next] == 0) continue;
        if (visited[next] == 0){
            dfs(next, computers);
        }
    }
    
    
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    visited.assign(n, 0);
    
    for (int i=0; i<n; i++){
        if (visited[i] == 0){
            dfs(i, computers);
            answer++;
        }
    }
    
    return answer;
}