#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int f, s, g, u, d;
int result = 0;
void bfs(vector<int>& visited, int s, int g ) {
	visited[s] = 1;
	queue<pair<int,int>> q;
	q.push({ s,0 });
	vector<int> di = { u,d };
	while (!q.empty()) {
		int tmps = q.front().first;
		int time = q.front().second;
		q.pop();

		if (tmps == g) {
			cout << time;
			return;
		}
		for (int k = 0; k < 2; k++) {
			int ns; 
			if (k == 0) ns = tmps + di[k];
			else ns = tmps - di[k];

			if (ns<1 || ns>f) continue;

			if (visited[ns] == 0) {
				visited[ns] = 1;
				q.push({ ns,time + 1 });
			}
		}

	}

	cout << "use the stairs";
}
int main(void) {
	cin >> f >> s >> g >> u >> d;

	vector<int> visited(f+1, 0);

	bfs(visited, s, g);

	return 0;
}