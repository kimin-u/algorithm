#include <iostream>
#include <vector>
#include <string>

using namespace std;

int n;
vector<vector<char>> graph;
vector<vector<int>> visited;
vector<int> di = { -1,1,0,0 };
vector<int> dj = { 0,0,-1,1 };

void dfs(int i, int j) {
	visited[i][j] = 1;
	char c = graph[i][j];

	for (int k = 0; k < 4; k++) {
		int ni = i + di[k];
		int nj = j + dj[k];

		if (ni < 0 || ni >= n || nj < 0 || nj >= n) continue;
		if (visited[ni][nj] == 0 && graph[ni][nj] == c) {
			dfs(ni, nj);
		}
	}
}

void dfs2(int i, int j) {
	visited[i][j] = 1;
	char c = graph[i][j];

	for (int k = 0; k < 4; k++) {
		int ni = i + di[k];
		int nj = j + dj[k];

		if (ni < 0 || ni >= n || nj < 0 || nj >= n) continue;

		if (visited[ni][nj] == 0){
			if (c == 'B'){
				if(graph[ni][nj] == c)
					dfs2(ni, nj);
			}
			else {
				if (graph[ni][nj] == 'R' || graph[ni][nj] == 'G')
					dfs2(ni, nj);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;

	graph.assign(n, vector<char>(n));

	for (int i = 0; i < n; i++) {
		string str; cin >> str;
		for (int j = 0; j < n; j++) {
			graph[i][j] = str[j];
		}
	}

	//적록색약X
	visited.assign(n, vector<int>(n, 0));
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visited[i][j] == 0) {
				dfs(i, j);
				cnt++;
			}
		}
	}
	cout << cnt << ' ';

	//적록색약.
	visited.assign(n, vector<int>(n, 0));
	cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visited[i][j] == 0) {
				dfs2(i, j);
				cnt++;
			}
		}
	}
	cout << cnt;
}