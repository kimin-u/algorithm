#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
vector<vector<int>> graph;
vector<vector<int>> visited;
vector<int> di = { -1,1,0,0 };
vector<int> dj = { 0,0,-1,1 };

int bfs(int i, int j) {
	queue<pair<int, int>> q;
	visited[i][j] = 1;
	q.push({ i,j });
	int cnt = 1;
	while (!q.empty()) {
		int ci = q.front().first;
		int cj = q.front().second;
		q.pop();
		for (int k = 0; k < 4; k++) {
			int ni = ci + di[k];
			int nj = cj + dj[k];
			if (ni < 0 || ni >= n || nj < 0 || nj >= m) continue;

			if (visited[ni][nj] == -1 && graph[ni][nj] == 1) {
				q.push({ ni,nj });
				visited[ni][nj] = 1;
				cnt++;
			}
		}
	}
	return cnt;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	graph.assign(n, vector<int>(m, 0));
	visited.assign(n, vector<int>(m, -1));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> graph[i][j];
		}
	}
	int cnt = 0;
	int max = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (graph[i][j] == 1 && visited[i][j] == -1) {
				int tmp = bfs(i, j);
				if (max < tmp) max = tmp;
				cnt++;
			}
		}
	}

	cout << cnt << "\n" << max;

}