#include <iostream>
#include <vector>
#include <queue>

using namespace std;


vector<vector<int>> graph;
vector<int> visited_dfs;
vector<int> visited_bfs;
vector<int> result_dfs;
vector<int> result_bfs;

void dfs(int i) {
	visited_dfs[i] = 1;
	result_dfs.push_back(i);
	for (int j = 1; j < graph[i].size(); j++) {
		if (graph[i][j] != 1 || visited_dfs[j] == 1) continue;
		dfs(j);
	}
}

void bfs(int i) {
	queue<int> q;
	visited_bfs[i] = 1;
	result_bfs.push_back(i);
	q.push(i);
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		for (int j = 1; j < graph[cur].size(); j++) {
			if (graph[cur][j] != 1 || visited_bfs[j] == 1) continue;
			q.push(j);
			visited_bfs[j] = 1;
			result_bfs.push_back(j);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n, m, v; cin >> n >> m >> v;

	graph.assign(n + 1, vector<int>(n + 1, -1));
	visited_dfs.assign(n + 1, 0);
	visited_bfs.assign(n + 1, 0);
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		graph[a][b] = 1;
		graph[b][a] = 1;
	}
	dfs(v); bfs(v);
	for (int i = 0; i < result_dfs.size(); i++) {
		if (i == result_dfs.size() - 1)
			cout << result_dfs[i] << "\n";
		else
			cout << result_dfs[i] << " ";
	}
	for (int i = 0; i < result_bfs.size(); i++) {
		if (i == result_bfs.size() - 1)
			cout << result_bfs[i] << "\n";
		else
			cout << result_bfs[i] << " ";
	}

}