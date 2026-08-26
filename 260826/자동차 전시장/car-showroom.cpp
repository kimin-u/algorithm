#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>


using namespace std;

int n, m, k;
vector<pair<int, int>> edges;
vector<int> start_points;
vector<vector<int>> dists;
vector<vector<int>> adj;

void dijkstra(int start, int i){
    queue<int> q;
    q.push(start);
    dists[i][start]= 0;

    while (!q.empty()){
        int cur = q.front();
        q.pop();

        for (int end : adj[cur]){   // cur에서 출발하는 간선만 바로 순회
            if (dists[i][end] > dists[i][cur] + 1){
                dists[i][end] = dists[i][cur] + 1;
                q.push(end);
            }
        }
    }
}

int main() {
    cin >> n >> m >> k;
    
    dists.assign(k,vector<int>(n, 1e9));
    edges.resize(m);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        edges[i] = {x, y};
    }

    start_points.resize(k);
    for (int i = 0; i < k; i++) {
        cin >> start_points[i];
        start_points[i]--;
    }

    adj.assign(n, vector<int>());
    for (int i = 0; i < m; i++) {
        adj[edges[i].first].push_back(edges[i].second);
    }
    // Please write your code here.
    for (int i=0; i<k; i++){
        dijkstra(start_points[i], i);
    }

    vector<int> answer(n,-1e9);

    for (auto &dist : dists){
        for(int i=0; i<n; i++){
            answer[i] = max(answer[i], dist[i]);
        }
    }

    int ans = *min_element(answer.begin(), answer.end());
    if (ans == 1e9){
        cout<<"-1";
    }
    else{
        cout<<ans;
    }

    return 0;
}
