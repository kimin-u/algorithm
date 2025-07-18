#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<vector<int>> graph;
vector<vector<int>> dp;
vector<vector<int>> visited;
vector<int> di = { -1,1,0,0 };
vector<int> dj = { 0,0,-1,1 };

int dfs(int i, int j) {
	if (dp[i][j] != -1) return dp[i][j];

	dp[i][j] = 1;
	for (int k = 0; k < 4; k++) {
		int ni = i + di[k];
		int nj = j + dj[k];
		if (ni < 0 || ni >= n || nj < 0 || nj >= n) continue;
		if (graph[ni][nj] <= graph[i][j]) continue;
		
		dp[i][j] = max(dp[i][j], dfs(ni, nj) + 1);
		
	}

	return dp[i][j];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin >> n;
	graph.assign(n, vector<int>(n));
	dp.assign(n, vector<int>(n, -1));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> graph[i][j];
		}
	}

	int max = -1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int tmp = dfs(i, j);
			if (max < tmp) max = tmp;
		}
	}

	cout << max;

}