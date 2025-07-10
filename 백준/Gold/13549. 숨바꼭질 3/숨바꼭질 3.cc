#include <iostream>
#include <vector>
#include <deque>

#define INTMAX 100001

using namespace std;

int n, k;
vector<int> visited;

void bfs() {
	deque<pair<int, int>> q;
	visited[n] = 1;
	q.push_front({ 0, n });

	while (!q.empty()) {
		int sec = q.front().first;
		int ci = q.front().second;
		q.pop_front();
		visited[ci] = 1;
		if (ci == k) {
			cout << sec;
			return;
		}

		if (ci * 2 >= 0 && ci * 2 < INTMAX && visited[ci*2] == 0) {
			q.push_front({ sec, ci * 2 });
		}
		if (ci + 1 >= 0 && ci + 1 < INTMAX && visited[ci + 1] == 0) {
			q.push_back({ sec + 1, ci + 1 });
		}
		if (ci - 1 >= 0 && ci - 1 < INTMAX && visited[ci - 1] == 0) {
			q.push_back({ sec + 1, ci - 1 });
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> k;
	visited.assign(INTMAX, 0);
	bfs();

}