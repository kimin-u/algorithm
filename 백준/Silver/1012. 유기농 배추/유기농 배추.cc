#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int t, n, m, k;
vector<vector<int>> graph;
vector<vector<int>> visited;

vector<int> di = { -1, 1, 0, 0 };
vector<int> dj = { 0,0,-1,1 };

void bfs(int i, int j) {
	queue<pair<int, int>> q;
	q.push({ i,j });
	visited[i][j] = 1;

	while (!q.empty()) {
		int ci = q.front().first;
		int cj = q.front().second;
		q.pop();

		for (int d = 0; d < 4; d++) {
			int ni = ci + di[d];
			int nj = cj + dj[d];
			if (ni < 0 || ni >= n || nj < 0 || nj >= m) continue;

			if (visited[ni][nj] == 0 && graph[ni][nj] == 1) {
				q.push({ ni,nj });
				visited[ni][nj] = 1;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> t;

	while (t--) {
		int cnt = 0;
		cin >> m >> n >> k;
		graph.assign(n, vector<int>(m, 0));
		visited.assign(n, vector<int>(m, 0));

		while (k--) {
			int x, y; cin >> x >> y;
			graph[y][x] = 1;
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (visited[i][j] == 0 && graph[i][j] == 1) {
					bfs(i, j);
					cnt++;
				}
			}
		}
		cout << cnt << "\n";

	}
}