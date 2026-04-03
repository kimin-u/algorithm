#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> graph;
vector<vector<int>> visited;
vector<int> di = {-1,1,0,0};
vector<int> dj = {0,0,-1,1};

int n,m;

void tmp_bfs(int a, int b){
    queue<pair<int, int>> q;
    q.push({a,b});
    visited[a][b] = 1;

    while (!q.empty()){
        int ci = q.front().first;
        int cj = q.front().second;
        q.pop();

        for (int k=0; k<4; k++){
            int ni = ci + di[k];
            int nj = cj + dj[k];

            if (ni<0 || ni>=n || nj<0 || nj>=m) continue;

            if (graph[ni][nj]==0) continue;
            if (visited[ni][nj] == 0){
                visited[ni][nj] = 1;
                q.push({ni,nj});
            }
        }

        
    }
}

int bfs(){
    queue<pair<int, int>> q;
    vector<vector<int>> tmp_graph(n, vector<int>(m,0));
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            tmp_graph[i][j] = graph[i][j];
            if (graph[i][j] != 0){
                q.push({i,j});
            }
        }
    }

    while (!q.empty()){
        int ci = q.front().first;
        int cj = q.front().second;
        q.pop();

        int tmp_cnt = 0;
        for (int k=0; k<4; k++){
            int ni = ci + di[k];
            int nj = cj + dj[k];

            if (ni<0 || ni>=n || nj<0 || nj>=m) continue;

            if (tmp_graph[ni][nj] == 0) tmp_cnt++;
        }
        graph[ci][cj] -= tmp_cnt;
        if (graph[ci][cj] < 0) graph[ci][cj] = 0;
    }

    //영역 개수 세는 for 2중 loop 필요/
    int ret = 0;
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            if (graph[i][j]!=0 && visited[i][j] == 0){
                ret++;
                tmp_bfs(i,j);
            }
        }
    }

    //영역 개수 return
    return ret;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin>>n>>m;
    graph.assign(n, vector<int>(m,0));

    for (int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>graph[i][j];
        }
    }

    int answer = 1;
    while (true){
        visited.assign(n, vector<int>(m,0));

        int result = bfs();
        if (result >= 2) {
            cout<<answer;
            return 0;
        }
        else if (result == 0){
            cout<< 0;
            return 0;
        }
        answer++;
    }
}