#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m, v;
vector<vector<int>> graph;
vector<int> visited_dfs;
vector<int> visited_bfs;
vector<int> result_dfs;
vector<int> result_bfs;

void dfs(int start){
    visited_dfs[start] = 1;
    result_dfs.push_back(start);
    for (int i = 0; i < graph[start].size(); i++){
        int nxt = graph[start][i];
        if (visited_dfs[nxt] == 0) {
            dfs(nxt);
        }
    }
}

void bfs(int start){
    queue<int> q;
    visited_bfs[start] = 1;
    q.push(start);
    result_bfs.push_back(start);
    while (!q.empty()){
        int cur = q.front(); q.pop();

        for (int i=0; i<graph[cur].size(); i++){
            int nxt = graph[cur][i];
            if (visited_bfs[nxt] == 0){
                visited_bfs[nxt] =1;
                q.push(nxt);
                result_bfs.push_back(nxt);
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> v;

    graph.assign(n, vector<int>());

    for (int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for (int i = 0; i < n; i++) {
        sort(graph[i].begin(), graph[i].end());
    }

    visited_dfs.assign(n,0);
    visited_bfs.assign(n,0);

   dfs(v - 1);
   bfs(v - 1);

   for (auto v: result_dfs){
    cout<<v+1<<" ";
   }
   cout<<'\n';
   for (auto v: result_bfs){
    cout<< v+1<< " ";
   }

}