#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> dp;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n, k; cin >> n >> k;
	dp.assign(n + 1, vector<int>(k + 1, 0));

	for (int i = 1; i < n + 1; i++)
		dp[i][1] = 1;
	for (int j = 1; j < k + 1; j++)
		dp[1][j] = j;

	for (int j = 2; j < k + 1; j++) {
		for (int i = 2; i < n + 1; i++) {
			dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) % 1000000000;
		}
	}
	
	cout << dp[n][k] % 1000000000;
}