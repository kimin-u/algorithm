#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<vector<int>> graph;
vector<vector<int>> nxt;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	graph.assign(n, vector<int>(n, 1e9));
	nxt.assign(n, vector<int>(n, -1));
	for (int i = 0; i < m; i++) {
		int a, b, c; cin >> a >> b >> c;
		graph[a - 1][b - 1] = min(graph[a - 1][b - 1], c);
		nxt[a - 1][b - 1] = b-1;
	}
	for (int i = 0; i < n; i++) {
		graph[i][i] = 0;
		nxt[i][i] = i;
	}

	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (graph[i][j] > graph[i][k] + graph[k][j]) {
					graph[i][j] = graph[i][k] + graph[k][j];
					nxt[i][j] = nxt[i][k];
				}
			}
		}
	}


	//출력
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (graph[i][j] == 1e9) {
				cout << 0 ;
			}
			else cout << graph[i][j];
			if (j != n - 1) cout << " ";
		}
		cout << '\n';
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (graph[i][j] == 1e9 || i == j) cout << 0 << "\n";
			else {
				vector<int> tmp;
				int cur = i;
				tmp.push_back(cur);
				while (cur != j) {
					cur = nxt[cur][j];
					if (cur == -1) break;
					tmp.push_back(cur);
				}
				cout << tmp.size() << " ";
				for (int i = 0; i < tmp.size(); i++) {
					cout << tmp[i] + 1;
					if (i != tmp.size()-1)
						cout << " ";
				}
				cout << "\n";
			}
		}
	}
}