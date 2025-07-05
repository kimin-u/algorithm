#include <iostream>
#include <vector>

using namespace std;

vector<int> dp;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;

	while (t--) {
		int n; cin >> n;
		dp.assign(11, -1);
		dp[1] = 1; dp[2] = 2; dp[3] = 4;
		for (int i = 4; i < n + 1; i++) {
			dp[i] = dp[i - 3] + dp[i - 2] + dp[i - 1];
		}
		cout << dp[n] << "\n";
	}

}