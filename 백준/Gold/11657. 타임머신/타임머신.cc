#include <iostream>
#include <vector>
using namespace std;

const long long INF = 1e18; 
int n, m;
vector<long long> dist;
vector<vector<pair<int, int>>> graph;

bool bellmanford(int start) {
    dist[start] = 0;

    for (int t = 1; t <= n - 1; t++) {
        for (int u = 1; u <= n; u++) {
            if (dist[u] == INF) continue;
            for (auto& edge : graph[u]) {
                int v = edge.first;
                int cost = edge.second;

                if (dist[v] > dist[u] + cost) {
                    dist[v] = dist[u] + cost;
                }
            }
        }
    }

    for (int u = 1; u <= n; u++) {
        if (dist[u] == INF) continue;
        for (auto& edge : graph[u]) {
            int v = edge.first;
            int cost = edge.second;

            if (dist[v] > dist[u] + cost) {
                return false;
            }
        }
    }

    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    dist.assign(n + 1, INF);
    graph.assign(n + 1, vector<pair<int, int>>());

    for (int i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c;
        graph[a].push_back({ b, c });
    }

    if (!bellmanford(1)) {
        cout << -1 << '\n';
    }
    else {
        for (int i = 2; i <= n; i++) {
            if (dist[i] == INF) cout << -1 << '\n';
            else cout << dist[i] << '\n';
        }
    }
}
