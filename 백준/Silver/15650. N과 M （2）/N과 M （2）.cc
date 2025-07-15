#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> visited;
vector<int> vec;


void dfs(int cnt) {
	if (cnt == m) {
		for (int i = 0; i < vec.size(); i++) {
			cout << vec[i];
			if (i != vec.size() - 1) cout << " ";
		}
		cout << "\n";
	}
	else {
		for (int i = 1; i <= n; i++) {
			if (visited[i] == 0 && vec[cnt- 1] < i) {
				visited[i] = 1;
				vec[cnt] = i;
				dfs(cnt + 1);
				visited[i] = 0;

			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	vec.assign(m, 0);
	visited.assign(n + 1, 0);

	dfs(0);
}