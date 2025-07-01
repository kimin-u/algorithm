#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> graph;
vector<int> visited;
vector<int> result;

void dfs(int i) {
	visited[i] = 1;
	
	for (int next: graph[i]) {
		if (visited[next] == 1) continue;

		result[next] = i;
		dfs(next);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n; cin >> n;
	graph.resize(n+1);
	visited.assign(n + 1, 0);
	result.assign(n + 1, 0);

	for (int i = 0; i < n; i++) {
		int a, b; cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	dfs(1);

	for (int i = 2; i < n + 1; i++) {
		cout << result[i] << "\n";
	}

}