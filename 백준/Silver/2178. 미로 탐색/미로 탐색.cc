#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;


int n, m;
vector<vector<int>> graph;
vector<vector<bool>> visited;

vector<int> di = { -1,1,0,0 };
vector<int> dj = { 0,0,-1,1 };

int bfs(void) {
	int i = 0;
	int j = 0;
	visited[i][j] = true;
	queue<pair<pair<int, int>,int>> q;
	q.push(make_pair(make_pair(i, j),1)); //좌표 (i,j), distance 형태로 저장 

	//int result = 1;
	while (!q.empty()) {
		int tmpi = q.front().first.first;
		int tmpj = q.front().first.second;
		int distance = q.front().second;
		q.pop();
		//result++;

		if (tmpi == n - 1 && tmpj == m - 1) return distance;
		
		for (int k = 0; k < 4; k++) {
			int ni = tmpi + di[k];
			int nj = tmpj + dj[k];

			if ((ni < 0) || (ni >= n) || (nj < 0) || (nj >= m)) continue;

			if (graph[ni][nj] == 1 && visited[ni][nj] == false) {
				visited[ni][nj] = true;
				q.push(make_pair(make_pair(ni, nj),distance+1));
			}
		}
	}

}

int main(void)
{
	cin >> n >> m;
	graph.assign(n, vector<int>(m));
	visited.assign(n, vector<bool>(m, false));
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++) {
			graph[i][j] = int(s[j] - '0');
		}
	}
	
	int result = bfs();
	cout << result;
	return 0;
	
}