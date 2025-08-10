#include <vector>
#include <queue>
using namespace std;

vector<int> di = {-1,1,0,0};
vector<int> dj = {0,0,-1,1};
vector<vector<int>> visited;
int n,m;

int bfs(int i, int j, vector<vector<int>> maps){
    queue<pair<pair<int, int>, int>> q;
    visited[i][j] = 1;
    q.push({{i,j}, 1});
    
    while(!q.empty()){
        int ci = q.front().first.first;
        int cj = q.front().first.second;
        int distance = q.front().second;
        q.pop();
        if (ci == n-1 && cj ==m-1){
            return distance;
        }
        
        for (int k=0; k<4; k++){
            int ni = ci+di[k];
            int nj = cj+dj[k];
            if (ni <0 || ni >=n || nj <0 || nj>=m) continue;
            
            if (visited[ni][nj] == 0 && maps[ni][nj] == 1){
                visited[ni][nj]=1;
                q.push({{ni,nj},distance+1});
            }
        }
    }
    return -1;
}
int solution(vector<vector<int>> maps)
{
    int answer = 0;
    n = maps.size();
    m = maps[0].size();
    visited.assign(n,vector<int>(m,0));
    answer = bfs(0,0, maps);
    return answer;
}