#include <iostream>
#include <vector>

using namespace std;

int v, e;
vector<vector<int>> dist;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> v >> e;
	dist.assign(v + 1, vector<int>(v + 1, 1e9));



	for (int i = 0; i < e; i++) {
		int a, b, c; cin >> a >> b >> c;
		dist[a][b] = min(dist[a][b], c);
	}

	for (int k = 1; k <= v; k++) {
		for (int i = 1; i <= v; i++) {
			for (int j = 1; j <= v; j++) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
	int minv = 1e9;
	for (int i = 1; i <= v; i++) {
		minv = min(minv, dist[i][i]);
	}

	if (minv == 1e9) cout << "-1\n";
	else cout << minv;

}