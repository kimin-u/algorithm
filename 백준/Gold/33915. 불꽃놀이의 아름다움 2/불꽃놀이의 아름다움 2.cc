#include <iostream>
#include <vector>

using namespace std;

int n;
vector<vector<int>> graph;
vector<int> visited;
bool odd = true;
void dfs(int start, int from, int depth) {
	visited[start] = depth;

	for (int i = 0; i < graph[start].size(); i++) {
		if (graph[start][i] == from) continue;
		if (visited[graph[start][i]] == 0)
			dfs(graph[start][i], start, depth+1);
		else { // 모두 방문 
			int cycle_len = depth - visited[graph[start][i]] + 1;
			if (cycle_len % 2 == 0) odd = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;
	graph.assign(n+1, vector<int>());
	visited.assign(n + 1, 0);
	for (int i = 0; i < n; i++) {
		int a, b; cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	//cycle.
	// 사이클 길이 % 2 ?
	dfs(1, -1, 1);
	if (odd) cout << 3;
	else cout << 2;
	
}