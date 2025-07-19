#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m, k, x;
vector<vector<int>> graph;

vector<int> dijkstra(int s) {
	vector<int> dist(n + 1, 1e9);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

	dist[s] = 0;
	pq.push({ 0, s });

	while (!pq.empty()) {
		int cost = pq.top().first;
		int now = pq.top().second;
		pq.pop();

		if (cost > dist[now]) continue;
		for (int next : graph[now]) {
			if (dist[next] > dist[now] + 1) {
				dist[next] = dist[now] + 1;
				pq.push({ dist[next], next });
			}
		}
	}

	return dist;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> m >> k >> x;
	graph.assign(n+1, vector<int>());

	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		graph[a].push_back(b);
	}

	vector<int> dist = dijkstra(x);
	bool found = false;
	for (int i = 1; i <= n; i++) {
		if (dist[i] == k) {
			cout << i << "\n";
			found = true;
		}
	}
	if (!found) cout << -1 << "\n";
}