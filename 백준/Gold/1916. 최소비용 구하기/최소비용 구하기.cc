#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
vector<vector<pair<int, int>>> graph;
vector<int> dist;

void dijkstra(int start) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
	dist[start] = 0; 
	pq.push({ 0, start });

	while (!pq.empty()) {
		int cost = pq.top().first;
		int now = pq.top().second;
		pq.pop();
		if (dist[now] < cost) continue;

		for (auto edge : graph[now]) {
			int next = edge.first;
			int weight = edge.second;

			
			if (dist[next] > dist[now] + weight) {
				dist[next] = dist[now] + weight;
				pq.push({ dist[next], next });
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	graph.assign(n + 1, vector<pair<int, int>>());
	dist.assign(n + 1, 1e9);
	for (int i = 0; i < m; i++) {
		int start, dest, cost; cin >> start >> dest >> cost;
		graph[start].push_back({ dest,cost });
	}

	int start, end; cin >> start >> end;

	dijkstra(start);

	cout << dist[end];
}