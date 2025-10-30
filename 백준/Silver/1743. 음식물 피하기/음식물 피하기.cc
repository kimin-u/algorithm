#include <iostream>
#include <vector>

using namespace std;

int n,m,k;
vector<vector<int>> graph;
vector<vector<int>> visited;

vector<int> di = {-1,1,0,0};
vector<int> dj = {0,0,-1,1};

int dfs(int i, int j){
    visited[i][j] = 1;

    int size = 1;
    
    for (int dir = 0; dir<4; dir++){
        int ni = i + di[dir];
        int nj = j + dj[dir];

        if (ni<0 || ni>=n || nj<0 || nj>=m) continue;
        if (visited[ni][nj] == 0 && graph[ni][nj] == 1){
            size += dfs(ni,nj);
        }
    }
    return size;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin>>n>>m>>k;
    graph.assign(n, vector<int>(m,0));
    visited.assign(n, vector<int>(m,0));
    for (int i=0; i<k; i++){
        int r, c; cin>>r>>c; r--; c--;
        graph[r][c] = 1;
    }

    int maxv= 0;

    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            if (graph[i][j] == 1 && visited[i][j] == 0){
                maxv = max(maxv,dfs(i,j));
            }
        }
    }

    cout<<maxv;
}