#include <iostream>
#include <vector>

using namespace std;

int n, m;
int cnt = 0;
vector<vector<int>> graph;
vector<int> visited;

void dfs(int i) {
	visited[i] = 1;

	for (int k = 0; k < graph[i].size(); k++) {
		int next = graph[i][k];
		if (visited[next] == 0) dfs(next);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	graph.assign(n, vector<int>());
	visited.assign(n, 0);
	for (int i = 0; i < m; i++) {
		int u, v; cin >> u >> v;
		graph[u - 1].push_back(v - 1);
		graph[v - 1].push_back(u - 1);
	}

	for (int i = 0; i < n; i++) {
		if (visited[i] == 0) {
			dfs(i);
			cnt++;
		}
	}

	cout << cnt;

}