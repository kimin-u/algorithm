#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n,m;
vector<vector<int>> graph;
vector<int> visited;
int answer;

void bfs(int s){
    queue<int> q;
    q.push(s);
    visited[s] = 1;
    answer = 0; 

    for (int i=0; i<graph[s].size(); i++){
        int next = graph[s][i];
        if (visited[next] == 0){
            visited[next] = 1;
            answer++;
        }
        
        for (int j =0; j<graph[next].size(); j++){
            int nextnext = graph[next][j];
            if (visited[nextnext] == 0){
                visited[nextnext] = 1;
                answer++;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin>>n>>m;
    visited.assign(n,0);
    graph.assign(n,vector<int>());
    for(int i=0; i<m; i++){
        int a,b; cin>>a>>b;
        graph[a-1].push_back(b-1);
        graph[b-1].push_back(a-1);
    }

    bfs(0);
    cout<<answer;
}