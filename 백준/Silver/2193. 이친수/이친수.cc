#include <iostream>
#include <vector>

using namespace std;

vector<long long> dp;

long long solve(int n) {
	if (dp[n] != -1) return dp[n];
	return dp[n] = solve(n - 1) + solve(n - 2);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n; cin >> n;
	dp.assign(91, -1);
	dp[1] = 1;
	dp[2] = 1;

	solve(n);
	cout << dp[n];
}