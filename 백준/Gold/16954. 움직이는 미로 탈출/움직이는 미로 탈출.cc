#include <iostream>
#include <vector>
#include <string>
#include <queue>


using namespace std;

vector<vector<char>> graph;

vector<int> di = { -1,1,0,0,-1,-1,1,1,0 };
vector<int> dj = { 0,0,-1,1,-1,1,-1,1,0 };

int is_wall(int x, int y, int t) {
	int nx = x - t;
	if (nx < 0) return 0;
	return (graph[nx][y] == '#');
}
int bfs(int i, int j) {
	queue<pair<pair<int, int>,int>> q;
	q.push({ { i,j },0 });

	while (!q.empty()) {
		int ci = q.front().first.first;
		int cj = q.front().first.second;
		int t = q.front().second;
		q.pop();
		if (ci == 0 && cj == 7) return 1;

		if (is_wall(ci, cj, t)) continue;


		for (int k = 0; k < 9; k++) {
			int ni = ci + di[k];
			int nj = cj + dj[k];
			int nt = min(t + 1, 8);
			if (ni < 0 || ni >= 8 || nj < 0 || nj >= 8) continue;
			if (is_wall(ni, nj, t)) continue;
			if (is_wall(ni, nj, nt)) continue;

			q.push({ {ni,nj},nt });

		}
	}

	return 0;

}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	graph.assign(8, vector<char>(8, '0'));

	for (int i = 0; i < 8; i++) {
		string s; cin >> s;
		for (int j = 0; j < 8; j++) {
			graph[i][j] = s[j];
		}
	}

	cout<<bfs(7, 0);
	
}