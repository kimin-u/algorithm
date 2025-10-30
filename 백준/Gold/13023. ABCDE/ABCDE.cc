#include <iostream>
#include <vector>

using namespace std;

int n,m;
vector<vector<int>> graph;
vector<int> visited;
bool found = false;

void dfs(int s, int depth){
    if (depth == 5) {
        found = true;
        return ;
    }

    visited[s] = 1;

    for (int i =0; i< graph[s].size(); i++){
        int next=  graph[s][i];
        if (visited[next] == 0){
            dfs(next, depth + 1);
            if (found) return;
        }
    }

    visited[s] = 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin>>n>>m;
    graph.assign(n,vector<int>());
    visited.assign(n, 0);
    for(int i=0; i<m; i++){
        int a,b; cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for (int i = 0; i < n; i++) {
        dfs(i, 1);
        if (found) break;
    }

    cout << (found ? 1 : 0);

}