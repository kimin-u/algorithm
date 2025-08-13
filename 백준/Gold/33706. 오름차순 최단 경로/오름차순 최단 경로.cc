#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
vector<vector<int>> graph;
vector<int> visited;

bool bfs(int k) {
	visited[k] = 1;
	queue<int> q;
	q.push(k);

	int cnt = 0;
	while (!q.empty()) {
		int c = q.front();
		q.pop();
		cnt++;
		for (int i = 0; i < graph[c].size(); i++) {
			int next = graph[c][i];
			if (visited[next] == 0) {
				visited[next] = 1;
				q.push(next);
			}
		}
	}
	return cnt == n;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	graph.assign(n, vector<int>());
	visited.assign(n, 0);
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		if (a<b)
			graph[a - 1].push_back(b - 1);
		else
			graph[b - 1].push_back(a - 1);
	}
	// 1~i 비용 < 1~j비용보다 작아야함 (i<j)
	// 1~i번째 까지의 거리가 오름차순임.
	if (bfs(0)) {
		cout << "YES\n";
	}
	else cout << "NO\n";
}