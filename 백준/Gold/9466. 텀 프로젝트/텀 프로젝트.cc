#include <iostream>
#include <vector>

using namespace std;

vector<int> graph;
vector<int> visited;
int cnt;

void dfs(int i) {
	visited[i] = 1;

	int next = graph[i];
	if (visited[next] == 0)
		dfs(next);
	else if (visited[next] == 1) {
		for (int j = next; j != i; j = graph[j])
			cnt++;
		cnt++;
	}

	visited[i] = 2;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int t; cin >> t;

	while (t--) {
		int n; cin >> n;
		graph.assign(n + 1, -1);
		visited.assign(n + 1, 0);
		cnt = 0;
		for (int i = 1; i < n + 1; i++)
			cin >> graph[i];

		for (int i = 1; i < n + 1; i++) {
			if (visited[i] == 0)
				dfs(i);
		}

		cout << n - cnt << "\n";
	}
}