#include <string>
#include <vector>

using namespace std;

vector<int> visited;

int dfs(int i, int k, vector<vector<int>> &graph){
    //k: 남은 피로도
    int ret = 0;
    
    for (int next = 0; next < graph.size(); next++){
        if (next == i) continue;
        if (visited[next] == 0){
            if (k >= graph[next][0]){
                visited[next] = 1;
                ret = max(ret, dfs(next, k-graph[next][1], graph));
                visited[next] = 0;
            }
        }
    }
    
    return 1+ret;
    
}


int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    
    int n = dungeons.size();
    visited.assign(n, 0);
    answer = -1e9;
    for (int i=0; i<n; i++){
        if (k >= dungeons[i][0]){
            visited[i] = 1;
            answer = max(answer,dfs(i, k-dungeons[i][1], dungeons));
            visited[i] = 0;    
        }
    }
    return answer;
}