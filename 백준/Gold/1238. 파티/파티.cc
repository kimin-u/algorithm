#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m, x;
vector<vector<pair<int, int>>> graph, reverse_graph;

vector<int> dijkstra(int start, const vector<vector<pair<int, int>>>& g) {
    vector<int> dist(n + 1, 1e9);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    dist[start] = 0;
    pq.push({ 0, start });

    while (!pq.empty()) {
        int cost = pq.top().first;
        int now = pq.top().second;
        pq.pop();

        if (dist[now] < cost) continue;

        for (auto edge : g[now]) {
            int next = edge.first;
            int weight = edge.second;

            if (dist[next] > dist[now] + weight) {
                dist[next] = dist[now] + weight;
                pq.push({ dist[next], next });
            }
        }
    }
    return dist;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> x;
    graph.assign(n + 1, vector<pair<int, int>>());
    reverse_graph.assign(n + 1, vector<pair<int, int>>());

    for (int i = 0; i < m; i++) {
        int start, dest, cost;
        cin >> start >> dest >> cost;
        graph[start].push_back({ dest, cost });           
        reverse_graph[dest].push_back({ start, cost });   
    }

    vector<int> from_x = dijkstra(x, graph);
    vector<int> to_x = dijkstra(x, reverse_graph);

    int max_time = 0;
    for (int i = 1; i <= n; i++) {
        int round_trip = to_x[i] + from_x[i];
        max_time = max(max_time, round_trip);
    }

    cout << max_time << '\n';
    return 0;
}