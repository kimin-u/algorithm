#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int n, m;
vector<vector<int>> graph;
int cnt = 0;
vector<int> di = { -1,1,0,0 };
vector<int> dj = { 0,0,-1,1 };
vector<vector<int>> dist;

void bfs(int i, int j) {
	//q : i,j 랑 여태 부신 벽의 개수.
	priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
	pq.push({ cnt, {i,j} });
	dist[i][j] = 0;

	while (!pq.empty()) {
		int cost = pq.top().first;
		int ci = pq.top().second.first;
		int cj = pq.top().second.second;
		pq.pop();
		if (ci == n - 1 && cj == m - 1) return;
		if (cost > dist[ci][cj]) continue;

		for (int k = 0; k < 4; k++) {
			int ni = ci + di[k];
			int nj = cj + dj[k];
			if (ni < 0 || ni >= n || nj < 0 || nj >= m) continue;

			int nextcost = cost + graph[ni][nj];
			if (nextcost < dist[ni][nj]) {
				dist[ni][nj] = nextcost;
				pq.push({ nextcost, {ni,nj} });
			}

		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> m >> n;
	graph.assign(n, vector<int>(m));
	dist.assign(n, vector<int>(m, 1e9));
	for (int i = 0; i < n; i++) {
		string str; cin >> str;
		for (int j = 0; j < m; j++) {
			graph[i][j] = str[j] - '0';
		}
	}
	
	bfs(0, 0);
	cout << dist[n - 1][m - 1];
}