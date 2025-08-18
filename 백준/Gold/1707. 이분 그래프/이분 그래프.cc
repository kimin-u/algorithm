#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int v, e;
vector<vector<int>> graph;
vector<int> visited;

bool bfs(int start) {
	queue<int> q;
	q.push(start);
	visited[start] = 0;

	while (!q.empty()) {
		int cur = q.front(); q.pop();
		
		for (int i = 0; i < graph[cur].size(); i++) {
			int next = graph[cur][i];
			if (visited[next] == -1) {
				visited[next] = 1 - visited[cur];
				q.push(next);
			}
			else if (visited[next] == visited[cur]) return false;
			
		}
	}
	return true;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int k; cin >> k;
	while (k--) {
		cin >> v >> e;
		graph.assign(v + 1, vector<int>());
		visited.assign(v + 1, -1);
		for (int i = 0; i < e; i++) {
			int a, b; cin >> a >> b;
			graph[a].push_back(b);
			graph[b].push_back(a);
		} 

		bool ok = true;
		for (int i = 1; i <= v; i++) {
			if (visited[i] == -1) {
				if (!bfs(i)) {
					ok = false;
					break;
				}
			}
		}
		if (ok) cout << "YES\n";
		else cout << "NO\n";
	}

}