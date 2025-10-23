#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int r, c;
queue<pair<pair<int, int> , int> > q_pos;
queue<pair<int, int> > q_fire;


vector<int> di = { -1,1,0,0 };
vector<int> dj = { 0,0,-1,1 };

int bfs(vector<vector<char>>& graph) {
	while (!q_pos.empty()) {
		
		int len = q_fire.size();

		for (int t = 0; t < len; t++) {
			int tmpi_f = q_fire.front().first;
			int tmpj_f = q_fire.front().second;
			q_fire.pop();

			//if (q_fire.empty()) break;

			for (int k = 0; k < 4; k++) {
				int ni_f = tmpi_f + di[k];
				int nj_f = tmpj_f + dj[k];

				if ((ni_f < 0) || (ni_f >= r) || (nj_f < 0) || (nj_f >= c)) continue;

				if (graph[ni_f][nj_f] != '#') {
					q_fire.push({ ni_f, nj_f });
					graph[ni_f][nj_f] = '#';
				}
			}
		}
		int len2 = q_pos.size();
		for (int t = 0; t < len2; t++) {

			int tmpi_p = q_pos.front().first.first;
			int tmpj_p = q_pos.front().first.second;
			int time = q_pos.front().second;
			q_pos.pop();

			//if (q_pos.empty()) break;

			if ((tmpi_p == 0) || (tmpi_p == r - 1) || (tmpj_p == 0) || (tmpj_p == c - 1)) {
				return time;
			}

			for (int k = 0; k < 4; k++) {
				int ni_p = tmpi_p + di[k];
				int nj_p = tmpj_p + dj[k];

				if ((ni_p < 0) || (ni_p >= r) || (nj_p < 0) || (nj_p >= c)) continue;

				if (graph[ni_p][nj_p] != '#') {
					q_pos.push({ { ni_p, nj_p }, time + 1 });
					graph[ni_p][nj_p] = '#';
				}

			}
		}

		

	}
	
	return -1;

}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> r >> c;
	
	vector<vector<char>> graph(r, vector<char>(c));

	string s;
	for (int i = 0; i < r; i++) {
		cin >> s;
		for (int j = 0; j < c; j++) {
			graph[i][j] = s[j];
			if (graph[i][j] == 'F') {
				q_fire.push(make_pair(i, j));
				graph[i][j] = '#';
			}
			else if (graph[i][j] == 'J') {
				q_pos.push(make_pair(make_pair(i, j), 0));
				graph[i][j] = '#';
			}
		}
	}

	int result = bfs(graph);

	if (result != -1)
		cout << result + 1;
	else
		cout << "IMPOSSIBLE";

	return 0;


}