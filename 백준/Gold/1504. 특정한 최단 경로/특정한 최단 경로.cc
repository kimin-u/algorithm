#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, e;
vector<vector<pair<int, int>>> graph;


vector<int> dijkstra(int k) {
	vector<int> dist(n + 1, 1e9);
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
	return dist;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> e;
	graph.assign(n + 1, vector<pair<int, int>>());

	for (int i = 0; i < e; i++) {
		int a, b, c; cin >> a >> b >> c;
		graph[a].push_back({ b, c });
		graph[b].push_back({ a,c });
	}

	int v1, v2; cin >> v1 >> v2;

	vector<int> dist1 = dijkstra(1);
	vector<int> dist2 = dijkstra(v1);
	vector<int> dist3 = dijkstra(v2);

	int path1 = dist1[v1] + dist2[v2] + dist3[n];
	int path2 = dist1[v2] + dist3[v1] + dist2[n];

	int result = min(path1, path2);

	if (result >= 1e9 || result < 0) cout << "-1\n";
	else cout << result << "\n";


}