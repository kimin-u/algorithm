#include <iostream>
#include <vector>

using namespace std;

int n, m;
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
			vec[cnt] = i;
			dfs(cnt + 1);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	vec.assign(m, 0);
	
	dfs(0);
}