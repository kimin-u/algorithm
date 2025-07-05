#include <iostream>
#include <vector>

using namespace std;

vector<int> dp;

int solve(int n) {
	if (n < 0) return 5001;
	if (n == 0) return 0;
	if (dp[n] == -1) {
		dp[n] = min(solve(n - 3), solve(n - 5)) + 1;
	}
	return dp[n];
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n; cin >> n;
	dp.assign(n + 1, -1);

	if (solve(n) >= 5001) cout << "-1";
	else cout << solve(n);
	return 0;
}