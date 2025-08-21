#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int t;
int w, h;
vector<vector<char>> graph;
vector<int> di = { -1,1,0,0 };
vector<int> dj = { 0,0,-1,1 };
queue<pair<int, int>> q;
queue<pair<int, int>> fire_q;
vector<vector<int>> fire_t;
vector<vector<int>> sg_t;

int bfs(int i, int j) {
	//불 먼저.
	while (!fire_q.empty()) {
		int ci = fire_q.front().first;
		int cj = fire_q.front().second;
		fire_q.pop();

		for (int k = 0; k < 4; k++) {
			int ni = ci + di[k];
			int nj = cj + dj[k];
			if (ni < 0 || ni >= h || nj < 0 || nj >= w) continue;
			if (graph[ni][nj] != '#' && fire_t[ni][nj] == 1e9) {
				fire_t[ni][nj] = fire_t[ci][cj] + 1;
				fire_q.push({ ni,nj });
			}
		}
	}

	q.push({ i,j });
	while (!q.empty()) {
		int ci = q.front().first;
		int cj = q.front().second;
		q.pop();
		if (ci == 0 || ci == h - 1 || cj == 0 || cj == w - 1) return sg_t[ci][cj] + 1;
		for (int k = 0; k < 4; k++) {
			int ni = ci + di[k];
			int nj = cj + dj[k];
			if (ni < 0 || ni >= h || nj < 0 || nj >= w) continue;
			if (graph[ni][nj] == '.' && sg_t[ni][nj] == -1) {
				sg_t[ni][nj] = sg_t[ci][cj] + 1;
				if (sg_t[ni][nj] < fire_t[ni][nj]) {
					q.push({ ni,nj });
				}
			}
		}
	}

	return 1e9;
	
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> t;
	while (t--) {
		while (!q.empty()) {
			q.pop();
		}
		while (!fire_q.empty()) {
			fire_q.pop();
		}
		cin >> w >> h;
		graph.assign(h, vector<char>(w));
		fire_t.assign(h, vector<int>(w, 1e9));
		sg_t.assign(h, vector<int>(w, -1));
		int ci, cj;
		for (int i = 0; i < h; i++) {
			string str; cin >> str;
			for (int j = 0; j < w; j++) {
				graph[i][j] = str[j];
				if (graph[i][j] == '@') {
					ci = i; cj = j;
				}
				else if (graph[i][j] == '*') {
					fire_q.push({ i,j });
					fire_t[i][j] = 0;
				}
			}
		}
		int cnt = 0;
		sg_t[ci][cj] = 0;
		//불 먼저, 다음 이동
		int answer = bfs(ci, cj);

		if (answer == 1e9) cout << "IMPOSSIBLE\n";
		else cout << answer << '\n';

	}
}