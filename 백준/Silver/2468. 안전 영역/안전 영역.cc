#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<vector<int>> graph;

vector<int> di = { -1,1,0,0 };
vector<int> dj = { 0,0,-1,1 };

void bfs(int i, int j, vector<vector<int>>& visited, int k) {
	visited[i][j] = 1;
	queue<pair<int, int>> q;
	q.push({ i,j });

	while (!q.empty()) {
		int tmpi = q.front().first;
		int tmpj = q.front().second;
		q.pop();

		for (int d = 0; d < 4; d++) {
			int ni = tmpi + di[d];
			int nj = tmpj + dj[d];

			if ((ni < 0) || (ni >= n) || (nj < 0) || (nj >= n)) continue;

			if (graph[ni][nj] > k && visited[ni][nj] == 0) {
				visited[ni][nj] = 1;
				q.push({ ni,nj });
			}
		}
	}
}
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	graph.assign(n, vector<int>(n));

	int max_height = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> graph[i][j];
			if (graph[i][j] > max_height) {
				max_height = graph[i][j];
			}
		}
	}
	
	int max = 1;
	for (int k = 1; k < max_height; k++) {
		vector<vector<int>> visited(n, vector<int>(n, 0));
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (graph[i][j] > k && visited[i][j] ==0){
					bfs(i, j, visited, k);
					cnt++;
				}
			}
		}
		if (cnt == 0) break;
		if (max < cnt) max = cnt;
	}

	cout << max;
	return 0;

}