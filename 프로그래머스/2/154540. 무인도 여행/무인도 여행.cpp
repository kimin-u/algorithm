#include <string>
#include <vector>
#include <queue>
#include <algorithm>


using namespace std;

int n,m;
vector<vector<int>> visited;
vector<vector<char>> graph;

vector<int> di = {-1,1,0,0};
vector<int> dj = {0,0,-1,1};

int bfs(int i, int j){
    queue<pair<int, int>> q;
    q.push({i,j});
    visited[i][j] = 1;
   
    int ret = graph[i][j]- '0';
    
    while (!q.empty()){
        int ci = q.front().first;
        int cj = q.front().second;
        q.pop();
        
        for (int k=0; k<4; k++){
            int ni = ci + di[k];
            int nj = cj + dj[k];
            
            if (ni<0 || ni>=n || nj<0 || nj>=m) continue;
            
            if (graph[ni][nj] != 'X' && visited[ni][nj] == 0){
                visited[ni][nj] =1;
                q.push({ni, nj});
                ret += (graph[ni][nj] - '0');
            }
        }
    }
    
    return ret;
}

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    
    n = maps.size();
    m = maps[0].size();
    visited.assign(n, vector<int>(m, 0));
    graph.assign(n, vector<char>(m, ' '));
    
    for (int i=0; i<n; i++){
        string tmp = maps[i];
        for (int j=0; j<m; j++){
            graph[i][j] = maps[i][j];
        }
    }
    
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            if (graph[i][j] != 'X' && visited[i][j] ==0){
                int tmp = bfs(i,j);
                answer.push_back(tmp);
            }
        }
    }

    if (answer.empty()){
        answer.push_back(-1);
    }
    else{
        sort(answer.begin(), answer.end());
    }
    
    
    
    return answer;
}