#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> graph;
vector<int> visited;
vector<int> result;
int cnt = 0;

void dfs(int i) {
	visited[i] = 1;
	cnt++;
	for (int j = 0; j < graph[i].size(); j++) {
		int next = graph[i][j];
		if (visited[next] == 1) continue;
		dfs(next);
	}
}

void bfs(int i) {
	queue<int> q;
	visited[i] = 1;
	cnt++;
	q.push(i);

	while (!q.empty()) {
		int cur = q.front(); q.pop();
		for (int j = 0; j < graph[cur].size(); j++) {
			int next = graph[cur][j];
			if (visited[next] == 1) continue;
			visited[next] = 1;
			q.push(next);
			cnt++;
		}
	}
	
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n, m; cin >> n >> m;
	graph.assign(n + 1, vector<int>());
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		graph[b].push_back(a);
	}

	result.assign(n + 1, 0);
	int max = -1;
	for (int i = 1; i <= n; i++) {
		visited.assign(n + 1, 0);
		cnt = 0;
		//dfs(i);
		bfs(i);
		result[i] = cnt;
		if (max < cnt) max = cnt;
	}

	for (int i = 1; i <= n; i++) {
		if (result[i] == max)
			cout << i << " ";
	}

}