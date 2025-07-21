#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int v, e, k;
vector<vector<pair<int, int>>> graph;
vector<int> dist;

void dijkstra(int k) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
	dist[k] = 0;
	pq.push({ 0,k });

	while (!pq.empty()) {
		int cost = pq.top().first;
		int now = pq.top().second;
		pq.pop();

		if (dist[now] < cost) continue;
		
		for (int i = 0; i < graph[now].size(); i++) {
			int next = graph[now][i].first;
			int weight = graph[now][i].second;

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

	cin >> v >> e >> k;
	graph.assign(v + 1, vector<pair<int, int>>());
	dist.assign(v + 1, 1e9);

	for (int i = 0; i < e; i++) {
		int s, d, w; cin >> s >> d >> w;
		graph[s].push_back({ d,w });
	}

	dijkstra(k);

	for (int i = 1; i < dist.size(); i++) {
		if (dist[i] == 1e9) {
			cout << "INF" << "\n";
		}
		else {
			cout << dist[i] << "\n";
		}
	}
}