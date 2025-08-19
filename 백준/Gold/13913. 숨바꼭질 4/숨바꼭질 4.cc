#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;


int n, k;
vector<int> visited;
vector<int> route;
void bfs() {
	visited[n] = 0;
	queue<int> q;
	q.push(n);

	while (!q.empty()) {
		int cur = q.front(); q.pop();
		vector<int> next = { cur - 1, cur + 1, 2 * cur };
		for (auto n : next) {
			if (n < 0 || n>100000) continue;
			if (visited[n] >= visited[cur] + 1) {
				visited[n] = visited[cur] + 1;
				route[n] = cur;
				q.push(n);
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> k;
	visited.assign(100001, 1e9);
	route.assign(100001, -1);
	bfs();

	cout << visited[k] <<'\n';
	vector<int> answer;
	int cur = k;
	while (cur != -1) {
		answer.push_back(cur);
		cur = route[cur];
	}
	reverse(answer.begin(), answer.end());

	for (auto a: answer){
		cout << a << " ";
	}
}