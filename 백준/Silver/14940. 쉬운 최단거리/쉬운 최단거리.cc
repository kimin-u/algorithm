#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> graph;
vector<vector<int>> result;
vector<vector<int>> visited;

int n, m;
vector<int> di = { -1,1,0,0 };
vector<int> dj = { 0,0,-1,1 };

void bfs(int i, int j){
	visited[i][j] = 1;
	queue<pair<int, int>> q;
	q.push({ i,j });
	graph[i][j] = 0;
	result[i][j] = 0;


	while (!q.empty()) {
		int ci = q.front().first;
		int cj = q.front().second;
		q.pop();

		for (int k = 0; k < 4; k++) {
			int ni = ci + di[k];
			int nj = cj + dj[k];
			if (ni < 0 || ni >= n || nj < 0 || nj >= m) continue;

			if (visited[ni][nj] == 0 && graph[ni][nj] != 0) {
				visited[ni][nj] = 1; 
				result[ni][nj] = result[ci][cj] + 1;
				q.push({ ni,nj });
			}
		}

	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	graph.assign(n, vector<int>());
	visited.assign(n, vector<int>(m, 0));
	result.assign(n, vector<int>(m, 0));

	int start_i, start_j;
	for (int i = 0; i < n; i++) {
		vector<int> tmp;
		for (int j = 0; j < m; j++) {
			int num; cin >> num;
			if (num == 2) {
				start_i = i; start_j = j;
			}
			tmp.push_back(num);
		}
		graph[i] = tmp;
	}

	bfs(start_i, start_j);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (graph[i][j] == 0) {
				cout << 0;
			}
			else if (visited[i][j]) {
				cout << result[i][j];
			}
			else {
				cout << -1;
			}
			if (j != m - 1) cout << ' ';
		}
		cout << '\n';
	}
}