#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> visited;
vector<vector<pair<int,int>>> graph;
int far_node, max_dist;


void dfs(int i, int dist){
    visited[i] = 1;
    if (dist > max_dist) {
        max_dist = dist;
        far_node = i;
    }

    for (int idx=0; idx<graph[i].size(); idx++){
        int next = graph[i][idx].first;
        int cost = graph[i][idx].second;
        if (!visited[next])
            dfs(next, dist + cost);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin>>n;
    graph.assign(n,vector<pair<int,int>>());

    for (int i=0; i<n-1; i++){
        int a, b, c; cin>>a>>b>>c;
        graph[a-1].push_back({b-1,c});
        graph[b-1].push_back({a-1,c});
    }

    visited.assign(n, 0);
    max_dist = 0;
    dfs(0, 0);

    visited.assign(n, 0);
    max_dist = 0;
    dfs(far_node, 0);

    cout<<max_dist<<'\n';

}