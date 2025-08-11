#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int k;
int cnt = 0;

vector<int> di = { -1,1,0,0 };
vector<int> dj = { 0,0,-1,1 };
vector<vector<int>> visited;
vector<vector<int>> graph;

bool check_visited() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (visited[i][j] == 0) return false;
		}
	}
	return true;
}

void dfs(int a, int b) {
	visited[a][b] = 1;
	if (check_visited()) {
		cnt++;
		visited[a][b] = 0;
		return ; 
	}

	for (int dir = 0; dir < 4; dir++) {
		int na = a + di[dir];
		int nb = b + dj[dir];
		if (na < 0 || na >= 3 || nb < 0 || nb >= 3) continue;
		if (visited[na][nb] == 0) {
			dfs(na, nb);
		}
	}
	visited[a][b] = 0;

}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> k;
	graph.assign(3, vector<int>(3, 0));
	visited.assign(3, vector<int>(3, 0));
	int value = 1;
	int a, b;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (value == k) {
				a = i; b = j;
			}
			graph[i][j] = value++;
		}
	}
	dfs(a, b);
	cout << cnt;
}