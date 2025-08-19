#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<vector<int>> graph;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	graph.assign(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> graph[i][j];
		}
	}
	vector<int> vec(m);
	for (int i = 0; i < m; i++) {
		cin >> vec[i];
	}
	
	for (int k = 0; k < n; k++) {
		for (int l = 0; l < n; l++) {
			for (int p = 0; p < n; p++) {
				if (graph[l][k] + graph[k][p] == 2) {
					graph[l][p] = 1;
				}
				graph[p][p] = 1;
			}
		}
	}
	for (int i = 0; i < m-1; i++) {
		if (graph[vec[i] - 1][vec[i + 1] - 1] == 1) continue;
		else {
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";


}