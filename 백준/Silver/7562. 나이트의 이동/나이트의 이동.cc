#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int l;
int t;
int ci, cj;
int ti, tj;
vector<vector<int>> dist;

vector<int> di = { -1,-2,-2,-1,1,2,2,1 };
vector<int> dj = { -2,-1,1,2,2,1,-1,-2 };

int bfs(int i, int j) {
	priority_queue < pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
	dist[i][j] = 0;
	pq.push({ 0,{i,j} });
	
	while (!pq.empty()) {
		int cost = pq.top().first;
		int ci = pq.top().second.first;
		int cj = pq.top().second.second;
		pq.pop();
		if (ci == ti && cj == tj) return cost;
		if (cost > dist[ci][cj]) continue;

		for (int k = 0; k < 8; k++) {
			int ni = ci + di[k];
			int nj = cj + dj[k];
			if (ni < 0 || ni >= l || nj < 0 || nj >= l) continue;

			if (dist[ni][nj] > dist[ci][cj] + 1) {
				dist[ni][nj] = dist[ci][cj] + 1;
				pq.push({ dist[ni][nj], {ni,nj} });
			}
		}
	}
	return 0;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int t; cin >> t;
	while (t--) {
		cin >> l;
		dist.assign(l, vector<int>(l, 1e9));
		cin >> ci >> cj;
		cin >> ti >> tj;

		//cout << bfs(ci, cj) << '\n';
		bfs(ci, cj);
		cout << dist[ti][tj] << '\n';
	
	}
}