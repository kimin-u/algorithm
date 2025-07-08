#include <iostream>
#include <vector>

using namespace std;

vector<int> vec;
vector<vector<int>> dp;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n; cin >> n;
	vec.assign(n + 1, -1);
	dp.assign(n + 1, vector<int>(n + 1, -1));

	for (int i = 1; i <= n; i++)
		cin >> vec[i];

	for (int i = 1; i <= n; i++)
		dp[i][i] = 1;

	for (int i = 1; i <= n - 1; i++) {
		if (vec[i] == vec[i + 1])
			dp[i][i + 1] = 1;
	}

	for (int i = n - 1; i >= 1; i--) {
		for (int j = i + 1; j <= n; j++) {
			if (dp[i][j] != -1) continue;
			if (vec[i] == vec[j] && dp[i + 1][j - 1]) dp[i][j] = 1;
			else dp[i][j] = 0;
		}
	}
	int m; cin >> m;

	while (m--) {
		int s, e; cin >> s >> e;
		cout << dp[s][e] << "\n";
	}
	


}