#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int t;
int n, d, c;
vector<vector<pair<int, int>>> graph;
vector<int> dist;
int cnt = 0;
int ttime = 0;

void dijkstra(int c) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
	dist[c] = 0;
	pq.push({ 0,c });

	while (!pq.empty()) {
		int cost = pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		if (dist[cur] < cost) continue;
		for (int i = 0; i < graph[cur].size(); i++) {
			int next = graph[cur][i].first;
			int weight = graph[cur][i].second;

			if (dist[next] > dist[cur] + weight) {
				dist[next] = dist[cur] + weight;
				pq.push({ dist[next], next });
			}
		}

	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> t;
	while (t--) {
		cnt = 0; ttime = 0;
		cin >> n >> d >> c;
		graph.assign(n, vector<pair<int,int>>());
		dist.assign(n, 1e9);
		for (int i = 0; i < d; i++) {
			int a, b, s; cin >> a >> b >> s;
			graph[b - 1].push_back({ a - 1, s });
		}
		dijkstra(c-1);

		for (int i = 0; i < n; i++) {
			if (dist[i] != 1e9) {
				cnt++;
				ttime = max(ttime, dist[i]);
			}
		}

		cout << cnt << " " << ttime << "\n";

	}
}