#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, l, r; 
vector<vector<int>> graph;
vector<vector<int>> visited;
vector<pair<int, int>> vec;
vector<int> di = { -1,1,0,0 };
vector<int> dj = { 0,0,-1,1 };

int sum = 0;
void bfs(int i, int j) {
	queue<pair<int,int>> q;
	q.push({i,j});
	visited[i][j] = 1;

	while (!q.empty()) {
		int ci = q.front().first;
		int cj = q.front().second;
		q.pop();

		for (int k = 0; k < 4; k++) {
			int ni = ci + di[k];
			int nj = cj + dj[k];
			if (ni < 0 || ni >= n || nj < 0 || nj >= n) continue;
		
			if (visited[ni][nj] == 0) {
				if ((abs(graph[ci][cj] - graph[ni][nj]) >= l) && (abs(graph[ci][cj] - graph[ni][nj]) <= r)) {
					vec.push_back({ ni,nj });
					q.push({ ni,nj });
					visited[ni][nj] = 1;
					sum += graph[ni][nj];
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> l >> r;

	graph.assign(n, vector<int>(n,0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> graph[i][j];
		}
	}

	int result = 0;
	int flag = true;
	while (flag) {
		flag = false;
		visited.assign(n, vector<int>(n, 0));
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++) {
				if (!visited[i][j]) {
					vec.clear();
					vec.push_back({ i,j });
					sum = graph[i][j];
					bfs(i, j);
				}

				if (vec.size() >= 2) {
					flag = true;
					for (int i = 0; i < vec.size(); i++) {
						graph[vec[i].first][vec[i].second] = sum / vec.size();
					}
				}
			}
		}
		if (flag) result++;
	}

	cout << result;
}