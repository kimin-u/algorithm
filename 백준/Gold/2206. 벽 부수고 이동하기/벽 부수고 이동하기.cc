#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

int n,m;
vector<vector<int>> graph;
vector<vector<vector<int>>> visited;
queue<pair<pair<int, int>, int>> q;
vector<int> di = {-1,1,0,0};
vector<int> dj = {0,0,-1,1};


void bfs(int i, int j){
    q.push({{i,j},0});
    visited[i][j][0] = 1;
    
    while (!q.empty()){
        int ci = q.front().first.first;
        int cj = q.front().first.second;
        int wall = q.front().second;
        q.pop();
        
        for(int k=0; k<4; k++){
            int ni = ci + di[k];
            int nj = cj + dj[k];

            if (ni <0 || ni >=n || nj <0 || nj>=m) continue;
            if (graph[ni][nj] == 0 && visited[ni][nj][wall] ==0){
                visited[ni][nj][wall] = visited[ci][cj][wall] + 1;
                q.push({{ni,nj}, wall});
            }
            if (graph[ni][nj] == 1 &&  wall ==0){
                visited[ni][nj][1] = visited[ci][cj][wall] + 1;
                q.push({{ni,nj}, 1});
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin>>n>>m;
    graph.assign(n, vector<int>(m));
    visited.assign(n, vector<vector<int>>(m, vector<int>(2,0)));
    for (int i=0; i<n; i++){
        string str; cin>>str;
        for (int j=0; j<m; j++){
            graph[i][j] = str[j] - '0';
        }
    }
    bfs(0,0);

    int ans0 = visited[n-1][m-1][0];
    int ans1 = visited[n-1][m-1][1];

    if(ans0 == 0 && ans1 == 0) {
        cout << -1;
    } else if(ans0 == 0) {
        cout << ans1;
    } else if(ans1 == 0) {
        cout << ans0;
    } else {
        cout << min(ans0, ans1);
    }
}