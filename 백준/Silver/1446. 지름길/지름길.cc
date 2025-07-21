#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, d;
vector<vector<pair<int, int>>> graph;
vector<int> dist;

void dijkstra() {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
	dist[0] = 0;
	pq.push({ 0, 0 }); // {거리, 위치}

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

	cin >> n >> d;
	graph.assign(d + 1, vector<pair<int, int>>());
	dist.assign(d + 1, 1e9);

	for (int i = 0; i < d; i++) {
		graph[i].push_back({ i + 1, 1 });
	}

	for (int i = 0; i < n; i++) {
		int a, b, c; cin >> a >> b >> c;
		if (b <= d && (b - a > c)) {
			graph[a].push_back({ b, c });
		}
	}

	dijkstra();

	cout << dist[d];
}