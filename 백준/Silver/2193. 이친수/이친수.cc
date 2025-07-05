#include <iostream>
#include <vector>

using namespace std;

vector<long long> dp;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n; cin >> n;
	dp.assign(91, -1);
	dp[1] = 1;
	dp[2] = 1;

	for (int i = 3; i < n+1; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	cout << dp[n];
}