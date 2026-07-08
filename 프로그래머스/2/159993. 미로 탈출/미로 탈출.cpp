#include <string>
#include <vector>
#include <queue>

using namespace std;

int n, m;
int si, sj;
int ei, ej;
int li, lj;
vector<vector<char>> graph;
vector<vector<int>> visited;
vector<int> di = {-1,1,0,0};
vector<int> dj = {0,0,-1,1};

int bfs_l(int i, int j){
    //si, sj 에서 레버까지의 거리
    queue<pair<int, int>> q;
    visited[i][j] = 0;
    q.push({i,j});
    
    while (!q.empty()){
        int ci = q.front().first;
        int cj = q.front().second;
        q.pop();
        
        if (ci == li && cj == lj) return visited[ci][cj];
        
        for (int k=0; k<4; k++){
            int ni = ci + di[k];
            int nj = cj + dj[k];
            if (ni<0 || ni>=n || nj<0 || nj>=m) continue;
            
            if (visited[ni][nj] == 0 && graph[ni][nj] != 'X'){
                visited[ni][nj] =  visited[ci][cj] + 1;
                q.push({ni,nj});
            }
        }
    }
    return -1;
}

int bfs_e(int i, int j){
    //li, ljk 에서 end까지의 거리
    queue<pair<int, int>> q;
    visited[i][j] = 0;
    q.push({i,j});
    
    while (!q.empty()){
        int ci = q.front().first;
        int cj = q.front().second;
        q.pop();
        
        if (ci == ei && cj == ej) return visited[ci][cj];
        
        for (int k=0; k<4; k++){
            int ni = ci + di[k];
            int nj = cj + dj[k];
            if (ni<0 || ni>=n || nj<0 || nj>=m) continue;
            
            if (visited[ni][nj] == 0 && graph[ni][nj] != 'X'){
                visited[ni][nj] =  visited[ci][cj] + 1;
                q.push({ni,nj});
            }
        }
    }
    return -1;
}

int solution(vector<string> maps) {
    int answer = 0;
    
    n = maps.size();
    m = maps[0].size();
    graph.assign(n, vector<char>(m, ' '));
    visited.assign(n, vector<int>(m, 0));
    
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            graph[i][j] = maps[i][j];
            if (graph[i][j] == 'S'){
                si = i; sj = j;
            }
            else if (graph[i][j] == 'E'){
                ei = i; ej = j;
            }
            else if (graph[i][j] == 'L'){
                li = i; lj = j;
            }
        }
    }
    
    int tmp = bfs_l(si, sj);
    if (tmp == -1) return - 1;
    answer += tmp;
    visited.assign(n, vector<int>(m,0));
    tmp = bfs_e(li, lj);
    if (tmp == -1) return -1;
    answer += tmp;
    
    return answer;
}